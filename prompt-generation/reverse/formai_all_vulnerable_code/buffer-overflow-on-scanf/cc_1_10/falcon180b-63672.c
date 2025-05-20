//Falcon-180B DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to calculate the length of a string
int getLength(char *str) {
    int length = 0;
    while (*(str + length)!= '\0') {
        length++;
    }
    return length;
}

// Function to reverse a string
void reverseString(char *str) {
    char temp;
    int length = getLength(str);
    for (int i = 0; i < length / 2; i++) {
        temp = *(str + i);
        *(str + i) = *(str + length - 1 - i);
        *(str + length - 1 - i) = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int length = getLength(str);
    for (int i = 0; i < length / 2; i++) {
        if (*(str + i)!= *(str + length - 1 - i)) {
            return 0;
        }
    }
    return 1;
}

// Function to handle errors
void handleError(char *errorMessage) {
    printf("ERROR: %s\n", errorMessage);
    exit(1);
}

int main() {
    char inputString[MAX_SIZE];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    scanf("%s", inputString);

    // Reverse the string
    reverseString(inputString);

    // Check if the string is a palindrome
    if (isPalindrome(inputString)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}