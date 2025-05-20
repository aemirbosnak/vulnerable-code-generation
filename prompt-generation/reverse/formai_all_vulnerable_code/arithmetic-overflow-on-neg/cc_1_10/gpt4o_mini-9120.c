//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void printHex(int num);
void intToHex(int num);
void displayMenu();
void convertFileContent(const char *filename);
int isHexadecimal(const char *input);
void processUserInput();

#define MAX_INPUT 256

// Entry Point of the Program
int main() {
    processUserInput();
    return 0;
}

// Function to Display a Menu to the User
void displayMenu() {
    printf("\n--- Hexadecimal Converter ---\n");
    printf("1. Convert Integer to Hexadecimal\n");
    printf("2. Convert Hexadecimal String to Integer\n");
    printf("3. Convert File Contents to Hexadecimal\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

// Function to Process User Input
void processUserInput() {
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int number;
                printf("Enter an integer: ");
                scanf("%d", &number);
                intToHex(number);
                break;
            }
            case 2: {
                char hexInput[MAX_INPUT];
                printf("Enter a hexadecimal string: ");
                scanf("%s", hexInput);
                if (isHexadecimal(hexInput)) {
                    int decimal = (int)strtol(hexInput, NULL, 16);
                    printf("Decimal: %d\n", decimal);
                } else {
                    printf("Invalid hexadecimal input.\n");
                }
                break;
            }
            case 3: {
                char filename[MAX_INPUT];
                printf("Enter the filename: ");
                scanf("%s", filename);
                convertFileContent(filename);
                break;
            }
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
}

// Function to Convert Integer to Hexadecimal and Print
void intToHex(int num) {
    printf("Hexadecimal: ");
    printHex(num);
    printf("\n");
}

// Function to Print Hexadecimal Representation
void printHex(int num) {
    if (num < 0) {
        num = -num; // Handling negative numbers as well
    }
    if (num / 16 != 0) {
        printHex(num / 16);
    }
    printf("%X", num % 16);
}

// Function to Check if String is a Valid Hexadecimal
int isHexadecimal(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!((input[i] >= '0' && input[i] <= '9') ||
              (input[i] >= 'a' && input[i] <= 'f') ||
              (input[i] >= 'A' && input[i] <= 'F'))) {
            return 0; // Invalid character found
        }
    }
    return 1; // Valid hexadecimal string
}

// Function to Convert Contents of a File to Hexadecimal Representation
void convertFileContent(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file: %s\n", filename);
        return;
    }

    int byte;
    printf("Hexadecimal contents of the file %s:\n", filename);
    while ((byte = fgetc(file)) != EOF) {
        printf("%02X ", byte);
    }
    printf("\n");
    fclose(file);
}