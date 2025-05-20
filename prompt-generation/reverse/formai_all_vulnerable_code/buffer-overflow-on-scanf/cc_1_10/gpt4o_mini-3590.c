//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define FILE_NAME "surprise_data.txt"

void createFile() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not create file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Welcome to the Surprise File!\n");
    fprintf(file, "Let's have some fun with file operations in C!\n");

    fclose(file);
    printf("File '%s' created with surprise messages!\n", FILE_NAME);
}

void readFile() {
    char line[MAX_LENGTH];
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for reading.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nReading the contents of the file...\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void appendToFile() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for appending.\n");
        exit(EXIT_FAILURE);
    }

    char additionalText[MAX_LENGTH];
    printf("\nWhat surprise message would you like to add? ");
    fgets(additionalText, sizeof(additionalText), stdin);
    
    // Remove the newline character if exists
    additionalText[strcspn(additionalText, "\n")] = 0;

    fprintf(file, "%s\n", additionalText);
    fclose(file);
    printf("Your surprise message was added to the file!\n");
}

void displayFileMetadata() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file to retrieve metadata.\n");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    printf("The size of the file '%s' is: %ld bytes\n", FILE_NAME, fileSize);
    
    fclose(file);
}

void surpriseBonusFeature() {
    printf("\nSurprise! Let's create a copy of your file called 'copy_of_surprise_data.txt'.\n");

    FILE *srcFile = fopen(FILE_NAME, "r");
    if (srcFile == NULL) {
        fprintf(stderr, "Could not open source file for copying.\n");
        exit(EXIT_FAILURE);
    }

    FILE *destFile = fopen("copy_of_surprise_data.txt", "w");
    if (destFile == NULL) {
        fprintf(stderr, "Could not create destination file.\n");
        fclose(srcFile);
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
    printf("Surprise! The file has been copied successfully!\n");
}

int main() {
    int choice;

    printf("Welcome to the Surprise File Handler!\n");
    printf("1. Create a Surprise File\n");
    printf("2. Read the Surprise File\n");
    printf("3. Append to the Surprise File\n");
    printf("4. Display File Metadata\n");
    printf("5. Create a Copy of the File\n");
    printf("6. Exit\n");

    do {
        printf("\nChoose an option (1-6): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after choice input

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                displayFileMetadata();
                break;
            case 5:
                surpriseBonusFeature();
                break;
            case 6:
                printf("Thank you for using the Surprise File Handler! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}