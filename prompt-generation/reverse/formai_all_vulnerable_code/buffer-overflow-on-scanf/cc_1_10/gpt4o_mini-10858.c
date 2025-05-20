//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

// Function prototypes
void toUpperCase(char *str);
void reverseString(char *str);
void removeVowels(char *str);
void duplicateCharacters(char *str);
void countCharacterOccurrences(char *str);
void printMenu();

// Main function
int main() {
    char str[MAX_STRING_LENGTH];
    int choice;

    printf("Welcome to the Curious String Manipulation Program!\n");
    printf("Please enter a string (max %d characters): ", MAX_STRING_LENGTH - 1);
    fgets(str, MAX_STRING_LENGTH, stdin);

    // Remove newline character from the end if present
    str[strcspn(str, "\n")] = 0;

    do {
        printMenu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the number input

        switch(choice) {
            case 1:
                printf("Original string: %s\n", str);
                toUpperCase(str);
                printf("Uppercase string: %s\n", str);
                break;
            case 2:
                printf("Original string: %s\n", str);
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;
            case 3:
                printf("Original string: %s\n", str);
                removeVowels(str);
                printf("String without vowels: %s\n", str);
                break;
            case 4:
                printf("Original string: %s\n", str);
                duplicateCharacters(str);
                printf("String with duplicated characters: %s\n", str);
                break;
            case 5:
                countCharacterOccurrences(str);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to reverse a string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to remove vowels from a string
void removeVowels(char *str) {
    char temp[MAX_STRING_LENGTH];
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
              str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
              str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
              str[i] == 'U')) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

// Function to duplicate characters in a string
void duplicateCharacters(char *str) {
    char temp[MAX_STRING_LENGTH * 2];
    int j = 0;
    for (int i = 0; str[i]; i++) {
        temp[j++] = str[i];
        temp[j++] = str[i]; // Duplicate the character
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

// Function to count the occurrences of each character in a string
void countCharacterOccurrences(char *str) {
    int count[256] = {0}; // To store count of characters
    for (int i = 0; str[i]; i++) {
        count[(unsigned char)str[i]]++;
    }

    printf("Character occurrences:\n");
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("'%c' : %d times\n", i, count[i]);
        }
    }
}

// Function to print the menu
void printMenu() {
    printf("\nSelect the operation you want to perform on the string:\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Reverse the String\n");
    printf("3. Remove Vowels\n");
    printf("4. Duplicate Characters\n");
    printf("5. Count Character Occurrences\n");
    printf("6. Exit\n");
}