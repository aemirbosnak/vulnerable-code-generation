//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

int isPalindrome(char* str) {
    int i, j;
    char cleanStr[MAX_LENGTH];
    strcpy(cleanStr, str);

    // Remove non-alphanumeric characters and convert to lowercase
    for (i = 0, j = 0; i < strlen(str); i++) {
        if (isalnum(str[i])) {
            cleanStr[j++] = tolower(str[i]);
        }
    }

    int length = strlen(cleanStr);
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (cleanStr[i]!= cleanStr[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading/trailing whitespace
    int i = 0;
    while (isspace(input[i])) {
        i++;
    }
    int j = strlen(input) - 1;
    while (isspace(input[j])) {
        j--;
        input[j] = '\0';
    }

    if (isPalindrome(input)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}