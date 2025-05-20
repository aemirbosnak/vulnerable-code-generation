//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 10000

// Function to remove non-alphanumeric characters and convert the string to lowercase
void cleanString(char* str) {
    int i = 0;
    while (*(str+i)!= '\0') {
        if (isalnum(*(str+i))) {
            *(str+i) = tolower(*(str+i));
        } else {
            *(str+i) = '\0';
        }
        i++;
    }
}

// Function to check if the given string is a palindrome
bool isPalindrome(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        if (*(str+i)!= *(str+j)) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);

    // Clean the input string
    cleanString(input);

    // Check if the input string is a palindrome
    if (isPalindrome(input)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}