//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100

// Function to print a string in reverse order
void print_string_backwards(char* str) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; --i)
        putchar(str[i]);
    putchar('\n');
}

// Function to count the number of vowels in a string
int count_vowels(char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isalpha(str[i])) {
            switch(tolower(str[i])) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    ++count;
                    break;
            }
        }
    }
    return count;
}

// Function to remove duplicates from a string and return a new string
char* remove_duplicates(char* str) {
    int index = 0;
    int len = strlen(str);

    char* result = malloc(len * sizeof(char));

    for (int i = 0; str[i] != '\0'; ++i) {
        bool already_exists = false;
        for (int j = 0; result[j] != '\0'; ++j) {
            if (str[i] == result[j]) {
                already_exists = true;
                break;
            }
        }

        if (!already_exists) {
            result[index++] = str[i];
        }
    }

    result[index] = '\0';
    return result;
}

// Function to print the elements of an array
void print_array(char arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%c", arr[i]);
    }
    putchar('\n');
}

int main() {
    char input_str[MAX_STRING_LENGTH];

    printf("Enter a string: ");
    scanf("%s", input_str);

    // Test functions here
    printf("Original string: %s\n", input_str);
    printf("String reversed: ");
    print_string_backwards(input_str);

    int num_vowels = count_vowels(input_str);
    printf("Number of vowels: %d\n", num_vowels);

    char* no_duplicates = remove_duplicates(input_str);
    printf("String without duplicates: ");
    print_array(no_duplicates, strlen(no_duplicates));

    free(no_duplicates);

    return 0;
}