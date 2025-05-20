//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int is_spam;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            exit(1);
        }
        words[num_words].word = strdup(word);
        words[num_words].is_spam = 0;
        num_words++;
    }

    fclose(file);
}

void train_spam(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading spam file.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].is_spam = 1;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    exit(1);
                }
                words[num_words].word = strdup(token);
                words[num_words].is_spam = 1;
                num_words++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
}

int is_spam(char *message) {
    char *token = strtok(message, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].word) == 0) {
                if (words[i].is_spam) {
                    return 1;
                }
                break;
            }
        }
        if (i == num_words) {
            return 0;
        }
        token = strtok(NULL, " ");
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s load_words <words_file> train_spam <spam_file> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "load_words") == 0) {
        load_words(argv[2]);
    } else if (strcmp(argv[1], "train_spam") == 0) {
        train_spam(argv[2]);
    } else {
        printf("Invalid command.\n");
        return 1;
    }

    char *message = argv[3];
    if (is_spam(message)) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}