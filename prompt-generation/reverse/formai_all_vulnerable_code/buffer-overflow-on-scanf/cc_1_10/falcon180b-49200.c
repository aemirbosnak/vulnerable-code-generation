//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// Function to convert a string to title case
void titleCase(char *str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
        i++;
    }
}

int main() {
    char str[100];

    // Prompt user for input
    printf("Enter a string: ");
    scanf("%s", str);

    // Call functions to manipulate string
    reverseString(str);
    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    }
    else {
        printf("%s is not a palindrome.\n", str);
    }
    titleCase(str);
    printf("Title case: %s\n", str);

    return 0;
}