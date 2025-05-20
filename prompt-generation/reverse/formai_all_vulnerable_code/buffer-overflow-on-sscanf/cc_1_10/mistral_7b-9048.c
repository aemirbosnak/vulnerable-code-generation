//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int sentiment;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *fp;
    char line[100];

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s%d", dictionary[num_words].word, &dictionary[num_words].sentiment);
        num_words++;
    }

    fclose(fp);
}

int analyze_sentiment(char *text) {
    int total_sentiment = 0;
    int num_words_in_text = 0;
    char word[WORD_LENGTH];

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int index = i;
            while (isalpha(text[index])) index++;
            strncpy(word, &text[i], index - i);
            word[index - i] = '\0';

            for (int j = 0; j < num_words; j++) {
                if (strcmp(word, dictionary[j].word) == 0) {
                    total_sentiment += dictionary[j].sentiment;
                    num_words_in_text++;
                    break;
                }
            }

            i = index - 1;
        }
    }

    return total_sentiment / num_words_in_text;
}

int main() {
    load_dictionary();

    char text[1000];
    printf("Enter text to analyze sentiment: ");
    fgets(text, sizeof(text), stdin);

    int sentiment = analyze_sentiment(text);

    if (sentiment > 0)
        printf("Sentiment is positive.\n");
    else if (sentiment < 0)
        printf("Sentiment is negative.\n");
    else
        printf("Sentiment is neutral.\n");

    return 0;
}