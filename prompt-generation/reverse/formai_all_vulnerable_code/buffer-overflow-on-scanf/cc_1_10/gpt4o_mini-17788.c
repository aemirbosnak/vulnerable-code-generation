//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void displayGratitude() {
    printf("Thank you for using our Binary Converter!\n");
    printf("We appreciate your interest in learning and growing!\n");
    printf("Here’s to the beauty of binary and the wonders of computing!\n\n");
}

void printBinary(int num) {
    if (num > 1) {
        printBinary(num / 2);
    }
    printf("%d", num % 2);
}

void convertToBinary(int num) {
    printf("The binary representation of %d is: ", num);
    if (num == 0) {
        printf("0");
    } else {
        printBinary(num);
    }
    printf("\n");
}

int getInput() {
    int num;
    printf("Please enter a non-negative integer to convert to binary: ");
    while (1) {
        if (scanf("%d", &num) != 1 || num < 0) {
            printf("Uh-oh! That's not a valid input. Please enter a non-negative integer: ");
            // Clear stdin buffer
            while (getchar() != '\n'); 
        } else {
            break;
        }
    }
    return num;
}

void displayMenu() {
    printf("\n-------- Binary Converter Menu --------\n");
    printf("1. Convert a number to binary\n");
    printf("2. Convert multiple numbers to binary\n");
    printf("3. Exit\n");
    printf("---------------------------------------\n");
}

void convertMultiple() {
    int count;
    printf("How many numbers would you like to convert? ");
    while (1) {
        if (scanf("%d", &count) != 1 || count <= 0) {
            printf("Please enter a positive integer: ");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    }

    int *numbers = malloc(count * sizeof(int));
    if (numbers == NULL) {
        printf("Thank you for your patience, but we've encountered a memory issue. Please try again later.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        numbers[i] = getInput();
    }

    printf("\nConverting your numbers to binary...\n");
    for (int i = 0; i < count; i++) {
        convertToBinary(numbers[i]);
    }

    free(numbers);
    printf("Thank you for using our multiple conversion feature!\n");
}

int main() {
    displayGratitude();
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        while (1) {
            if (scanf("%d", &choice) != 1) {
                printf("That's not a valid option. Please try again: ");
                while (getchar() != '\n'); 
            } else {
                break;
            }
        }

        switch (choice) {
            case 1:
                {
                    int num = getInput();
                    convertToBinary(num);
                }
                break;
            case 2:
                convertMultiple();
                break;
            case 3:
                printf("Thank you for using our Binary Converter! Have a fantastic day!\n");
                return 0;
            default:
                printf("Please select a valid option from the menu.\n");
        }
    }
    return 0;
}