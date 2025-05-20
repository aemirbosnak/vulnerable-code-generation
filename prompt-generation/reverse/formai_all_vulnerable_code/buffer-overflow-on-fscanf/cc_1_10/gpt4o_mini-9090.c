//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

void print_welcome_message() {
    printf("Welcome to the Grateful Text Processor!\n");
    printf("This program will help you analyze and process text with gratitude.\n");
    printf("You can read a text file and get statistics such as word count, unique words, and more.\n");
    printf("Let's get started!\n");
    printf("------------------------------------------\n");
}

int read_file(const char *filename, char text[][MAX_WORD_LENGTH], int *word_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return -1;
    }

    *word_count = 0;
    while (fscanf(file, "%s", text[*word_count]) != EOF && *word_count < MAX_WORDS) {
        (*word_count)++;
    }

    fclose(file);
    return 0;
}

void count_unique_words(char text[][MAX_WORD_LENGTH], int word_count) {
    char unique_words[MAX_WORDS][MAX_WORD_LENGTH];
    int unique_count = 0;
    int found;

    for (int i = 0; i < word_count; i++) {
        found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(text[i], unique_words[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(unique_words[unique_count], text[i]);
            unique_count++;
        }
    }

    printf("Total unique words: %d\n", unique_count);
    printf("List of unique words:\n");
    for (int i = 0; i < unique_count; i++) {
        printf("%s\n", unique_words[i]);
    }
}

void count_word_length_distribution(char text[][MAX_WORD_LENGTH], int word_count) {
    int length_distribution[MAX_WORD_LENGTH] = {0};

    for (int i = 0; i < word_count; i++) {
        int length = strlen(text[i]);
        if (length < MAX_WORD_LENGTH) {
            length_distribution[length]++;
        }
    }

    printf("Word length distribution:\n");
    for (int i = 1; i < MAX_WORD_LENGTH; i++) {
        if (length_distribution[i] > 0) {
            printf("Length %d: %d\n", i, length_distribution[i]);
        }
    }
}

int main() {
    char text[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    print_welcome_message();

    char filename[MAX_WORD_LENGTH];
    printf("Please enter the path to the text file you wish to process: ");
    scanf("%s", filename);

    if (read_file(filename, text, &word_count) == -1) {
        return 1;
    }

    printf("Total words read: %d\n", word_count);
    
    count_unique_words(text, word_count);
    count_word_length_distribution(text, word_count);

    printf("Thank you for using the Grateful Text Processor. Have a wonderful day!\n");

    return 0;
}