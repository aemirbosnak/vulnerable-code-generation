//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h> // for tolower function
#include <stdlib.h> // for exit function

// function to check if string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (tolower(str[i])!= tolower(str[len-1-i])) {
            return 0;
        }
    }
    return 1;
}

// function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    char temp[len];
    int i, j;
    for (i = 0, j = len-1; i < j; i++, j--) {
        temp[i] = str[j];
        temp[j] = str[i];
    }
    strcpy(str, temp);
}

// function to convert string to uppercase
void toUpper(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

// function to convert string to lowercase
void toLower(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

// function to remove whitespace from string
void removeWhiteSpace(char *str) {
    int len = strlen(str);
    char temp[len];
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        if (!isspace(str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // remove whitespace from string
    removeWhiteSpace(str);

    // convert string to uppercase
    toUpper(str);

    // reverse the string
    reverse(str);

    // check if string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}