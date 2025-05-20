//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to reverse a string
void reverse_string(char* str) {
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

// function to check if a string is a palindrome
int is_palindrome(char* str) {
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        if (str[i]!= str[j]) {
            return 0; // not a palindrome
        }
        i++;
        j--;
    }

    return 1; // is a palindrome
}

int main() {
    char input_string[100];
    char reversed_string[100];
    char palindrome_string[100];

    // prompt user to enter a string
    printf("Enter a string: ");
    scanf("%s", input_string);

    // reverse the input string
    reverse_string(input_string);
    strcpy(reversed_string, input_string);

    // check if the input string is a palindrome
    if (is_palindrome(input_string)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    // prompt user to enter a new string
    printf("Enter a new string: ");
    scanf("%s", input_string);

    // reverse the new string
    reverse_string(input_string);
    strcpy(reversed_string, input_string);

    // check if the new string is a palindrome
    if (is_palindrome(input_string)) {
        printf("The new string is a palindrome.\n");
    } else {
        printf("The new string is not a palindrome.\n");
    }

    return 0;
}