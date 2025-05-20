//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 1000
#define MAX_WORDS 100

// Function to split a string into words
int split_string(char* str, char words[][MAX_CHARS]) {
    int num_words = 0;
    char* token = strtok(str, " ");
    while (token!= NULL && num_words < MAX_WORDS) {
        strcpy(words[num_words], token);
        num_words++;
        token = strtok(NULL, " ");
    }
    return num_words;
}

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to sort an array of strings in reverse alphabetical order
void sort_strings(char words[][MAX_CHARS], int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char temp[MAX_CHARS];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

// Function to print an array of strings
void print_strings(char words[][MAX_CHARS], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to generate a random string of a given length
void generate_random_string(char* str, int len) {
    for (int i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[len] = '\0';
}

int main() {
    srand(time(NULL));
    char input_string[MAX_CHARS];
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Split input string into words
    char words[MAX_WORDS][MAX_CHARS];
    int num_words = split_string(input_string, words);

    // Reverse each word
    for (int i = 0; i < num_words; i++) {
        reverse_string(words[i]);
    }

    // Sort words in reverse alphabetical order
    sort_strings(words, num_words);

    // Print sorted words
    printf("Reversed and sorted words:\n");
    print_strings(words, num_words);

    return 0;
}