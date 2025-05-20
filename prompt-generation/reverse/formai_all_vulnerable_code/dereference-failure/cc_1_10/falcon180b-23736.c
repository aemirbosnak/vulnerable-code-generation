//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    char* temp = (char*)malloc(len + 1);
    strcpy(temp, str);
    for (int i = 0; i < len / 2; i++) {
        char c = temp[i];
        temp[i] = temp[len - i - 1];
        temp[len - i - 1] = c;
    }
    strcpy(str, temp);
    free(temp);
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    char vowels[] = "aeiouAEIOU";
    int len = strlen(str);
    char* temp = (char*)malloc(len + 1);
    strcpy(temp, str);
    for (int i = 0; i < len; i++) {
        char c = temp[i];
        int found = 0;
        for (int j = 0; j < strlen(vowels); j++) {
            if (c == vowels[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(temp, &c);
        }
    }
    strcpy(str, temp);
    free(temp);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    reverseString(input);
    printf("Reversed string: %s\n", input);

    // Remove all vowels from the string
    removeVowels(input);
    printf("String without vowels: %s\n", input);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}