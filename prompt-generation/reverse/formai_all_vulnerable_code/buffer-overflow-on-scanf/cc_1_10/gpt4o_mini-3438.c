//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

// Function prototypes
void toLowerCase(char *str);
void removeNonAlphanumeric(char *src, char *dst);
int isPalindrome(const char *str);
void handleInput(char *input);
void printResult(const char *input, int result);
void displayMenu();
void processChoice(int choice);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        processChoice(choice);
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("\nPalindrome Checker Menu:\n");
    printf("1. Check for Palindrome\n");
    printf("2. Clear Console\n");
    printf("3. Exit\n");
}

void processChoice(int choice) {
    char input[MAX_STRING_LENGTH];
    switch (choice) {
        case 1:
            handleInput(input);
            break;
        case 2:
            printf("\033[H\033[J"); // Clear console
            break;
        case 3:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

void handleInput(char *input) {
    printf("Enter a string to check: ");
    getchar(); // to consume the newline character from the buffer
    fgets(input, MAX_STRING_LENGTH, stdin);

    // Remove trailing newline character
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    int result = isPalindrome(input);
    printResult(input, result);
}

void printResult(const char *input, int result) {
    if (result) {
        printf("\"%s\" is a palindrome.\n", input);
    } else {
        printf("\"%s\" is not a palindrome.\n", input);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void removeNonAlphanumeric(char *src, char *dst) {
    int j = 0;
    for (int i = 0; src[i]; i++) {
        if (isalnum((unsigned char)src[i])) {
            dst[j++] = src[i];
        }
    }
    dst[j] = '\0'; // null terminate the destination string
}

int isPalindrome(const char *str) {
    char filtered[MAX_STRING_LENGTH];
    char lowerStr[MAX_STRING_LENGTH];

    removeNonAlphanumeric(str, filtered);
    toLowerCase(filtered);
    strcpy(lowerStr, filtered);

    int len = strlen(lowerStr);
    for (int i = 0; i < len / 2; i++) {
        if (lowerStr[i] != lowerStr[len - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}