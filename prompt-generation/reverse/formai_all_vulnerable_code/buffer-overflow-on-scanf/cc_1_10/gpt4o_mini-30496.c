//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void compressRLE(char *input, char *output);
void decompressRLE(char *input, char *output);
void printMenu();
void handleUserChoice(int choice);

int main() {
    int choice;
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        handleUserChoice(choice);
        
        if (choice == 3) break; // Exit on choice 3
    }
    
    return 0;
}

// Function to handle user choices
void handleUserChoice(int choice) {
    char input[256], output[512];
    
    switch (choice) {
        case 1:
            printf("Enter the string to compress: ");
            scanf("%s", input);
            compressRLE(input, output);
            printf("Compressed output: %s\n", output);
            break;
        case 2:
            printf("Enter the string to decompress: ");
            scanf("%s", input);
            decompressRLE(input, output);
            printf("Decompressed output: %s\n", output);
            break;
        case 3:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please select again.\n");
    }
}

// Function to compress the input string using RLE
void compressRLE(char *input, char *output) {
    int count, i = 0;
    char temp[256] = "";
   
    while (input[i] != '\0') {
        count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }
        sprintf(temp + strlen(temp), "%c%d", input[i], count);
        i++;
    }

    strcpy(output, temp);
}

// Function to decompress the input string using RLE
void decompressRLE(char *input, char *output) {
    int i, j = 0, count;
    char temp[256];
    
    for (i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        i++;
        count = input[i] - '0';
        
        // Repeat character count times
        for (int k = 0; k < count; k++) {
            temp[j++] = ch;
        }
    }
    temp[j] = '\0';
    strcpy(output, temp);
}

// Function to print menu options to the user
void printMenu() {
    printf("\n--- Run-Length Encoding Compression Menu ---\n");
    printf("1. Compress a string\n");
    printf("2. Decompress a string\n");
    printf("3. Exit\n");
    printf("Please enter your choice: ");
}