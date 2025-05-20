//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

// Function Prototypes
void displayBitwiseOperations(int a, int b);
void writeToFile(const char *filename, int a, int b);
void readFromFile(const char *filename);
void clearBuffer();

// Main function
int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;
    char choice;
    
    printf("Welcome to the Bitwise Operations Program!\n");
    printf("You can perform bitwise operations on integers and write/read from a file.\n");

    // Input numbers
    while (count < MAX_NUMBERS) {
        printf("Enter an integer (or 'x' to stop): ");
        if (scanf("%d", &numbers[count]) != 1) {
            clearBuffer(); // Clear invalid input
            break; // Stop input on invalid entry
        }
        count++;
    }

    // Perform Operations
    do {
        printf("\nAvailable Operations:\n");
        printf("1: Display Bitwise Operations\n");
        printf("2: Write to File\n");
        printf("3: Read from File\n");
        printf("4: Exit\n");
        printf("Choose an operation (1-4): ");
        choice = getchar();
        clearBuffer(); // Clear newline character from buffer

        switch (choice) {
            case '1': {
                int a, b;
                printf("Enter two indices (0 to %d): ", count - 1);
                scanf("%d %d", &a, &b);
                if (a >= 0 && a < count && b >= 0 && b < count) {
                    displayBitwiseOperations(numbers[a], numbers[b]);
                } else {
                    printf("Invalid indices. Please try again.\n");
                }
                break;
            }
            case '2': {
                char filename[30];
                printf("Enter filename to write to: ");
                scanf("%s", filename);
                writeToFile(filename, numbers[0], numbers[1]); // Writing the first two numbers for simplicity
                break;
            }
            case '3': {
                char filename[30];
                printf("Enter filename to read from: ");
                scanf("%s", filename);
                readFromFile(filename);
                break;
            }
            case '4':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != '4');

    return 0;
}

// Function to display bitwise operations of two numbers
void displayBitwiseOperations(int a, int b) {
    printf("\nBitwise Operations for %d and %d:\n", a, b);
    printf("--------------------------------------------------\n");
    printf("A (Binary): %08X  B (Binary): %08X\n", a, b);
    printf("A & B     : %08X\n", a & b); // AND
    printf("A | B     : %08X\n", a | b); // OR
    printf("A ^ B     : %08X\n", a ^ b); // XOR
    printf("~A        : %08X\n", ~a);     // NOT
    printf("A << 1    : %08X\n", a << 1); // Left Shift
    printf("A >> 1    : %08X\n", a >> 1); // Right Shift
    printf("--------------------------------------------------\n");
}

// Function to write data to a file
void writeToFile(const char *filename, int a, int b) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "Numbers: %d, %d\n", a, b);
    fclose(file);
    printf("Data written to %s successfully.\n", filename);
}

// Function to read data from a file
void readFromFile(const char *filename) {
    char buffer[100];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    printf("\nContents of %s:\n", filename);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

// Function to clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}