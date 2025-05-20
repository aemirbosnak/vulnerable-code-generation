//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100

struct sentence {
    char *text;
    int length;
    int sentiment;
};

struct word {
    char *text;
    int length;
    int sentiment;
};

int get_sentiment(char *word) {
    if (strcmp(word, "happy") == 0) {
        return 1;
    } else if (strcmp(word, "sad") == 0) {
        return -1;
    } else {
        return 0;
    }
}

int get_sentence_sentiment(struct sentence *sentence) {
    int sentiment = 0;
    int word_count = 0;

    for (int i = 0; i < sentence->length; i++) {
        if (isspace(sentence->text[i])) {
            continue;
        }

        struct word *word = malloc(sizeof(struct word));
        word->text = malloc((sentence->length - i) * sizeof(char));
        word->length = 0;

        while (i < sentence->length &&!isspace(sentence->text[i])) {
            word->text[word->length++] = tolower(sentence->text[i++]);
        }

        word->sentiment = get_sentiment(word->text);
        sentiment += word->sentiment;
        word_count++;

        free(word->text);
        free(word);
    }

    if (word_count > 0) {
        return sentiment / word_count;
    } else {
        return 0;
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    char buffer[4096];
    struct sentence sentences[MAX_SENTENCES];
    int sentence_count = 0;

    while (fgets(buffer, sizeof(buffer), input_file)!= NULL) {
        char *token = strtok(buffer, ".");

        if (token!= NULL) {
            int length = strlen(token);

            if (sentence_count >= MAX_SENTENCES) {
                printf("Maximum number of sentences reached.\n");
                break;
            }

            sentences[sentence_count].text = malloc((length + 1) * sizeof(char));
            strcpy(sentences[sentence_count].text, token);
            sentences[sentence_count].length = length;
            sentence_count++;
        }
    }

    fclose(input_file);

    for (int i = 0; i < sentence_count; i++) {
        printf("Sentence %d: %s\n", i + 1, sentences[i].text);
        printf("Sentiment: %d\n", get_sentence_sentiment(&sentences[i]));
        printf("\n");
    }

    return 0;
}