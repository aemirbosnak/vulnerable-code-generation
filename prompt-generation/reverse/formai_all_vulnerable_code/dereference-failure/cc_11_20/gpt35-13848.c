//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char *posWords[1000], *negWords[1000];
    int posCount = 0, negCount = 0;

    //Read input text from user
    printf("Enter text to analyze:\n");
    fgets(input, 1000, stdin);

    //Open positive and negative word lists
    FILE *f_pos = fopen("positive_words.txt", "r");
    if (f_pos == NULL) {
        printf("Error: Unable to open positive_words.txt file!\n");
        return 1;
    }
    FILE *f_neg = fopen("negative_words.txt", "r");
    if (f_neg == NULL) {
        printf("Error: Unable to open negative_words.txt file!\n");
        return 1;
    }

    //Load words from positive word list
    char line[100];
    while (fgets(line, 100, f_pos) != NULL) {
        posWords[posCount] = strdup(line);
        posCount++;
    }
    fclose(f_pos);

    //Load words from negative word list
    while (fgets(line, 100, f_neg) != NULL) {
        negWords[negCount] = strdup(line);
        negCount++;
    }
    fclose(f_neg);

    //Count positive and negative words in input text
    char *word = strtok(input, " ,.-\n");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < posCount; i++) {
            if (strcmp(word, posWords[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (found == 1) {
            posCount++;
        }
        else {
            for (int i = 0; i < negCount; i++) {
                if (strcmp(word, negWords[i]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found == 1) {
                negCount++;
            }
        }
        word = strtok(NULL, " ,.-\n");
    }

    //Calculate sentiment score
    int score = posCount - negCount;
    printf("Sentiment Score: %d\n", score);
    if (score > 0) {
        printf("Positive sentiment!\n");
    }
    else if (score < 0) {
        printf("Negative sentiment!\n");
    }
    else {
        printf("Neutral sentiment.\n");
    }

    //Free allocated memory
    for (int i = 0; i < posCount; i++) {
        free(posWords[i]);
    }
    for (int i = 0; i < negCount; i++) {
        free(negWords[i]);
    }

    return 0;
}