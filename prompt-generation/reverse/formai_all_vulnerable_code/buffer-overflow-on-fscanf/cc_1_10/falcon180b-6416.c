//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 3

// Function prototypes
void load_words(char *filename, char words[MAX_WORDS][MAX_WORD_LENGTH]);
int is_spam(char *message, char words[MAX_WORDS][MAX_WORD_LENGTH]);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <training_data> <message>\n", argv[0]);
        return 1;
    }

    char training_data[MAX_WORDS][MAX_WORD_LENGTH];
    load_words(argv[1], training_data);

    char message[1000];
    strcpy(message, argv[2]);

    int is_spam_result = is_spam(message, training_data);

    if (is_spam_result) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}

void load_words(char *filename, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }

    int word_count = 0;
    while (fscanf(fp, "%s", words[word_count])!= EOF) {
        word_count++;
        if (word_count >= MAX_WORDS) {
            break;
        }
    }

    fclose(fp);
}

int is_spam(char *message, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    int message_word_count = 0;
    int spam_word_count = 0;

    char *token = strtok(message, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i]) == 0) {
                spam_word_count++;
                break;
            }
        }

        if (i == MAX_WORDS) {
            if (strlen(token) >= MIN_WORD_LENGTH) {
                strcpy(words[message_word_count], token);
                message_word_count++;
            }
        }

        token = strtok(NULL, " ");
    }

    double spam_probability = (double)spam_word_count / message_word_count;

    if (spam_probability >= 0.5) {
        return 1;
    } else {
        return 0;
    }
}