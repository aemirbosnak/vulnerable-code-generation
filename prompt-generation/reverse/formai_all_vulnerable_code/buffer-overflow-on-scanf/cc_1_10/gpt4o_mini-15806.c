//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

void writeLoveLetter(FILE *file);
void readLoveLetter(FILE *file);

int main() {
    char filename[MAX_LENGTH];
    printf("Enter the name for your love letter file (with .txt extension): ");
    fgets(filename, MAX_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove newline character

    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Oh no! I couldn't open the love letter file...\n");
        return 1;
    }

    int choice;
    do {
        printf("\nWelcome to the Love Letter Manager!\n");
        printf("1. Write a love letter\n");
        printf("2. Read the love letters\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left in the input buffer

        switch (choice) {
            case 1:
                writeLoveLetter(file);
                break;
            case 2:
                readLoveLetter(file);
                break;
            case 3:
                printf("Leaving, but my heart will always be with you.\n");
                break;
            default:
                printf("Ah, my love, you've lost your way. Please choose 1, 2, or 3.\n");
        }
    } while (choice != 3);

    fclose(file);
    return 0;
}

void writeLoveLetter(FILE *file) {
    char letter[MAX_LENGTH];
    printf("Write your love letter (max %d characters):\n", MAX_LENGTH);
    fgets(letter, MAX_LENGTH, stdin);
    strncat(letter, "\n", MAX_LENGTH - strlen(letter) - 1);  // Add a newline

    fprintf(file, "%s", letter);
    printf("Your sweet words have been preserved forever in this letter!\n");
}

void readLoveLetter(FILE *file) {
    fseek(file, 0, SEEK_SET);  // Move the file pointer to the beginning
    char letter[MAX_LENGTH];

    printf("Here are the love letters that you have written:\n");
    while (fgets(letter, MAX_LENGTH, file) != NULL) {
        printf("%s", letter);
    }

    if (ftell(file) == 0) {
        printf("Oh, your heart is like a blank page, waiting to be filled...\n");
    }
}