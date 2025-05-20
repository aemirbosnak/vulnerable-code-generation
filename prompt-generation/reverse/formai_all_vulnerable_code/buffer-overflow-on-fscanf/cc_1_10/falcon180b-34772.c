//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

char *words[MAX_WORDS];
int num_words;

void load_words() {
    FILE *f = fopen("words.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(f, "%s", word)!= EOF) {
        words[num_words++] = strdup(word);
    }
    fclose(f);
}

void unload_words() {
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
}

int is_spam(char *message) {
    int spam_score = 0;
    char *word;
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            word = &message[i];
            while (isalpha(word[strlen(word)-1])) {
                word[strlen(word)-1] = '\0';
                word--;
            }
            for (int j = 0; j < num_words; j++) {
                if (strcmp(word, words[j]) == 0) {
                    spam_score++;
                }
            }
        }
    }
    return spam_score;
}

int main() {
    load_words();
    char message[1000];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    int spam_score = is_spam(message);
    if (spam_score > 0) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }
    unload_words();
    return 0;
}