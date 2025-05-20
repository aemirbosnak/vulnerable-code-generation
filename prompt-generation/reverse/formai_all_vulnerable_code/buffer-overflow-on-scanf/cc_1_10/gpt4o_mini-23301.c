//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to convert a string to lowercase and remove non-alphanumeric characters
void preprocessString(char *str, char *processed) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            processed[j++] = tolower(str[i]);
        }
    }
    processed[j] = '\0'; // Null terminate the processed string
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

// Function to display the interactive menu
void displayMenu() {
    printf("*****************************************\n");
    printf("Welcome to the Palindrome Checker!\n");
    printf("*****************************************\n");
    printf("1. Check if a word or phrase is a palindrome\n");
    printf("2. Exit\n");
    printf("*****************************************\n");
}

int main() {
    char str[MAX_SIZE];
    char processed[MAX_SIZE];
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the choice

        if (choice == 1) {
            printf("Enter a word or phrase: ");
            fgets(str, MAX_SIZE, stdin);
            str[strcspn(str, "\n")] = 0; // Remove newline character

            preprocessString(str, processed);
            printf("Processed String: %s\n", processed);

            if (isPalindrome(processed)) {
                printf("The given input is a palindrome!\n");
            } else {
                printf("The given input is not a palindrome.\n");
            }
        } else if (choice == 2) {
            printf("Thank you for using the Palindrome Checker! Goodbye.\n");
        } else {
            printf("Invalid option. Please choose 1 or 2.\n");
        }

        printf("\n");
    } while (choice != 2);

    return 0;
}