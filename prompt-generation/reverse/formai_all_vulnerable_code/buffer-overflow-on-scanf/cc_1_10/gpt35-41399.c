//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STR_LEN 100

void count_alphabets(char *str, int *alphabets);
int is_palindrome(char *str);
void reverse_string(char *str);
int calculate_frequency(char *str, char ch);

int main() {
    char input_string[MAX_STR_LEN];
    int option, result;
    int alphabets[26] = { 0 }; // array to store the count of each alphabet

    do {
        printf("\nSelect an option: \n");
        printf("1. Calculate the frequency of a given character in the string.\n");
        printf("2. Check if the string is a palindrome or not.\n");
        printf("3. Reverse the string.\n");
        printf("4. Exit.\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a character to search for in the string: ");
                char ch;
                scanf(" %c", &ch);
                printf("Enter a string: ");
                scanf(" %[^\n]s", input_string);
                result = calculate_frequency(input_string, ch);
                printf("The frequency of %c in \"%s\" is %d.\n", ch, input_string, result);
                break;

            case 2:
                printf("Enter a string to check if it is a palindrome: ");
                scanf(" %[^\n]s", input_string);
                result = is_palindrome(input_string);
                if (result == 1) {
                    printf("\"%s\" is a palindrome.\n", input_string);
                }
                else {
                    printf("\"%s\" is not a palindrome.\n", input_string);
                }
                break;

            case 3:
                printf("Enter a string to reverse: ");
                scanf(" %[^\n]s", input_string);
                reverse_string(input_string);
                printf("The reversed string is: %s\n", input_string);
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }

        // count the number of each alphabet in the entered string
        count_alphabets(input_string, alphabets);
        printf("\nAlphabet Count:\n------------\n");
        for (int i = 0; i < 26; i++) {
            if (alphabets[i] > 0) {
                printf("%c: %d\n", i + 'a', alphabets[i]);
            }
        }

        // reset array for next iteration
        memset(alphabets, 0, sizeof(alphabets));
    } while (option != 4);

    return 0;
}

// helper function to count the number of each alphabet in a given string
void count_alphabets(char *str, int *alphabets) {
    while (*str != '\0') {
        if (isalpha(*str)) {
            alphabets[tolower(*str) - 'a']++;
        }
        str++;
    }
}

// helper function to check if a string is a palindrome
int is_palindrome(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (start < end) {
        if (*start != *end) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// helper function to reverse a given string
void reverse_string(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;
    while (start < end) {
        temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
        start++;
        end--;
    }
}

// helper function to calculate the frequency of a given character in a string
int calculate_frequency(char *str, char ch) {
    int frequency = 0;
    while (*str != '\0') {
        if (*str == ch) {
            frequency++;
        }
        str++;
    }
    return frequency;
}