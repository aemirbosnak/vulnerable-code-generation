//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to count the number of words in a string
int count_words(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to capitalize the first letter of each word in a string
void capitalize(char* str) {
    char* token = strtok(str, " ");
    while (token!= NULL) {
        char* first_char = token;
        while (*first_char!= '\0') {
            if (*first_char >= 'a' && *first_char <= 'z') {
                *first_char -= 32;
            }
            first_char++;
        }
        strcat(str, token);
        strcat(str, " ");
        token = strtok(NULL, " ");
    }
}

int main() {
    char input_str[1000];
    printf("Enter a string: ");
    scanf("%s", input_str);

    // Reverse the string
    reverse(input_str);
    printf("Reversed string: %s\n", input_str);

    // Count the number of words in the string
    int word_count = count_words(input_str);
    printf("Number of words: %d\n", word_count);

    // Capitalize the first letter of each word in the string
    capitalize(input_str);
    printf("Capitalized string: %s\n", input_str);

    return 0;
}