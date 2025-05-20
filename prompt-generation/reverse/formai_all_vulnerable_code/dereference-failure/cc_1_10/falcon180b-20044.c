//Falcon-180B DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum string length
#define MAX_STRING_LENGTH 100

// Function to get a string from the user
char* get_string(char* prompt) {
    char input[MAX_STRING_LENGTH];
    printf("%s", prompt);
    fgets(input, MAX_STRING_LENGTH, stdin);
    return strdup(input);
}

// Function to reverse a string
char* reverse_string(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    int i = 0, j = length - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    str[length - 1] = '\0';
    return strdup(str);
}

// Function to count the number of vowels in a string
int count_vowels(char* str) {
    int count = 0;
    while (*str) {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* name = get_string("Enter your name: ");
    char* reversed_name = reverse_string(name);
    int vowel_count = count_vowels(name);
    int is_palindrome_name = is_palindrome(name);

    printf("Your name reversed is: %s\n", reversed_name);
    printf("The number of vowels in your name is: %d\n", vowel_count);
    if (is_palindrome_name) {
        printf("Your name is a palindrome!\n");
    } else {
        printf("Your name is not a palindrome.\n");
    }

    return 0;
}