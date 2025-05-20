//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void reverseString(char *str);
void changeCase(char *str);
int countVowels(const char *str);
void toUppercase(char *str);
void toLowercase(char *str);
void displayMenu();

int main() {
    char inputString[100];
    int choice;
    
    printf("Welcome to the String Manipulation Program!\n");
    printf("Please enter a string (max 99 characters): ");
    fgets(inputString, sizeof(inputString), stdin);
    
    // Remove newline character from input if exists
    inputString[strcspn(inputString, "\n")] = 0;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to clear the newline character left in input buffer

        switch (choice) {
            case 1:
                printf("You entered: \"%s\"\n", inputString);
                break;
            case 2:
                reverseString(inputString);
                printf("Reversed string: \"%s\"\n", inputString);
                break;
            case 3:
                changeCase(inputString);
                printf("Changed case string: \"%s\"\n", inputString);
                break;
            case 4:
                printf("Vowel count: %d\n", countVowels(inputString));
                break;
            case 5:
                toUppercase(inputString);
                printf("Uppercase string: \"%s\"\n", inputString);
                break;
            case 6:
                toLowercase(inputString);
                printf("Lowercase string: \"%s\"\n", inputString);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 6.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Display original string\n");
    printf("2. Reverse string\n");
    printf("3. Change case (uppercase to lowercase and vice versa)\n");
    printf("4. Count vowels in the string\n");
    printf("5. Convert to uppercase\n");
    printf("6. Convert to lowercase\n");
    printf("0. Exit\n");
}

void reverseString(char *str) {
    int len = strlen(str);
    int i;
    char temp;

    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void changeCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int countVowels(const char *str) {
    int count = 0;
    char c;
    for (int i = 0; str[i]; i++) {
        c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

void toUppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}