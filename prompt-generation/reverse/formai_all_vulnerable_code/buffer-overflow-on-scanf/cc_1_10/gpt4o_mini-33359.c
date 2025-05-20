//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 256
#define MAX_BINARY_SIZE 8

typedef struct {
    char character;
    char binary[MAX_BINARY_SIZE + 1];
} CharBinary;

char charToBinary(char c) {
    char binary[MAX_BINARY_SIZE + 1] = {0};
    for (int i = MAX_BINARY_SIZE - 1; i >= 0; i--) {
        binary[i] = (c % 2) + '0'; // Convert to char '0' or '1'
        c /= 2;
    }

    return strdup(binary); // Return a string representing the binary
}

void showIntro() {
    printf("********************************************\n");
    printf("  Welcome to the Cyberpunk Binary Converter  \n");
    printf("********************************************\n");
    printf("Prepare to convert your plain text into \n");
    printf("the digital whispers of the megacity.\n\n");
}

void readInput(char* input) {
    printf("Enter your text: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Strip newline
}

void convertToBinary(const char* text, CharBinary* bArray, int* size) {
    *size = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        CharBinary cb;
        cb.character = text[i];
        strcpy(cb.binary, charToBinary(text[i]));
        
        bArray[*size] = cb; // Store it in the array
        (*size)++;
    }
}

void displayBinary(CharBinary* bArray, int size) {
    printf("Binary Conversion:\n");
    for (int i = 0; i < size; i++) {
        printf(" %c -> %s\n", bArray[i].character, bArray[i].binary);
    }
}

void menu() {
    printf("\nOptions:\n");
    printf("1. Convert Text to Binary\n");
    printf("2. Exit\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    CharBinary bArray[MAX_INPUT_SIZE];
    int size = 0;
    int choice;

    showIntro();

    while (1) {
        menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        if (choice == 1) {
            readInput(input);
            convertToBinary(input, bArray, &size);
            displayBinary(bArray, size);
        } else if (choice == 2) {
            printf("Exiting... Don't get caught in the grid!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}