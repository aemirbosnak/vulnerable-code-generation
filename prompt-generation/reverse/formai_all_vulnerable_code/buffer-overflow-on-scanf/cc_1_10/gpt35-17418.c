//FormAI DATASET v1.0 Category: Image Steganography ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 10000
#define MAX_MSG_SIZE 1000

void encode(char *img_data, char *msg){
    int i, j, k = 0;
    for(i = 0; i < strlen(msg); i++){
        for(j = 0; j < 8; j++){
            img_data[k] &= 0xFE; // Clear the LSB of the pixel value
            img_data[k] |= ((msg[i] >> j) & 1); // Set LSB to the corresponding bit of the message
            k++;
        }
    }
}

void decode(char *img_data, char *msg, int msg_len){
    int i, j, k = 0;
    for(i = 0; i < msg_len; i++){
        msg[i] = 0;
        for(j = 0; j < 8; j++){
            msg[i] |= ((img_data[k] & 1) << j); // Extract the LSB from the pixel value
            k++;
        }
    }
    msg[msg_len] = '\0';
}

int main(){
    char img_data[MAX_IMAGE_SIZE];
    char msg[MAX_MSG_SIZE];
    char choice;
    int len;

    printf("\n   C Image Steganography Example\n");
    printf("========================================\n\n");
    printf("Select your choice:\n");
    printf("1. Encode\n");
    printf("2. Decode\n");
    printf(">> ");
    scanf("%c", &choice);

    if(choice == '1'){
        printf("\nEnter image data (max %d characters):\n>> ", MAX_IMAGE_SIZE);
        scanf(" %[^\n]s", img_data);
        printf("\nEnter message (max %d characters):\n>> ", MAX_MSG_SIZE);
        scanf(" %[^\n]s", msg);

        len = strlen(msg);
        if(len > (MAX_IMAGE_SIZE/8)){
            printf("\nError: Message is too long to encode.\n");
            return 0;
        }

        encode(img_data, msg);
        printf("\nEncoded message: %s\n", msg);
        printf("\nEncoded image data: %s\n", img_data);
    }
    else if(choice == '2'){
        printf("\nEnter image data (max %d characters):\n>> ", MAX_IMAGE_SIZE);
        scanf(" %[^\n]s", img_data);
        printf("\nEnter length of the message to be decoded:\n>> ");
        scanf("%d", &len);

        if(len > (MAX_IMAGE_SIZE/8)){
            printf("\nError: Message length is invalid.\n");
            return 0;
        }

        decode(img_data, msg, len);
        printf("\nDecoded message: %s\n", msg);
    }
    else{
        printf("\nInvalid choice!\n");
        return 0;
    }

    return 0;
}