//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to reverse a string
void reverse_string(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to remove all vowels from a string
void remove_vowels(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            str[i] = '\0';
        }
    }
}

// Function to check if two strings are anagrams
int are_anagrams(char* str1, char* str2) {
    int i, j;
    char temp_str1[100], temp_str2[100];
    strcpy(temp_str1, str1);
    strcpy(temp_str2, str2);

    // Remove all vowels from both strings
    remove_vowels(temp_str1);
    remove_vowels(temp_str2);

    // Reverse the strings
    reverse_string(temp_str1);
    reverse_string(temp_str2);

    // Compare the strings
    for (i = 0, j = 0; temp_str1[i] && temp_str2[j]; i++, j++) {
        if (temp_str1[i]!= temp_str2[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100], str2[100];

    // Get input from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Check if the strings are anagrams
    if (are_anagrams(str1, str2)) {
        printf("%s and %s are anagrams!\n", str1, str2);
    } else {
        printf("%s and %s are not anagrams.\n", str1, str2);
    }

    return 0;
}