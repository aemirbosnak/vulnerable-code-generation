//FormAI DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hideMessage(char image[], char message[]) {
    FILE *fp1, *fp2;
    char ch, *data;
    int fileSize, messageSize, i, j;

    // Open image file in read mode
    fp1 = fopen(image, "rb");

    // Find file size
    fseek(fp1, 0, SEEK_END);
    fileSize = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);

    // Allocate memory to hold the file
    data = (char *) malloc(fileSize);

    // Read the file into memory
    fread(data, fileSize, 1, fp1);

    // Open image file in write mode
    fp2 = fopen(image, "wb");

    // Write the first 54 bytes as is
    for(i = 0; i < 54; i++) {
        fputc(data[i], fp2);
    }

    // Calculate message size
    messageSize = strlen(message);

    // Hide message in image file
    for(i = 54, j = 0; j < messageSize; i += 3, j++) {
        if(i >= fileSize) {
            // If file size is exceeded, stop hiding the message
            printf("File size exceeded. Message not hidden.\n");
            break;
        }

        data[i] = message[j];
    }

    // Write the remaining data to image file
    for(i = 54; i < fileSize; i++) {
        fputc(data[i], fp2);
    }

    fclose(fp1);
    fclose(fp2);
    free(data);
}

void showMessage(char image[]) {
    FILE *fp;
    char ch;
    int i;

    // Open image file in read mode
    fp = fopen(image, "rb");

    // Read and discard the first 54 bytes
    for(i = 0; i < 54; i++) {
        ch = fgetc(fp);
    }

    // Print the hidden message
    printf("Hidden message in the image: ");
    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    printf("\n");

    fclose(fp);
}

int main() {
    char image[100], message[100];

    // Get image file name
    printf("Enter the name of the image file: ");
    scanf("%s", image);

    // Get message to hide
    printf("Enter the message to hide in the image: ");
    scanf(" %[^\n]s", message);

    // Hide the message in the image
    hideMessage(image, message);

    // Show the hidden message from the image
    showMessage(image);

    return 0;
}