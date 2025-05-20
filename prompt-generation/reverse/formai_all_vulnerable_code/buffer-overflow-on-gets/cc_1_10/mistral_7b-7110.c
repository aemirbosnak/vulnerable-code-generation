//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_SIZE 50

typedef struct {
    char word[WORD_SIZE];
    int freq;
} Word;

void summarize(char *text, int num_sentences) {
    int num_words = 0;
    Word words[MAX_WORDS];

    puts("Hello sunshine! 🌞 Let's make a cheerful text summary for you!");

    for (int i = 0; i < num_sentences; i++) {
        char sentence[1000];
        gets(sentence); // Read a sentence from user input

        char *token = strtok(sentence, " .,?!");
        while (token != NULL) {
            int is_new_word = 0;
            for (int j = 0; j < num_words; j++) {
                if (strcmp(words[j].word, token) == 0) {
                    words[j].freq++;
                    is_new_word = 1;
                    break;
                }
            }

            if (!is_new_word) {
                strcpy(words[num_words].word, token);
                strcpy(words[num_words].word + strlen(token), " ");
                words[num_words++].freq = 1;
            }

            token = strtok(NULL, " .,?!");
        }
    }

    puts("Great job, sunshine! Now let's find the top 10 cheerful words for you:");

    for (int i = 0; i < 10 && i < num_words; i++) {
        for (int j = i; j < num_words; j++) {
            if (words[j].freq > words[i].freq) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }

        printf("%d. %s (frequency: %d)\n", i + 1, words[i].word, words[i].freq);
    }
}

int main() {
    char text[1000];
    int num_sentences = 0;

    puts("Hey there! 🌺 I'd be happy to help you summarize a text.");

    gets(text); // Read the text from user input

    char *token = strtok(text, " .?!");
    while (token != NULL) {
        if (strlen(token) > 0 && token[strlen(token) - 1] == '.') {
            token[strlen(token) - 1] = '\0';
            num_sentences++;
        }

        token = strtok(NULL, " .?!");
    }

    summarize(text, num_sentences);

    return 0;
}