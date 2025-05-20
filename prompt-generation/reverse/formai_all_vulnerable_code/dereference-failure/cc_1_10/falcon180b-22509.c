//Falcon-180B DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int i, j;
    char vowels[] = "aeiouAEIOU";
    char* temp = strdup(str);

    // Remove all vowels from the string
    for (i = 0; temp[i]; i++) {
        if (strchr(vowels, temp[i])) {
            for (j = i; temp[j]; j++) {
                temp[j] = temp[j + 1];
            }
            i--;
        }
    }

    // Copy the modified string back to the original string
    strcpy(str, temp);
    free(temp);
}

// Function to reverse a string
void reverseString(char* str) {
    int i, j;
    char temp;

    // Reverse the string
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i, j;

    // Compare the string with its reverse
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[1000];

    // Get user input
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove all vowels from the string
    removeVowels(input);

    // Reverse the string
    reverseString(input);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}