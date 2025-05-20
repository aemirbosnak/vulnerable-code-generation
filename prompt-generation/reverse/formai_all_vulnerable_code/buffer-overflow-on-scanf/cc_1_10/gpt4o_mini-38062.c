//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void toLowerCaseAndTrim(char str[], char result[]) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {  // Check if the character is alphanumeric
            result[j++] = tolower(str[i]);  // Convert to lower case
        }
    }
    result[j] = '\0';  // Null-terminate the cleaned string
}

int isPalindrome(const char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Is a palindrome
}

void checkPalindrome(char inputStr[]) {
    char cleanedStr[MAX_LEN];
    
    // Clean the input string
    toLowerCaseAndTrim(inputStr, cleanedStr);
    
    printf("\nChecking if \"%s\" is a palindrome...\n", cleanedStr);
    
    if (isPalindrome(cleanedStr)) {
        printf("\033[1;32m🎉 YAY! \"%s\" is a Palindrome! 🎉\033[0m\n", cleanedStr);
    } else {
        printf("\033[1;31m😞 Oops! \"%s\" is NOT a Palindrome! 😞\033[0m\n", cleanedStr);
    }
}

int main() {
    char str[MAX_LEN];
    
    printf("✨ Welcome to the Palindrome Checker! ✨\n");
    printf("Please enter a string (up to %d characters): ", MAX_LEN - 1);
    
    // Getting user input
    fgets(str, MAX_LEN, stdin);
    
    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';
    
    checkPalindrome(str);
    
    // Keeping the program open for further checks or to exit
    char continueCheck;
    do {
        printf("\nDo you want to check another string? (Y/N): ");
        scanf(" %c", &continueCheck);
        continueCheck = toupper(continueCheck);
        
        if (continueCheck == 'Y') {
            printf("Please enter another string (up to %d characters): ", MAX_LEN - 1);
            scanf(" %[^\n]", str);  // Scan the input including spaces
            checkPalindrome(str);
        }
        
    } while (continueCheck == 'Y');
    
    printf("\n✨ Thank you for using the Palindrome Checker! ✨\n");
    return 0;
}