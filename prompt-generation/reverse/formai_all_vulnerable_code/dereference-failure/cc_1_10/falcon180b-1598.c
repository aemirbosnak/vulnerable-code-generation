//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';
    printf("Reversed string: %s\n", reversed);
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
                count++;
            }
        }
    }
    return count;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length/2; i++) {
        if (tolower(str[i])!= tolower(str[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a pangram
int isPangram(char* str) {
    int vowels = countVowels(str);
    if (vowels == 0) {
        return 0;
    }
    int hasAllLetters = 0;
    for (int i = 0; i < 26; i++) {
        if (isalpha(str[i])) {
            hasAllLetters = 1;
            break;
        }
    }
    if (!hasAllLetters) {
        return 0;
    }
    return 1;
}

// Function to generate a random string of a given length
char* generateRandomString(int length) {
    char* str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
    return str;
}

int main() {
    char* text = "The quick brown fox jumps over the lazy dog. ";
    int length = strlen(text);
    char* reversed = malloc(length + 1);
    strcpy(reversed, text);
    reverse(reversed);
    if (strcmp(text, reversed) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    free(reversed);

    if (isPalindrome(text)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    int numVowels = countVowels(text);
    printf("The string contains %d vowels.\n", numVowels);

    if (isPangram(text)) {
        printf("The string is a pangram.\n");
    } else {
        printf("The string is not a pangram.\n");
    }

    char* randomStr = generateRandomString(10);
    printf("Random string: %s\n", randomStr);
    free(randomStr);
    return 0;
}