//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to print the given string in reverse order
void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str)-1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if the given string is a palindrome
int isPalindrome(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str)-1; i < j; i++, j--) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
    }
    return 1;
}

// Function to get the largest palindrome in the given string
void largestPalindrome(char str[]) {
    int i, j, k, maxLen = 1;
    char temp;
    for (i = 0; i < strlen(str); i++) {
        for (j = i, k = i; j < strlen(str); j++) {
            if (isPalindrome(str + i + 1)) {
                k++;
            } else {
                break;
            }
        }
        if (k - i > maxLen) {
            maxLen = k - i;
        }
    }
    printf("The largest palindrome in the given string is: ");
    reverse(str);
    printf("%s\n", str + maxLen - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    largestPalindrome(str);
    return 0;
}