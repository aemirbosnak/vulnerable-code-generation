//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void load_words(const char* filename, struct word_count words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s", words[num_words].word)!= EOF) {
        num_words++;
    }

    fclose(file);
}

int is_spam(const char* message, struct word_count words[], int num_words) {
    int num_spam_words = 0;
    int total_words = 0;

    char* tokens = strtok(message, " ");
    while (tokens!= NULL) {
        total_words++;

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(tokens, words[i].word) == 0) {
                num_spam_words++;
                break;
            }
        }

        tokens = strtok(NULL, " ");
    }

    float spam_percentage = (float)num_spam_words / total_words * 100.0;
    return spam_percentage >= 50.0;
}

void train_spam_filter(const char* train_filename, struct word_count words[]) {
    load_words(train_filename, words);
}

int main() {
    struct word_count words[MAX_WORDS];
    int num_words = 0;

    train_spam_filter("spam_words.txt", words);

    char* message = "Make money fast! Buy these pills!";
    int is_spam_result = is_spam(message, words, num_words);

    if (is_spam_result) {
        printf("Message is spam\n");
    } else {
        printf("Message is not spam\n");
    }

    return 0;
}