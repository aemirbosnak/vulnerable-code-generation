//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include<stdio.h>
#include<string.h>

// Function to convert binary to decimal
int bin2dec(char *str){
    int n = strlen(str);
    int dec = 0;
    for(int i=0; i<n; i++){
        dec += (str[i] - '0') * (1 << (n-i-1));
    }
    return dec;
}

// Function to convert decimal to binary
void dec2bin(int dec, char *bin) {
    for(int i=0; i<8; i++){
        bin[i] = '0' + ((dec >> (7-i)) & 1);
    }
    bin[8] = '\0';
}

// Function to embed watermark in image
void embed_watermark(char *img_path, char *watermark){
    FILE *input_file = fopen(img_path, "rb");
    FILE *output_file = fopen("watermarked_image.bmp", "wb");

    // Read BMP header
    unsigned char header[54];
    fread(header, 1, 54, input_file);

    // Write BMP header to output file
    fwrite(header, 1, 54, output_file);

    // Read image data
    unsigned char pixel[3];
    char binary[9];
    int index = 0;
    int watermark_len = strlen(watermark);
    fseek(input_file, 54, SEEK_SET);
    while(fread(pixel, 1, 3, input_file) == 3){
        dec2bin(pixel[0], binary);
        if(index < watermark_len){
            binary[7] = watermark[index];
            index++;
        }
        pixel[0] = bin2dec(binary);

        dec2bin(pixel[1], binary);
        if(index < watermark_len){
            binary[7] = watermark[index];
            index++;
        }
        pixel[1] = bin2dec(binary);

        dec2bin(pixel[2], binary);
        if(index < watermark_len){
            binary[7] = watermark[index];
            index++;
        }
        pixel[2] = bin2dec(binary);

        // Write watermarked pixel to output file
        fwrite(pixel, 1, 3, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

// Function to extract watermark from image
char* extract_watermark(char *img_path){
    FILE *input_file = fopen(img_path, "rb");

    // Read BMP header
    unsigned char header[54];
    fread(header, 1, 54, input_file);

    // Read image data
    unsigned char pixel[3];
    char binary[9];
    char *watermark = (char*) malloc(sizeof(char));
    int index = 0;
    fseek(input_file, 54, SEEK_SET);
    while(fread(pixel, 1, 3, input_file) == 3){
        dec2bin(pixel[0], binary);
        watermark = (char*) realloc(watermark, (index+1)*sizeof(char));
        watermark[index++] = binary[7];

        dec2bin(pixel[1], binary);
        watermark = (char*) realloc(watermark, (index+1)*sizeof(char));
        watermark[index++] = binary[7];

        dec2bin(pixel[2], binary);
        watermark = (char*) realloc(watermark, (index+1)*sizeof(char));
        watermark[index++] = binary[7];
    }

    watermark[index] = '\0';
    fclose(input_file);
    return watermark;
}

int main(){
    char img_path[100], watermark[100];
    printf("Enter image path: ");
    scanf("%s", img_path);
    printf("Enter watermark text: ");
    scanf("%s", watermark);

    embed_watermark(img_path, watermark);
    printf("Watermark embedded successfully!\n");

    char *extracted = extract_watermark("watermarked_image.bmp");
    printf("Extracted watermark: %s\n", extracted);

    return 0;
}