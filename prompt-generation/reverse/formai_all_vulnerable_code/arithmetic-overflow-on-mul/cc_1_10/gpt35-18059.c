//FormAI DATASET v1.0 Category: Image Steganography ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IMAGE_SIZE 1000000

//Function to convert integer to binary string
char* int_to_bin(int num, int bits){
    int i, j, k;
    char *bin_str = (char*) malloc(bits*sizeof(char));
    for(i = (bits-1); i >= 0; i--){
        j = num >> i;
        k = j & 1;
        if(k) bin_str[bits-i-1] = '1';
        else bin_str[bits-i-1] = '0';
    }
    return bin_str;
}

//Function to convert binary string to integer    
int bin_to_int(char* bin_str, int bits){
    int i, num = 0;
    for(i = 0; i < bits; i++){
        num = num<<1;
        num = num | (bin_str[i] - '0');
    }
    return num;
}

//Function to hide message into image
void hide_message(char* image_path, char* message_path){
    //Open image file
    FILE *image_file = fopen(image_path, "rb");
    if(!image_file){
        printf("Error opening image file %s\n", image_path);
        exit(1);
    }

    //Read image data
    unsigned char* image_data = (unsigned char*) malloc(MAX_IMAGE_SIZE*sizeof(unsigned char));
    int image_size = fread(image_data, 1, MAX_IMAGE_SIZE, image_file);
    fclose(image_file);

    //Extract image header info
    int offset = *(int*)(image_data + 10);
    int width = *(int*)(image_data + 18);
    int height = *(int*)(image_data + 22);

    //Open message file
    FILE *message_file = fopen(message_path, "rb");
    if(!message_file){
        printf("Error opening message file %s\n", message_path);
        exit(1);
    }

    //Read message data
    fseek(message_file, 0, SEEK_END);
    int message_size = ftell(message_file);
    fseek(message_file, 0, SEEK_SET);
    char* message_data = (char*) malloc(message_size*sizeof(char));
    fread(message_data, 1, message_size, message_file);
    fclose(message_file);

    //Calculate message length and maximum message size that can be hidden in the image
    int message_len = strlen(message_data);
    int max_message_size = (width*height*3 - offset)/8;

    //Check if message size is less or equal to max message size
    if(message_len > max_message_size){
        printf("Message size is too large to be hidden in the image\n");
        exit(1);
    }

    //Convert message length to binary string
    char* message_len_bin = int_to_bin(message_len, 32);

    //Hide message length in image
    int i, j;
    for(i = offset; i < offset+32*3; i+=3){
        for(j = 0; j < 8; j++){
            if(message_len_bin[j+24] == '1') image_data[i+j] = (image_data[i+j] & 0xFE) | 0x01;
            else image_data[i+j] = (image_data[i+j] & 0xFE) | 0x00;
        }
        for(j = 8; j < 16; j++){
            if(message_len_bin[j+16] == '1') image_data[i+j] = (image_data[i+j] & 0xFE) | 0x01;
            else image_data[i+j] = (image_data[i+j] & 0xFE) | 0x00;
        }
        for(j = 16; j < 24; j++){
            if(message_len_bin[j+8] == '1') image_data[i+j] = (image_data[i+j] & 0xFE) | 0x01;
            else image_data[i+j] = (image_data[i+j] & 0xFE) | 0x00;
        }
    }

    //Convert message to binary string
    char* message_bin = (char*) malloc(message_len*8*sizeof(char));
    for(i = 0; i < message_len; i++){
        char* temp = int_to_bin((int)message_data[i], 8);
        strcat(message_bin, temp);
        free(temp);
    }

    //Hide message in image
    for(i = offset+32*3; i < offset+32*3+message_len*8*3; i+=3){
        for(j = 0; j < 8; j++){
            if(message_bin[((i-offset-32*3)/3)*8+j] == '1') image_data[i+j] = (image_data[i+j] & 0xFE) | 0x01;
            else image_data[i+j] = (image_data[i+j] & 0xFE) | 0x00;
        }
        for(j = 8; j < 16; j++){
            if(message_bin[((i-offset-32*3)/3)*8+j-8] == '1') image_data[i+j] = (image_data[i+j] & 0xFE) | 0x01;
            else image_data[i+j] = (image_data[i+j] & 0xFE) | 0x00;
        }
        for(j = 16; j < 24; j++){
            if(message_bin[((i-offset-32*3)/3)*8+j-16] == '1') image_data[i+j] = (image_data[i+j] & 0xFE) | 0x01;
            else image_data[i+j] = (image_data[i+j] & 0xFE) | 0x00;
        }
    }

    //Write stego image to file
    char* stego_image_path = (char*) malloc((strlen(image_path)+7)*sizeof(char));
    strncpy(stego_image_path, image_path, strlen(image_path)-4);
    strcat(stego_image_path, "_stego.bmp");
    FILE *stego_image_file = fopen(stego_image_path, "wb");
    fwrite(image_data, 1, image_size, stego_image_file);
    fclose(stego_image_file);
    printf("Stego image created at %s\n", stego_image_path);

    //Free memory
    free(image_data);
    free(message_data);
    free(message_len_bin);
    free(message_bin);
    free(stego_image_path);
}

//Function to extract message from image
void extract_message(char* stego_image_path, char* output_path){
    //Open image file
    FILE *stego_image_file = fopen(stego_image_path, "rb");
    if(!stego_image_file){
        printf("Error opening stego image file %s\n", stego_image_path);
        exit(1);
    }

    //Read image data
    unsigned char* image_data = (unsigned char*) malloc(MAX_IMAGE_SIZE*sizeof(unsigned char));
    int image_size = fread(image_data, 1, MAX_IMAGE_SIZE, stego_image_file);
    fclose(stego_image_file);

    //Extract image header info
    int offset = *(int*)(image_data + 10);
    int width = *(int*)(image_data + 18);
    int height = *(int*)(image_data + 22);

    //Extract message length from image
    char* message_len_bin = (char*) malloc(32*sizeof(char));
    int i, j, k = 0;
    for(i = offset; i < offset+32*3; i+=3){
        for(j = 0; j < 8; j++){
            if(image_data[i+j] & 0x01) message_len_bin[k++] = '1';
            else message_len_bin[k++] = '0';
        }
        for(j = 8; j < 16; j++){
            if(image_data[i+j] & 0x01) message_len_bin[k++] = '1';
            else message_len_bin[k++] = '0';
        }
        for(j = 16; j < 24; j++){
            if(image_data[i+j] & 0x01) message_len_bin[k++] = '1';
            else message_len_bin[k++] = '0';
        }
    }
    int message_len = bin_to_int(message_len_bin, 32);

    //Extract message from image
    char* message_bin = (char*) malloc(message_len*8*sizeof(char));
    k = 0;
    for(i = offset+32*3; i < offset+32*3+message_len*8*3; i+=3){
        for(j = 0; j < 8; j++){
            if(image_data[i+j] & 0x01) message_bin[k++] = '1';
            else message_bin[k++] = '0';
        }
        for(j = 8; j < 16; j++){
            if(image_data[i+j] & 0x01) message_bin[k++] = '1';
            else message_bin[k++] = '0';
        }
        for(j = 16; j < 24; j++){
            if(image_data[i+j] & 0x01) message_bin[k++] = '1';
            else message_bin[k++] = '0';
        }
    }
    char* message_data = (char*) malloc(message_len*sizeof(char));
    k = 0;
    for(i = 0; i < message_len; i++){
        message_data[i] = (char)bin_to_int(message_bin+k, 8);
        k += 8;
    }

    //Write extracted message to file
    FILE *output_file = fopen(output_path, "wb");
    fwrite(message_data, 1, message_len, output_file);
    fclose(output_file);
    printf("Extracted message written to file %s\n", output_path);

    //Free memory
    free(image_data);
    free(message_len_bin);
    free(message_bin);
    free(message_data);
}

int main(){
    char* image_path = "image.bmp";
    char* message_path = "input.txt";
    char* output_path = "output.txt";
    
    hide_message(image_path, message_path);
    extract_message("image_stego.bmp", output_path);

    return 0;
}