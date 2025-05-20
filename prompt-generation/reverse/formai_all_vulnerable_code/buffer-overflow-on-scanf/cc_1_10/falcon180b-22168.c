//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: realistic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

int isPalindrome(char* str);
void reverseString(char* str);

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}

int isPalindrome(char* str) {
    int length = strlen(str);
    char cleanStr[MAX_LENGTH];
    int i, j;

    // Remove non-alphabetic characters and convert to lowercase
    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(str[i])) {
            cleanStr[j++] = tolower(str[i]);
        }
    }
    cleanStr[j] = '\0';

    // Compare clean string with its reverse
    for (i = 0, j = strlen(cleanStr) - 1; i < j; i++, j--) {
        if (cleanStr[i]!= cleanStr[j]) {
            return 0;
        }
    }

    return 1;
}

void reverseString(char* str) {
    int length = strlen(str);
    char temp;
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}