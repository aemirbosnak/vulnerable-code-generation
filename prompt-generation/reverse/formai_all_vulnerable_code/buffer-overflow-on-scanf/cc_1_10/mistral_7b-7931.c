//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is an alphanumeric character or not
int is_alphanumeric(char c) {
    return (isalnum(c) || isspace(c));
}

// Function to reverse a string
void reverse_string(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[101];
    printf("Enter a string: ");
    scanf("%s", str);

    // Making the string lowercase and removing spaces
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_alphanumeric(str[i])) {
            for (int j = i; str[j] != '\0'; j++) {
                str[j - 1] = str[j];
            }
            i--;
            continue;
        }
        str[i] = tolower(str[i]);
    }

    // Checking if the string is a palindrome
    if (is_palindrome(str)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    // Reversing the string for fun
    int len = strlen(str);
    reverse_string(str, 0, len - 1);
    printf("The reversed string is: %s\n", str);

    return 0;
}