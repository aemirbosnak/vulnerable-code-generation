//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Function prototypes
void displayMenu();
void shiftString(char *str, int shiftAmount);
void reverseString(char *str);
void capitalizeString(char *str);
void lowercaseString(char *str);
void swapFirstAndLast(char *str);
void transformString(char *str, int transformationChoice);

int main() {
    char input[MAX_SIZE];
    int transformationChoice;
    char continueChoice;

    printf("Welcome to the Shape Shifting String Manipulator!\n");

    while (1) {
        printf("Please enter a string (max 255 characters): ");
        fgets(input, MAX_SIZE, stdin);

        // Remove newline character if exists
        input[strcspn(input, "\n")] = 0;

        displayMenu();
        printf("Choose a transformation option (1-6): ");
        scanf("%d", &transformationChoice);
        getchar(); // consume the newline character after integer input

        transformString(input, transformationChoice);
        
        printf("\nThe transformed string is: %s\n", input);
        
        printf("Do you want to transform another string? (y/n): ");
        scanf("%c", &continueChoice);
        getchar(); // consume the newline character

        if (continueChoice != 'y' && continueChoice != 'Y') {
            break;
        }
    }
    
    printf("Thank you for using the Shape Shifting String Manipulator. Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\nTransformation Options:\n");
    printf("1. Shift String\n");
    printf("2. Reverse String\n");
    printf("3. Capitalize String\n");
    printf("4. Lowercase String\n");
    printf("5. Swap First and Last Characters\n");
    printf("6. Shift and Reverse String (combination)\n");
}

void shiftString(char *str, int shiftAmount) {
    int length = strlen(str);
    char *temp = malloc(length + 1);
    
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    for (int i = 0; i < length; i++) {
        int newIndex = (i + shiftAmount) % length;
        temp[newIndex] = str[i];
    }
    
    // Handle potential underflow
    for (int i = 0; i < length; i++) {
        str[i] = temp[i];
    }
    
    free(temp);
}

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void capitalizeString(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32; // ASCII difference between lower and upper
        }
    }
}

void lowercaseString(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32; // ASCII difference between upper and lower
        }
    }
}

void swapFirstAndLast(char *str) {
    int length = strlen(str);
    if (length > 1) {
        char temp = str[0];
        str[0] = str[length - 1];
        str[length - 1] = temp;
    }
}

void transformString(char *str, int transformationChoice) {
    int shiftAmount;

    switch (transformationChoice) {
        case 1:
            printf("Enter shift amount: ");
            scanf("%d", &shiftAmount);
            shiftString(str, shiftAmount);
            break;
        case 2:
            reverseString(str);
            break;
        case 3:
            capitalizeString(str);
            break;
        case 4:
            lowercaseString(str);
            break;
        case 5:
            swapFirstAndLast(str);
            break;
        case 6:
            printf("Enter shift amount: ");
            scanf("%d", &shiftAmount);
            shiftString(str, shiftAmount);
            reverseString(str);
            break;
        default:
            printf("Invalid option! Please select a valid transformation.\n");
            break;
    }
}