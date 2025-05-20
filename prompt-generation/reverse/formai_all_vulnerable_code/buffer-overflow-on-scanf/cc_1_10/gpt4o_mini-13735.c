//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void replaceSpacesWithUnderscores(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            str[i] = '_';
        }
    }
}

void printMenu() {
    printf("\n--- String Manipulation Menu ---\n");
    printf("1. Convert to Upper Case\n");
    printf("2. Convert to Lower Case\n");
    printf("3. Reverse String\n");
    printf("4. Replace Spaces with Underscores\n");
    printf("5. Exit\n");
    printf("--------------------------------\n");
}

int main() {
    char inputString[MAX_LENGTH];
    int choice;
    
    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = 0; // Remove trailing newline

    while (1) {
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // To handle newline character after scanf

        switch (choice) {
            case 1:
                toUpperCase(inputString);
                printf("Upper Case: %s\n", inputString);
                break;
            case 2:
                toLowerCase(inputString);
                printf("Lower Case: %s\n", inputString);
                break;
            case 3:
                reverseString(inputString);
                printf("Reversed: %s\n", inputString);
                break;
            case 4:
                replaceSpacesWithUnderscores(inputString);
                printf("Spaces replaced: %s\n", inputString);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}