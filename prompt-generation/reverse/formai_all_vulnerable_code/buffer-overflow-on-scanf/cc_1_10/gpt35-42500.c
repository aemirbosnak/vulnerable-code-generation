//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int watermark[50];
    int pixels[500], pixel_count, i, ch;
    FILE *image, *stego_image, *secret_file, *extracted_file;
    char image_path[100], stego_image_path[100], secret_file_path[100], extracted_file_path[100];
    char message[500], extracted_message[500];
    int message_len, extracted_len;

    // Enter image path
    printf("Enter the path of the image: ");
    scanf("%s", image_path);
    image = fopen(image_path, "rb"); // Opening image

    // Enter secret file path
    printf("Enter the path of the secret file to be hidden: ");
    scanf("%s", secret_file_path);
    secret_file = fopen(secret_file_path, "rb"); // Opening secret file

    // Enter stego image path
    printf("Enter the path of the stego image: ");
    scanf("%s", stego_image_path);
    stego_image = fopen(stego_image_path, "wb"); // Creating stego image

    // Reading secret file as message
    fseek(secret_file, 0, SEEK_END);
    message_len = ftell(secret_file);
    fseek(secret_file, 0, SEEK_SET);
    fread(message, sizeof(char), message_len, secret_file);
    printf("Secret message to be hidden: %s\n", message);

    // Getting pixel data from image
    pixel_count = 0;
    while((ch = fgetc(image)) != EOF){
        pixels[pixel_count] = ch;
        pixel_count++;
    }

    // Encoding secret message into pixel data
    watermark[0] = message_len; // First 4 pixels represent the length of the message
    for(i=0; i<message_len; i++){
        watermark[i+1] = message[i];
    }
    for(i=0; i<pixel_count; i++){
        if(i<message_len+4){
            pixels[i] = pixels[i] & 0xFE; // Clear LSB of pixel data
            pixels[i] = pixels[i] | ((watermark[i/4] >> ((i%4)*2)) & 0x03); // Set 2 LSB of pixel data as watermark data
        }
        fputc(pixels[i], stego_image);
    }
    fclose(image);
    fclose(secret_file);
    fclose(stego_image);

    // Extraction process
    printf("Enter the path of the stego image for extraction: ");
    scanf("%s", stego_image_path);
    printf("Enter the path to save the extracted file: ");
    scanf("%s", extracted_file_path);
    stego_image = fopen(stego_image_path, "rb"); // Opening stego image
    extracted_file = fopen(extracted_file_path, "wb"); // Creating extracted file

    // Getting pixel data from stego image
    watermark[0] = 0;
    for(i=0; i<pixel_count; i++){
        pixels[i] = fgetc(stego_image);
        if(i<4){
            watermark[0] = (watermark[0] << 8) | pixels[i]; // First 4 pixels represent length of extracted message
        }
        else if(i<4+watermark[0]*4){ 
            watermark[(i-3)/4] = (watermark[(i-3)/4] << 2) | (pixels[i] & 0x03); // Get 2 LSB of pixel data as watermark data
        }
    }
    extracted_len = watermark[0];
    for(i=0; i<extracted_len; i++){ // Extracting message from watermark array
        extracted_message[i] = (char)(watermark[i+1]);
    }
    printf("Extracted message: %s\n", extracted_message);
    fwrite(extracted_message, sizeof(char), extracted_len, extracted_file);

    fclose(stego_image);
    fclose(extracted_file);

    return 0;
}