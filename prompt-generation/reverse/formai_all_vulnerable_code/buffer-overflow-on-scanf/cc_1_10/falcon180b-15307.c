//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include <math.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to remove vowels from a string
void removeVowels(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
            str[i] = '\0';
        }
    }
}

// Function to convert a string to title case
void titleCase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int choice;
    char string[100];

    // Menu
    printf("Welcome to the String Manipulation Program!\n");
    printf("Please enter your choice:\n");
    printf("1. Reverse string\n");
    printf("2. Check if string is a palindrome\n");
    printf("3. Remove vowels from string\n");
    printf("4. Convert string to title case\n");
    scanf("%d", &choice);

    // Input string
    printf("Enter a string: ");
    scanf("%[^\n]", string);

    // Perform selected operation
    switch (choice) {
        case 1:
            reverseString(string);
            printf("Reversed string: %s\n", string);
            break;
        case 2:
            if (isPalindrome(string)) {
                printf("The string is a palindrome.\n");
            } else {
                printf("The string is not a palindrome.\n");
            }
            break;
        case 3:
            removeVowels(string);
            printf("String with vowels removed: %s\n", string);
            break;
        case 4:
            titleCase(string);
            printf("String in title case: %s\n", string);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}