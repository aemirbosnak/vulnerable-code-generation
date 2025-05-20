//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    while(start < end) {
        if(str[start++] != str[end--]) {
            return 0;
        }
    }
    return 1;
}

void printResult(char *str) {
    if(isPalindrome(str)) {
        printf("The string '%s' is a palindrome!", str);
    } else {
        printf("The string '%s' is NOT a palindrome.", str);
    }
}

int main() {
    char name[] = "Bob";
    char randomWord1[] = "racecar";
    char randomWord2[] = "hello";
    char userInput[20];
    
    printf("Welcome to the Palindrome Checker!\n\n");
    printf("Check if a few words are palindromes...\n\n");
    
    printf("Is %s a palindrome?\n", name);
    printResult(name);
    printf("\n\n");
    
    printf("How about %s?\n", randomWord1);
    printResult(randomWord1);
    printf("\n\n");
    
    printf("And %s?\n", randomWord2);
    printResult(randomWord2);
    printf("\n\n");
    
    printf("Enter a word of your own to check: ");
    scanf("%s", userInput);
    printResult(userInput);
    printf("\n\n");
    
    printf("Thanks for using the Palindrome Checker. Have a nice day!\n");
    
    return 0;
}