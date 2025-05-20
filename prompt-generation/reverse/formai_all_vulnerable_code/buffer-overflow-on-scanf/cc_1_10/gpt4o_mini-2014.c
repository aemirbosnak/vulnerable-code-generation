//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 256

void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        // Swap characters
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp; 
    }
}

void toUpperCase(char* str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void toLowerCase(char* str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void replaceSpacesWithDashes(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            str[i] = '-';
        }
    }
}

void printMenu() {
    printf("\n******* C String Manipulation Menu *******\n");
    printf("1. Reverse a String\n");
    printf("2. Convert String to Uppercase\n");
    printf("3. Convert String to Lowercase\n");
    printf("4. Replace Spaces with Dashes\n");
    printf("5. Exit\n");
}

int main() {
    char str[MAX_STRING_SIZE];
    int choice;

    printf("Enter a string (max length %d): ", MAX_STRING_SIZE - 1);
    fgets(str, MAX_STRING_SIZE, stdin);

    // Remove newline character from the string if present
    str[strcspn(str, "\n")] = 0;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume the newline character after the integer input

        switch (choice) {
            case 1:
                reverseString(str);
                printf("Reversed String: %s\n", str);
                break;
            case 2:
                toUpperCase(str);
                printf("Uppercase String: %s\n", str);
                break;
            case 3:
                toLowerCase(str);
                printf("Lowercase String: %s\n", str);
                break;
            case 4:
                replaceSpacesWithDashes(str);
                printf("String with Dashes: %s\n", str);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}