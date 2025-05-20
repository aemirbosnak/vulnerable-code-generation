//FormAI DATASET v1.0 Category: Image Steganography ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100000

int main(){
    FILE *image, *hidden_msg, *stego_image;
    char image_name[MAX_SIZE], hidden_msg_name[MAX_SIZE], stego_image_name[MAX_SIZE], buffer;

    // Input image
    printf("Enter the name of the image file: ");
    scanf("%s", image_name);

    // Open image file
    image = fopen(image_name, "rb");
    if(image == NULL){
        printf("Unable to open image file!\n");
        exit(1);
    }

    // Input hidden message
    printf("Enter the name of the message file: ");
    scanf("%s", hidden_msg_name);

    // Open message file
    hidden_msg = fopen(hidden_msg_name, "r");
    if(hidden_msg == NULL){
        printf("Unable to open message file!\n");
        exit(1);
    }

    // Input name for stego image
    printf("Enter the name for the stego image file: ");
    scanf("%s", stego_image_name);

    // Open stego image file
    stego_image = fopen(stego_image_name, "wb");
    if(stego_image == NULL){
        printf("Unable to create stego image file!\n");
        exit(1);
    }

    // Copy image header to stego image
    for(int i=0; i<54; i++){
        buffer = getc(image);
        putc(buffer, stego_image);
    }

    char msg[MAX_SIZE];
    fgets(msg, MAX_SIZE, hidden_msg);

    // Calculate length of message
    int msg_len = strlen(msg);

    // Convert msg length to binary and write to stego image header
    char bits[8];
    int i, j;
    for(i=0, j=7; i<8; i++, j--){
        bits[j] = msg_len % 2;
        msg_len = msg_len / 2;
    }

    fseek(stego_image, 32, SEEK_SET);
    for(int i=0; i<8; i++){
        buffer = getc(stego_image);
        buffer = buffer & 0b11111110;
        buffer = buffer | bits[i];
        fseek(stego_image, -1, SEEK_CUR);
        putc(buffer, stego_image);
    }

    // Convert message to binary and write to stego image
    int bit_pos = 0;
    while(fgets(msg, MAX_SIZE, hidden_msg)){
        int msg_len = strlen(msg);
        for(i=0; i<msg_len; i++){
            char c = msg[i];
            for(j=7; j>=0; j--){
                buffer = getc(image);
                if(feof(image)){
                    printf("Image file too small!\n");
                    exit(1);
                }
                char bit = (c >> j) & 0b00000001;
                buffer = buffer & 0b11111110;
                buffer = buffer | bit;
                putc(buffer, stego_image);
                bit_pos++;
            }
        }
    }
 
    // Copy remaining image data to stego image
    while(!feof(image)){
        buffer = getc(image);
        putc(buffer, stego_image);
    }

    printf("Steganography completed successfully!\n");

    fclose(image);
    fclose(hidden_msg);
    fclose(stego_image);

    return 0;
}