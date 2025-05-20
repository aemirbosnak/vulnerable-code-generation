//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_freq {
    char word[MAX_WORD_LENGTH];
    int freq;
};

struct word_freq *load_words(char *filename) {
    FILE *f = fopen(filename, "r");
    struct word_freq *words = NULL;
    int num_words = 0;

    if (f == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fscanf(f, "%s", words[num_words].word)!= EOF) {
        num_words++;
        if (num_words == MAX_WORDS) {
            printf("Error: too many words in file %s\n", filename);
            exit(1);
        }
    }

    fclose(f);
    return words;
}

int is_spam(char *message, struct word_freq *words) {
    int num_spam_words = 0;
    int i;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char word[MAX_WORD_LENGTH];
            int j = 0;

            while (isalpha(message[i + j]) && j < MAX_WORD_LENGTH) {
                word[j] = tolower(message[i + j]);
                j++;
            }
            word[j] = '\0';

            int k;
            for (k = 0; k < num_spam_words; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    num_spam_words++;
                    break;
                }
            }
        }
    }

    return num_spam_words;
}

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[80];
    strftime(date, 80, "%Y-%m-%d %H:%M:%S", t);

    char *filename = "spam_words.txt";
    struct word_freq *words = load_words(filename);

    printf("Spam detection system started on %s\n", date);

    while (1) {
        char message[1000];
        printf("Enter message to check: ");
        fgets(message, sizeof(message), stdin);

        int is_spam_message = is_spam(message, words);

        if (is_spam_message > 0) {
            printf("Message is spam\n");
        } else {
            printf("Message is not spam\n");
        }
    }

    return 0;
}