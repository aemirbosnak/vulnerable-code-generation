//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 30

struct word {
    char *word;
    int count;
};

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void read_words(struct word *words, FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
            struct word *word_ptr = bsearch(word, words, MAX_WORDS, sizeof(struct word), compare_strings);
            if (word_ptr == NULL) {
                word_ptr = (struct word *)malloc(sizeof(struct word));
                strcpy(word_ptr->word, word);
                word_ptr->count = 1;
                qsort(words, MAX_WORDS, sizeof(struct word), compare_strings);
            } else {
                word_ptr->count++;
            }
        }
    }
}

int is_spam(char *message, struct word *words) {
    int spam_score = 0;
    char *word_ptr = strtok(message, " ");
    while (word_ptr!= NULL) {
        struct word *word_ptr2 = bsearch(word_ptr, words, MAX_WORDS, sizeof(struct word), compare_strings);
        if (word_ptr2!= NULL) {
            spam_score += word_ptr2->count;
        }
        word_ptr = strtok(NULL, " ");
    }
    return spam_score;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <training_data> <message>\n", argv[0]);
        return 1;
    }
    FILE *training_file = fopen(argv[1], "r");
    if (training_file == NULL) {
        fprintf(stderr, "Error opening training data file.\n");
        return 1;
    }
    struct word words[MAX_WORDS];
    read_words(words, training_file);
    fclose(training_file);

    FILE *message_file = fopen(argv[2], "r");
    if (message_file == NULL) {
        fprintf(stderr, "Error opening message file.\n");
        return 1;
    }
    char message[1000];
    fgets(message, sizeof(message), message_file);
    fclose(message_file);

    int spam_score = is_spam(message, words);
    if (spam_score >= 5) {
        printf("SPAM\n");
    } else {
        printf("NOT SPAM\n");
    }

    return 0;
}