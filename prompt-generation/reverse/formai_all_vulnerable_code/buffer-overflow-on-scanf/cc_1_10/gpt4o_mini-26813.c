//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void getInput(char *str, int maxLength);
void reverseString(char *str);
int countVowels(const char *str);
void toUpperCase(char *str);
void toLowerCase(char *str);
void displayMenu();
void processOption(int option, char *str);

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH];
    int option;

    printf("Enter a string (up to %d characters): ", MAX_LENGTH - 1);
    getInput(str, MAX_LENGTH);
    
    do {
        displayMenu();
        printf("Choose an option (1-%d): ", 6);
        scanf("%d", &option);
        
        processOption(option, str);
    } while (option != 0);

    printf("Exiting program. Goodbye!\n");
    
    return 0;
}

void getInput(char *str, int maxLength) {
    // Clear the input buffer
    while (getchar() != '\n');
    
    printf("Input: ");
    fgets(str, maxLength, stdin);
    
    // Remove newline character from input if present
    str[strcspn(str, "\n")] = 0;
}

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    printf("Reversed string: %s\n", str);
}

int countVowels(const char *str) {
    int count = 0;
    char *ptr = (char*)str;
    
    while (*ptr) {
        char ch = tolower(*ptr);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        ptr++;
    }
    
    return count;
}

void toUpperCase(char *str) {
    char *ptr = str;
    while (*ptr) {
        *ptr = toupper(*ptr);
        ptr++;
    }
    printf("Uppercase string: %s\n", str);
}

void toLowerCase(char *str) {
    char *ptr = str;
    while (*ptr) {
        *ptr = tolower(*ptr);
        ptr++;
    }
    printf("Lowercase string: %s\n", str);
}

void displayMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Reverse String\n");
    printf("2. Count Vowels\n");
    printf("3. Convert to Uppercase\n");
    printf("4. Convert to Lowercase\n");
    printf("0. Exit\n");
}

void processOption(int option, char *str) {
    switch (option) {
        case 1:
            reverseString(str);
            break;
        case 2:
            printf("Number of vowels: %d\n", countVowels(str));
            break;
        case 3:
            toUpperCase(str);
            break;
        case 4:
            toLowerCase(str);
            break;
        case 0:
            break;
        default:
            printf("Invalid option, please try again.\n");
            break;
    }
}