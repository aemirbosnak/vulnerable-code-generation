//FormAI DATASET v1.0 Category: Image Steganography ; Style: enthusiastic
#include <stdio.h>

int main(){
    printf("\n\t\tWelcome to Image Steganography program!\n\n");
    char message[100];
    printf("Enter the message you want to hide in an image(max 100 characters): ");
    fgets(message, 100, stdin); // Reading user input message and storing it in message array

    FILE *fptr_src, *fptr_new; // declaring file pointers for source and new image
    char src_file[50], new_file[50]; 

    printf("\nEnter the source image file name: ");
    scanf("%s", src_file); // Reading source image file name
    fptr_src = fopen(src_file, "rb"); // Opening source image in binary read mode
 
    printf("\nEnter the new image file name: ");
    scanf("%s", new_file); // Reading new image file name
    fptr_new = fopen(new_file, "wb"); // Opening new image in binary write mode
 
    int byte; // Declaring int variable for storing byte of the image
    int i = 0; // Declaring and initializing int variable i with 0 for messages iteration
 
    while (i < sizeof(message)){ // Looping until message ends
        byte = fgetc(fptr_src); // Reading one byte of image
        byte = byte & 0xfe | ((message[i] >> 7) & 1); // Encoding 1st bit of character to the byte
        fputc(byte, fptr_new); // Writting the modified byte to new image file

        byte = fgetc(fptr_src); // Reading one byte of image
        byte = byte & 0xfe | ((message[i] >> 6) & 1); // Encoding 2nd bit of character to the byte
        fputc(byte, fptr_new); // Writting the modified byte to new image file

        byte = fgetc(fptr_src); // Reading one byte of image
        byte = byte & 0xfe | ((message[i] >> 5) & 1); // Encoding 3rd bit of character to the byte
        fputc(byte, fptr_new); // Writting the modified byte to new image file

        byte = fgetc(fptr_src); // Reading one byte of image
        byte = byte & 0xfe | ((message[i] >> 4) & 1); // Encoding 4th bit of character to the byte
        fputc(byte, fptr_new); // Writting the modified byte to new image file

        byte = fgetc(fptr_src); // Reading one byte of image
        byte = byte & 0xfe | ((message[i] >> 3) & 1); // Encoding 5th bit of character to the byte
        fputc(byte, fptr_new); // Writting the modified byte to new image file

        byte = fgetc(fptr_src); // Reading one byte of image
        byte = byte & 0xfe | ((message[i] >> 2) & 1); // Encoding 6th bit of character to the byte
        fputc(byte, fptr_new); // Writting the modified byte to new image file

        byte = fgetc(fptr_src); // Reading one byte of image
        byte = byte & 0xfe | ((message[i] >> 1) & 1); // Encoding 7th bit of character to the byte
        fputc(byte, fptr_new); // Writting the modified byte to new image file

        byte = fgetc(fptr_src); // Reading one byte of image
        byte = byte & 0xfe | (message[i] & 1); // Encoding 8th bit of character to the byte
        fputc(byte, fptr_new); // Writing the modified byte to new image file
        
        i++; // Moving to the next character
    }

    while((byte = fgetc(fptr_src)) != EOF){ // Looping until the end of image
        fputc(byte, fptr_new); // Writing the remaining bits to new image file
    }

    fclose(fptr_src); // Closing the source image file after encoding
    fclose(fptr_new); // Closing the new image file after encoding

    printf("\nMessage encoded successfully in %s image file!\n", new_file); // Success message
    return 0;
}