//Falcon-180B DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove all non-alphanumeric characters from a string
char* remove_non_alphanumeric(char* str) {
    char* result = strdup(str);
    char* p = result;
    while (*p) {
        if (!isalnum(*p)) {
            *p = '\0';
        }
        p++;
    }
    return result;
}

// Function to count the number of words in a string
int count_words(char* str) {
    int count = 0;
    char* p = str;
    while (*p) {
        if (isspace(*p)) {
            count++;
        }
        p++;
    }
    return count;
}

// Function to reverse the order of words in a string
char* reverse_words(char* str) {
    char* result = strdup(str);
    char* p = result;
    while (*p) {
        if (isspace(*p)) {
            *p = '\0';
        }
        p++;
    }
    p = result + strlen(result) - 1;
    while (p > result) {
        if (*p == '\0') {
            p--;
        } else {
            break;
        }
    }
    while (p > result) {
        char c = *p;
        *p = '\0';
        p--;
        strcat(result, &c);
    }
    return result;
}

int main() {
    char input[1024];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    char* cleaned_input = remove_non_alphanumeric(input);
    int num_words = count_words(cleaned_input);
    char* reversed_input = reverse_words(cleaned_input);
    printf("Cleaned input: %s\n", cleaned_input);
    printf("Number of words: %d\n", num_words);
    printf("Reversed input: %s\n", reversed_input);
    free(cleaned_input);
    free(reversed_input);
    return 0;
}