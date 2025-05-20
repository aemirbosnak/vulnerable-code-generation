//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int stringLength(char *str) {
    return strlen(str);
}

int countCharacter(char *str, char c) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

void displayMenu() {
    printf("String Manipulation Menu:\n");
    printf("1. Reverse a string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Find string length\n");
    printf("4. Count occurrence of a character\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    char str[MAX_STRING_LENGTH];
    int choice;
    char character;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter a string to reverse: ");
                fgets(str, MAX_STRING_LENGTH, stdin);
                strtok(str, "\n"); // Remove the newline character
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;

            case 2:
                printf("Enter a string to convert to uppercase: ");
                fgets(str, MAX_STRING_LENGTH, stdin);
                strtok(str, "\n"); // Remove the newline character
                toUpperCase(str);
                printf("Uppercase string: %s\n", str);
                break;

            case 3:
                printf("Enter a string to find its length: ");
                fgets(str, MAX_STRING_LENGTH, stdin);
                strtok(str, "\n"); // Remove the newline character
                printf("Length of the string: %d\n", stringLength(str));
                break;

            case 4:
                printf("Enter a string: ");
                fgets(str, MAX_STRING_LENGTH, stdin);
                strtok(str, "\n"); // Remove the newline character
                printf("Enter the character to count: ");
                scanf(" %c", &character);
                printf("The character '%c' occurs %d times in the string.\n", character, countCharacter(str, character));
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}