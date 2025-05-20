//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_WORD_LEN 50
#define MIN_WORD_LEN 3
#define THRESHOLD 0.5

struct token {
    char word[MAX_WORD_LEN];
    int count;
};

struct token tokens[MAX_TOKENS];
int num_tokens = 0;

void read_tokens(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) < MIN_WORD_LEN) {
            continue;
        }

        int i;
        for (i = 0; i < num_tokens; i++) {
            if (strcmp(tokens[i].word, word) == 0) {
                tokens[i].count++;
                break;
            }
        }

        if (i == num_tokens) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: too many tokens.\n");
                exit(1);
            }

            strcpy(tokens[num_tokens].word, word);
            tokens[num_tokens].count = 1;
            num_tokens++;
        }
    }

    fclose(fp);
}

void classify(char *email) {
    int i, j;
    int spam_count = 0;
    int non_spam_count = 0;

    for (i = 0; i < num_tokens; i++) {
        int word_found = 0;
        for (j = 0; j < strlen(email); j++) {
            if (tolower(email[j]) == tolower(tokens[i].word[0])) {
                int k;
                for (k = 0; k < strlen(tokens[i].word); k++) {
                    if (j + k >= strlen(email)) {
                        break;
                    }
                    if (tolower(email[j + k])!= tolower(tokens[i].word[k])) {
                        break;
                    }
                }

                if (k == strlen(tokens[i].word)) {
                    word_found = 1;
                    break;
                }
            }
        }

        if (word_found) {
            if (tokens[i].count > THRESHOLD) {
                spam_count++;
            } else {
                non_spam_count++;
            }
        }
    }

    if (spam_count > non_spam_count) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s email\n", argv[0]);
        exit(1);
    }

    read_tokens("tokens.txt");

    classify(argv[1]);

    return 0;
}