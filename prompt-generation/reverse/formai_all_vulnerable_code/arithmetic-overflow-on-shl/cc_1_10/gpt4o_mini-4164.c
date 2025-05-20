//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void decimalToBinary(int n, char* binary) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        binary[i] = (n & 1) ? '1' : '0';
        n >>= 1; // Shift right to process the next bit
    }
    binary[MAX_BITS] = '\0'; // Null-terminate the string
}

void displayBinary(char* binary) {
    printf("Binary representation: ");
    for (int i = 0; i < MAX_BITS; i++) {
        if (i > 0 && i % 4 == 0) {
            printf(" "); // Adding spacing for better readability
        }
        printf("%c", binary[i]);
    }
    printf("\n");
}

void getBinaryFromUser() {
    int number;
    char binary[MAX_BITS + 1]; // +1 for the null terminator

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Please enter a decimal number (0 to %d): ", (1 << MAX_BITS) - 1);
    
    // Validate user input
    while (1) {
        if (scanf("%d", &number) != 1 || number < 0 || number >= (1 << MAX_BITS)) {
            printf("Invalid input. Please enter a positive integer less than %d: ", (1 << MAX_BITS) - 1);
            while(getchar() != '\n'); // Clear the input buffer
        } else {
            break; // Valid input
        }
    }

    decimalToBinary(number, binary);
    displayBinary(binary);
}

void binaryOption() {
    char choice;
    do {
        getBinaryFromUser();
        printf("Would you like to convert another number? (y/n): ");
        while(getchar() != '\n'); // Clear input buffer before getting choice
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');
    
    printf("Thank you for using the Decimal to Binary Converter!\n");
}

void binaryQuiz() {
    printf("\n--- Binary Quiz ---\n");
    printf("What is the binary representation of the number 10?\n");
    printf("1) 1010\n2) 1110\n3) 1001\n4) 1100\n");
    
    int answer;
    printf("Your answer (1-4): ");
    while (scanf("%d", &answer) != 1 || answer < 1 || answer > 4) {
        printf("Invalid input. Please enter a number between 1 and 4: ");
        while(getchar() != '\n'); // Clear input buffer
    }

    if (answer == 1) {
        printf("Correct! 10 in binary is 1010.\n");
    } else {
        printf("Incorrect. The correct answer is 1) 1010.\n");
    }
}

int main() {
    int menuChoice;
    
    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1) Convert Decimal to Binary\n");
        printf("2) Take a Binary Quiz\n");
        printf("3) Exit\n");
        printf("Please select an option (1-3): ");
        
        while (scanf("%d", &menuChoice) != 1 || menuChoice < 1 || menuChoice > 3) {
            printf("Invalid input. Please select an option (1-3): ");
            while(getchar() != '\n'); // Clear input buffer
        }
        
        switch (menuChoice) {
            case 1:
                binaryOption();
                break;
            case 2:
                binaryQuiz();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
        }
    }
    
    return 0;
}