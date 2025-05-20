//FormAI DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MESSAGE_LENGTH 100

int main(){
    FILE *original_img, *stego_img, *extracted_text;
    unsigned char original[512][512][3], stego[512][512][3], ch;
    char str[MESSAGE_LENGTH], ext_str[MESSAGE_LENGTH];
    int i, j, len, ext_len, width, height, bit, byte, mask = 128;

    //Read the original image
    original_img = fopen("original_image.bmp", "rb");
    if(original_img == NULL){
        printf("Unable to open file!");
        exit(1);
    }
    fread(original, sizeof(original), 1, original_img);
    fclose(original_img);

    //Read the secret message
    printf("Enter the message to be hidden: ");
    gets(str);
    len = strlen(str);

    //Encoding the secret message in the image pixels
    byte = 0;
    for(i=0; i<len; i++){
        for(j=0; j<8; j++){
            bit = ((int)str[i] & mask) >> 7; //Get the most significant bit of the current character
            stego[i][byte][0] = original[i][byte][0] & 0xFE | bit; //Change the LSB of the R component
            mask = mask >> 1;
            bit = ((int)str[i] & mask) >> 6; //Get the next most significant bit of the current character
            stego[i][byte][1] = original[i][byte][1] & 0xFE | bit; //Change the LSB of the G component
            mask = mask >> 1;
            bit = ((int)str[i] & mask) >> 5; //Get the next most significant bit of the current character
            stego[i][byte][2] = original[i][byte][2] & 0xFE | bit; //Change the LSB of the B component
            mask = 128;
            byte++;
        }
    }

    //Write the stego image
    stego_img = fopen("stego_image.bmp", "wb");
    if(stego_img == NULL){
        printf("Unable to create file!");
        exit(1);
    }
    fwrite(stego, sizeof(stego), 1, stego_img);
    fclose(stego_img);

    //Read the steganographic image
    stego_img = fopen("stego_image.bmp", "rb");
    if(stego_img == NULL){
        printf("Unable to open file!");
        exit(1);
    }
    fread(stego, sizeof(stego), 1, stego_img);
    fclose(stego_img);

    //Decoding the secret message from the stego image pixels
    byte = 0;
    for(i=0; i<len; i++){
        str[i] = 0;
        for(j=0; j<8; j++){
            ch = (stego[i][byte][0] & 0x01) << 7 | (stego[i][byte][1] & 0x01) << 6 | (stego[i][byte][2] & 0x01) << 5;
            str[i] = str[i] | ch;
            byte++;
        }
    }
    str[i] = '\0';
    printf("\nExtracted Message: %s\n", str);

    //Write the extracted message
    extracted_text = fopen("extracted_text.txt", "w");
    if(extracted_text == NULL){
        printf("Unable to create file!");
        exit(1);
    }
    fputs(str, extracted_text);
    fclose(extracted_text);

    return 0;
}