//Falcon-180B DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char* str) {
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
int isPalindrome(char* str) {
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

// Recursive function to generate all permutations of a string
void generatePermutations(char* str, int start) {
    int i, j, k;
    char temp;

    if (start == strlen(str) - 1) {
        printf("%s\n", str);
        return;
    }

    for (i = start; i <= strlen(str) - 1; i++) {
        temp = str[start];
        str[start] = str[i];
        str[i] = temp;
        generatePermutations(str, start + 1);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverseString(str);

    // Check if the reversed string is a palindrome
    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    // Generate all permutations of the string
    printf("\nPermutations of %s:\n", str);
    generatePermutations(str, 0);

    return 0;
}