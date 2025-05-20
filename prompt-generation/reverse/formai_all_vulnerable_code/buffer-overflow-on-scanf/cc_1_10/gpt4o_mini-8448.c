//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the string is a palindrome
int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Move forward if the left character is not alphanumeric
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        
        // Move backward if the right character is not alphanumeric
        while (left < right && !isalnum(str[right])) {
            right--;
        }

        // Check if characters are equal (case-insensitive)
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // It is a palindrome
}

int main() {
    char str[256];
    char choice;
    int status;

    do {
        printf("Welcome to the Palindrome Checker!\n");
        printf("Please enter a string you would like to check: ");
        fgets(str, sizeof(str), stdin);

        // Remove the newline character read by fgets
        str[strcspn(str, "\n")] = '\0';

        status = isPalindrome(str);

        if (status) {
            printf("Eureka! The string you provided is indeed a palindrome.\n");
        } else {
            printf("Oh no! The string you provided is not a palindrome.\n");
        }

        printf("If you would like to check another string, press 'Y' or 'y'.\n");
        printf("If you wish to exit, press any other key. What will it be? ");
        scanf(" %c", &choice);
        getchar(); // To consume the newline character after scanf

    } while (choice == 'Y' || choice == 'y');

    printf("Thank you for checking with us. Have a great day!\n");
    return 0;
}