//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000
#define MAX_NUMBER_OF_CHARACTERS 26
#define MAX_NUMBER_OF_WORDS 100

int is_palindrome(char *string);
int count_words(char *string);

int main(int argc, char *argv[]) {
    char input_string[MAX_STRING_LENGTH];
    int string_length, number_of_words, i;
    int is_palindrome_flag = 0;
    char *word_array[MAX_NUMBER_OF_WORDS];
    time_t start_time, end_time;

    // Get input string from user
    printf("Enter a string to check if it is a palindrome: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);
    string_length = strlen(input_string);

    // Remove leading/trailing spaces and convert to lowercase
    input_string[string_length - 1] = '\0';
    for (i = 0; i < string_length; i++) {
        input_string[i] = tolower(input_string[i]);
    }

    // Count number of words in string
    number_of_words = count_words(input_string);

    // Check if string is a palindrome
    if (is_palindrome(input_string)) {
        is_palindrome_flag = 1;
    }

    // Print result
    if (is_palindrome_flag) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    // Print number of words in string
    printf("The input string contains %d words.\n", number_of_words);

    return 0;
}

int is_palindrome(char *string) {
    int i, j, string_length;

    // Remove leading/trailing spaces and convert to lowercase
    string_length = strlen(string);
    for (i = 0; i < string_length; i++) {
        string[i] = tolower(string[i]);
    }

    // Check if string is a palindrome
    for (i = 0, j = string_length - 1; i < j; i++, j--) {
        if (string[i]!= string[j]) {
            return 0;
        }
    }

    return 1;
}

int count_words(char *string) {
    int i, j, word_count = 0;

    // Remove leading/trailing spaces and convert to lowercase
    for (i = 0; i < strlen(string); i++) {
        if (isspace(string[i])) {
            string[i] = '\0';
        } else {
            string[i] = tolower(string[i]);
        }
    }

    // Count number of words in string
    for (i = 0; i < strlen(string); i++) {
        if (string[i]!= '\0') {
            word_count++;
            for (j = i; j < strlen(string); j++) {
                if (string[j] == '\0') {
                    break;
                }
                string[j] = '\0';
            }
        }
    }

    return word_count;
}