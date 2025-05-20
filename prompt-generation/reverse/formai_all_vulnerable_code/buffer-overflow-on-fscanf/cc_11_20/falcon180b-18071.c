//Falcon-180B DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    // Open the input file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Read in the words
    struct word_count words[MAX_WORDS];
    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            exit(1);
        }
        strcpy(words[num_words].word, word);
        words[num_words].count = 1;
        num_words++;
    }
    fclose(input_file);

    // Query the database
    char query[MAX_WORD_LENGTH];
    printf("Enter a query: ");
    fgets(query, MAX_WORD_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // remove newline character

    // Split the query into words
    char* tokens[MAX_WORDS];
    int num_tokens = 0;
    char* token = strtok(query, " ");
    while (token!= NULL) {
        if (num_tokens >= MAX_WORDS) {
            printf("Error: too many words in query.\n");
            exit(1);
        }
        strcpy(tokens[num_tokens], token);
        num_tokens++;
        token = strtok(NULL, " ");
    }

    // Count the number of results
    int num_results = 0;
    for (int i = 0; i < num_tokens; i++) {
        int j;
        for (j = 0; j < num_words; j++) {
            if (strcmp(tokens[i], words[j].word) == 0) {
                words[j].count++;
                num_results++;
                break;
            }
        }
    }

    // Print the results
    printf("Results:\n");
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}