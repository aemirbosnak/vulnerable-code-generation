//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

// Function to reverse a string
void reverse(char* str, int length) {
    char temp;
    int start = 0;
    int end = length - 1;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str, int length) {
    reverse(str, length);
    if (strcmp(str, str + 1) == 0) {
        return 1; // It's a palindrome
    } else {
        return 0; // It's not a palindrome
    }
}

int main() {
    char str[100];
    int length;

    // Get user input
    printf("Enter a string (maximum 100 characters): ");
    scanf("%[^\n]", str);

    // Remove newline character from input
    str[strcspn(str, "\n")] = '\0';

    // Convert input to lowercase
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }

    // Check if input is a palindrome
    length = strlen(str);
    if (isPalindrome(str, length)) {
        printf("Yes, \"%s\" is a palindrome.\n", str);
    } else {
        printf("No, \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}