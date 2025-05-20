//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000

int main() {
    char text[MAX_TEXT_LENGTH];
    char c;
    int i = 0;
    float sentiment_score = 0;

    printf("Enter text to analyze: \n");

    // read text input
    while ((c = getchar()) != '\n' && i < MAX_TEXT_LENGTH) {
        // convert all characters to lowercase
        text[i++] = tolower(c);
    }

    // add null terminator to end of string
    text[i] = '\0';

    // open sentiment lexicon file
    FILE* lexicon_file = fopen("sentiment-lexicon.txt", "r");
    if (lexicon_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // read lexicon file line by line
    char line[100];
    while (fgets(line, sizeof(line), lexicon_file)) {
        char* token = strtok(line, "\t");
        char* word = token;
        int score = 0;

        // search for sentiment score in lexicon entry
        while (token != NULL) {
            if (strstr(token, "pos")) {
                score = atoi(token + 4);
            }
            if (strstr(token, "neg")) {
                score = -1 * atoi(token + 4);
            }
            token = strtok(NULL, "\t");
        }

        // search for occurrences of lexicon word in input text
        char* pos = strstr(text, word);
        while (pos != NULL) {
            sentiment_score += score;
            pos = strstr(pos + 1, word);
        }
    }

    // close lexicon file
    fclose(lexicon_file);

    // print sentiment score
    if (sentiment_score > 0) {
        printf("Positive sentiment detected!\n");
    } else if (sentiment_score < 0) {
        printf("Negative sentiment detected!\n");
    } else {
        printf("Neutral sentiment detected.\n");
    }

    return 0;
}