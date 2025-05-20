//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 101

void reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int isPalindrome(char *str) {
    int len = strlen(str);
    if (len <= 1)
        return 1;

    reverse(str, 0, len - 1);

    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[SIZE], str2[SIZE];

    printf("Enter a word: ");
    fgets(str, SIZE, stdin);

    // Surrealist part begins here
    str[strlen(str) - 1] = '\0'; // Remove newline character

    printf("Enter its mirrored counterpart: ");
    fgets(str2, SIZE, stdin);

    str2[strlen(str2) - 1] = '\0'; // Remove newline character

    if (strlen(str) != strlen(str2)) {
        printf("Error: Lengths of input strings do not match.\n");
        return 1;
    }

    printf("Checking if '%s' and '%s' are palindromes...\n", str, str2);

    if (isPalindrome(str) && isPalindrome(str2)) {
        printf("Congratulations! Both strings are palindromes.\n");
    } else {
        printf("Sorry, only one of the strings is a palindrome.\n");
    }

    return 0;
}

// Surrealist part ends here