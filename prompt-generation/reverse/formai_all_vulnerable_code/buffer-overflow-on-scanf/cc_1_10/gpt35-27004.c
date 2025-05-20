//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encode(char image[], char message[]) {
    int i, j, k = 0;
    char binary_message[9999];

    for(i=0; message[i]!='\0'; i++) {
        int ascii_value = message[i];
        //converting each character of message to binary
        for(j=7;j>=0;j--) {
            binary_message[k++] = ((ascii_value >> j) & 1) + '0';
        }
    }

    binary_message[k]='\0';

    int length = strlen(binary_message);

    FILE *image_file = fopen(image, "r+");
    if(!image_file) {
        printf("Error opening file!");
        exit(1);
    }

    int offset = 54;
    char bit;
    unsigned char byte;
    int bit_count = 0;

    //Encoding the binary message in image
    for(i=0; i<length; i++) {
        fseek(image_file, offset, SEEK_SET);
        fflush(image_file);
        fread(&byte, sizeof(byte), 1, image_file);

        if(bit_count < 8) {
            bit = binary_message[i];
            byte = (byte & 0xFE) | (bit - '0');
            fseek(image_file, -1, SEEK_CUR);
            fwrite(&byte, sizeof(byte), 1, image_file);
            bit_count++;
        }
        else {
            offset++;
            bit_count = 0;
            i--;
        }
        offset++;
    }

    printf("Steganography successful!");
    fclose(image_file);
}

void decode(char image[]) {
    int offset = 54;
    int i, j;
    char message[9999];
    char binary_message[9999];

    FILE *image_file = fopen(image, "r");
    if(!image_file) {
        printf("Error opening file!");
        exit(1);
    }

    unsigned char byte;
    int bit_count = 0;
    //Decoding the binary message from image
    for(i=0; i<8; i++) {
        fseek(image_file, offset, SEEK_SET);
        fflush(image_file);
        fread(&byte, sizeof(byte), 1, image_file);
        int bit = byte & 1;
        binary_message[bit_count++] = bit + '0';
        offset++;
    }
    binary_message[bit_count]='\0';

    int size = strlen(binary_message);
    int ascii_value = 0;
    int k = 0;
    //Converting the binary message to text
    for(i=0; i<size; i+=8, k++) {
        ascii_value = 0;
        for(j=0; j<8; j++){
            ascii_value = ascii_value << 1;
            ascii_value += (binary_message[i+j] - '0');
        }
        message[k] = ascii_value;
    }
    message[k]='\0';

    printf("The decoded message is: ");
    printf("%s",message);
    fclose(image_file);
}

int main() {
    int choice;
    char image[100], message[100];

    printf("Welcome to Image Steganography!\n\n");
    printf("Enter the name of the image file: ");
    scanf("%s", image);

    printf("Choose an option:\n");
    printf("1. Encode\n2. Decode\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the message to be hidden: ");
            scanf("%s", message);
            encode(image, message);
            break;
        case 2:
            decode(image);
            break;
        default:
            printf("Wrong Choice!");
    }

    return 0;
}