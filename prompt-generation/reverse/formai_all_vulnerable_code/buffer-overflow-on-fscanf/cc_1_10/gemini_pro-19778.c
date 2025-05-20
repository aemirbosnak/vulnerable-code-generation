//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_LEN 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wa = (WordCount *)a;
    WordCount *wb = (WordCount *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    // Load the dictionary
    FILE *dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        return EXIT_FAILURE;
    }

    char word[MAX_LEN];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    while (fscanf(dict, "%s", word) != EOF) {
        words[num_words].word = strdup(word);
        words[num_words].count = 0;
        num_words++;
    }

    fclose(dict);

    // Sort the dictionary
    qsort(words, num_words, sizeof(WordCount), compare);

    // Load the spam email
    FILE *email = fopen("email.txt", "r");
    if (email == NULL) {
        fprintf(stderr, "Error opening email file.\n");
        return EXIT_FAILURE;
    }

    char line[MAX_LEN];
    int num_lines = 0;

    while (fgets(line, MAX_LEN, email) != NULL) {
        num_lines++;

        // Tokenize the line
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Convert the token to lowercase
            for (int i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }

            // Check if the token is in the dictionary
            WordCount key = { token, 0 };
            WordCount *result = bsearch(&key, words, num_words, sizeof(WordCount), compare);

            if (result != NULL) {
                // The token is in the dictionary
                result->count++;
            }

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    fclose(email);

    // Calculate the spam score
    double spam_score = 0.0;
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            spam_score += words[i].count * log(num_words / words[i].count);
        }
    }

    // Print the spam score
    printf("Spam score: %f\n", spam_score);

    // Free the memory allocated for the dictionary
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    return EXIT_SUCCESS;
}