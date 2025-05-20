//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILE_NAME_SIZE 100
#define MAX_WATERMARK_SIZE 50
#define MAX_FILE_SIZE 1000000 // 1MB

// Function to add watermark to file
void addWatermarkToFile(char *fileName, char *watermark) {
    FILE *fPtr1, *fPtr2;
    char ch;
    int count = 0;

    // Open input file in binary mode
    fPtr1 = fopen(fileName, "rb");
    if (fPtr1 == NULL) {
        printf("Unable to open input file: %s\n", fileName);
        return;
    }

    // Open output file in binary mode
    fPtr2 = fopen("temp.bin", "wb");
    if (fPtr2 == NULL) {
        printf("Unable to create temporary file\n");
        fclose(fPtr1);
        return;
    }

    // Write watermark to output file
    fwrite(watermark, sizeof(char), strlen(watermark), fPtr2);

    // Add watermark to input file
    while ((ch = fgetc(fPtr1)) != EOF) {
        fputc(ch, fPtr2);
        count++;
    }

    // Close input and output files
    fclose(fPtr1);
    fclose(fPtr2);

    // Rename output file as input file
    remove(fileName);
    rename("temp.bin", fileName);

    printf("Watermark added successfully!\n");
}

// Function to extract watermark from file
void extractWatermarkFromFile(char *fileName) {
    FILE *fPtr;
    char watermark[MAX_WATERMARK_SIZE];
    char ch;
    int count = 0;

    // Open file in binary mode
    fPtr = fopen(fileName, "rb");
    if (fPtr == NULL) {
        printf("Unable to open input file: %s\n", fileName);
        return;
    }

    // Read watermark from file
    while ((ch = fgetc(fPtr)) != EOF && count < MAX_WATERMARK_SIZE) {
        watermark[count++] = ch;
    }

    // Null terminate watermark string
    watermark[count] = '\0';

    // Close file
    fclose(fPtr);

    // Print watermark
    printf("Watermark: %s\n", watermark);
}

// Function to get user choice
int getUserChoice() {
    int choice;
    printf("\n1. Add Watermark to File\n");
    printf("2. Extract Watermark from File\n");
    printf("3. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    char fileName[MAX_FILE_NAME_SIZE];
    char watermark[MAX_WATERMARK_SIZE];
    int choice;

    printf("Enter input file name: ");
    scanf("%s", fileName);

    // Check file size
    FILE *fPtr = fopen(fileName, "rb");
    fseek(fPtr, 0L, SEEK_END);
    int fileSize = ftell(fPtr);
    fclose(fPtr);
    if (fileSize > MAX_FILE_SIZE) {
        printf("File size too big. Maximum file size allowed is %d bytes\n", MAX_FILE_SIZE);
        return 0;
    }

    while (1) {
        choice = getUserChoice();

        switch (choice) {
            case 1:
                printf("Enter watermark: ");
                scanf("%s", watermark);
                addWatermarkToFile(fileName, watermark);
                break;
            case 2:
                extractWatermarkFromFile(fileName);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}