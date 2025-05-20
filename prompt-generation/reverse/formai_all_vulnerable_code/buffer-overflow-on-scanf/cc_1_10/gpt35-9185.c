//FormAI DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <string.h>

// function to check if a string is palindrome using recursion
int isPalindrome(char *str, int start, int end) {
    if(start >= end) {
        return 1;
    }
    if(str[start] != str[end]) {
        return 0;
    }
    return isPalindrome(str, start+1, end-1);
}

int main() {
    char string[100];
    int length, choice, i, j, k;
    printf("Enter a string: ");
    scanf("%[^\n]", string);
    length = strlen(string);
    printf("\nString length: %d\n", length);

    // menu for string operations
    printf("\nWhat do you want to do with the string?\n");
    printf("1. Reverse the string\n");
    printf("2. Check if the string is palindrome\n");
    printf("3. Remove all vowels from the string\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // switch statement for each operation
    switch(choice) {
        case 1:
            printf("\nReversed string: ");
            for(i=length-1; i>=0; i--) {
                printf("%c", string[i]);
            }
            break;
        case 2:
            if(isPalindrome(string, 0, length-1)) {
                printf("\nThe string is a palindrome!");
            }
            else {
                printf("\nThe string is not a palindrome.");
            }
            break;
        case 3:
            printf("\nString after removing vowels: ");
            for(i=0; i<length; i++) {
                if(string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u' &&
                   string[i] != 'A' && string[i] != 'E' && string[i] != 'I' && string[i] != 'O' && string[i] != 'U') {
                    printf("%c", string[i]);
                }
            }
            break;
        default:
            printf("\nInvalid choice.");
    }
    printf("\n");
    return 0;
}