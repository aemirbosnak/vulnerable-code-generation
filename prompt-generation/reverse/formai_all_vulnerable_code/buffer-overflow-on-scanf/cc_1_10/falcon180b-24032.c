//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to reverse a string
void reverseString(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
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

// Function to convert a string to uppercase
void strtoupper(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            str[i] = '\0';
        } else {
            i++;
        }
    }
}

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Check if the string is a palindrome
    int result = isPalindrome(str);
    if (result == 1) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Convert the string to uppercase
    strtoupper(str);
    printf("Uppercase string: %s\n", str);

    // Remove all vowels from the string
    removeVowels(str);
    printf("String without vowels: %s\n", str);

    // Count the number of words in the string
    int wordCount = countWords(str);
    printf("Number of words in the string: %d\n", wordCount);

    return 0;
}