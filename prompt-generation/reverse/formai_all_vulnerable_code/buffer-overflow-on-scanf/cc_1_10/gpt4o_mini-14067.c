//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void compress(char *input, char *output) {
    int length = strlen(input);
    int count, j = 0;
    
    for (int i = 0; i < length; i++) {
        count = 1;

        // Count occurrences of the current character
        while (i + 1 < length && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Store the character and its count in the output
        output[j++] = input[i]; // Current character
        output[j++] = count + '0'; // Character count as a string
    }
    output[j] = '\0';
}

void decompress(char *input, char *output) {
    int length = strlen(input);
    int count, j = 0;

    for (int i = 0; i < length; i++) {
        char currentChar = input[i];
        i++;
        count = input[i] - '0'; // Read the number of repetitions

        // Append the character to the output 'count' times
        for (int k = 0; k < count; k++) {
            output[j++] = currentChar;
        }
    }
    output[j] = '\0';
}

void displayMenu() {
    printf("\n=============================");
    printf("\n  Custom RLE Compression Tool  ");
    printf("\n=============================");
    printf("\n1. Compress Text");
    printf("\n2. Decompress Text");
    printf("\n3. Exit");
    printf("\n=============================");
}

int main() {
    char input[MAX_LENGTH];
    char compressed[MAX_LENGTH];
    char decompressed[MAX_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter text to compress: ");
                scanf(" %[^\n]s", input); // Get string input with spaces
                compress(input, compressed);
                printf("Compressed Text: %s\n", compressed);
                break;
            case 2:
                printf("Enter text to decompress: ");
                scanf(" %[^\n]s", input); // Get string input with spaces
                decompress(input, decompressed);
                printf("Decompressed Text: %s\n", decompressed);
                break;
            case 3:
                printf("Exiting the program... Bye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}