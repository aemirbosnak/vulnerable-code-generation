//FormAI DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function to read the byte value of a file */
unsigned char* readBytes(FILE* file, int* size) {
    unsigned char* buffer = NULL;
    int readSize = 0;

    if(file) {
        /* Seek to the end of the file for getting the size of the file */
        fseek(file, 0, SEEK_END);
        /* Reset the file pointer to the beginning of the file */
        rewind(file);
        /* Allocate the buffer with the size of the file */
        buffer = malloc(*size = ftell(file));
        if(buffer) {
            /* Read the file and store the content in the buffer variable */
            readSize = fread(buffer, sizeof(unsigned char), *size, file);
            if(readSize != *size) {
                /* Error handling in case of read failure */
                free(buffer), buffer = NULL;
            }
        }
    }

    return buffer;
}

/* Function to hide a message into the image byte stream */
void hideMessage(unsigned char* bytes, int size, char* message) {
    int lenMessage, i, j = 0;
    unsigned char lsb;

    /* Get the length of the message */
    lenMessage = strlen(message);
    /* Append the length of the message in the last 2 bytes of the image byte stream */
    bytes[size - 2] = (lenMessage & 0xff00) >> 8;
    bytes[size - 1] = (lenMessage & 0x00ff);
    /* Hide the message bit by bit */
    for(i = 0; i < lenMessage; ++i) {
        /* Loop through each bit */
        for(j = 0; j < 8; ++j) {
            /* Get the least significant bit of the message character */
            lsb = (message[i] & (1 << j)) >> j;
            /* Set the least significant bit of the corresponding byte in the image byte stream */
            bytes[i * 8 + j] = (bytes[i * 8 + j] & 0xfe) | lsb;
        }
    }
}

/* Function to retrieve the hidden message from the image byte stream */
char* retrieveMessage(unsigned char* bytes, int size) {
    int lenMessage, i, j;
    unsigned char lsb;
    char* buffer;

    /* Get the length of the message from the last 2 bytes of the image byte stream */
    lenMessage = (bytes[size - 2] << 8) | bytes[size - 1];
    /* Allocate the buffer with the size of the message plus 1 (for the null character) */
    buffer = malloc(lenMessage + 1);
    /* Retrieve the message bit by bit */
    for(i = 0; i < lenMessage; ++i) {
        buffer[i] = 0;
        /* Loop through each bit */
        for(j = 0; j < 8; ++j) {
            /* Get the least significant bit of the corresponding byte in the image byte stream */
            lsb = bytes[i * 8 + j] & 0x01;
            /* Set the bit in the message character */
            buffer[i] |= lsb << j;
        }
    }
    buffer[lenMessage] = '\0';

    return buffer;
}

int main() {
    FILE* imageFile;
    unsigned char* bytes;
    int sizeImage, i;
    char message[1024];

    /* Open the image file with read binary mode */
    imageFile = fopen("image.bmp", "rb");
    if(!imageFile) {
        /* Error handling in case of file not found */
        printf("File not found!\n");
        return -1;
    }

    /* Read the byte value of the image file */
    bytes = readBytes(imageFile, &sizeImage);
    if(!bytes) {
        /* Error handling in case of read failure */
        printf("Read failed!\n");
        return -1;
    }

    /* Get the message from the user */
    printf("Enter the message to be hidden:\n");
    fgets(message, 1024, stdin);
    /* Remove the newline character at the end of the message */
    message[strlen(message) - 1] = '\0';

    /* Hide the message into the image byte stream */
    hideMessage(bytes, sizeImage, message);

    /* Write the modified byte stream back into the image file */
    fclose(imageFile);
    imageFile = fopen("image_r.bmp", "wb");
    fwrite(bytes, sizeof(unsigned char), sizeImage, imageFile);

    /* Retrieve the message from the modified byte stream */
    printf("Message retrieved from the image: %s\n", retrieveMessage(bytes, sizeImage));

    /* Free the allocated memory and close the file */
    free(bytes);
    fclose(imageFile);

    return 0;
}