//FormAI DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200

void summarize(char *article);

int main() {
    char article[MAX_SENTENCES * MAX_SENTENCE_LENGTH];
    printf("Enter the article to be summarized:\n");
    fgets(article, MAX_SENTENCES * MAX_SENTENCE_LENGTH, stdin);
    summarize(article);

    return 0;
}

void summarize(char *article) {
    char *sentence[MAX_SENTENCES];
    char *word;
    int sentenceCount = 0;
    int wordCount = 0;
    int score[MAX_SENTENCES];
    int index[MAX_SENTENCES];
    int i, j;

    // Tokenize the input into sentences
    for (i = 0; i < strlen(article); i++) {
        if (article[i] == '.' || article[i] == '?' || article[i] == '!') {
            article[i] = '\0';
            sentence[sentenceCount++] = &article[i - wordCount];
            wordCount = 0;
        } else {
            wordCount++;
        }
    }

    // Count the number of times each unique word appears in the sentences
    int count[sentenceCount][MAX_SENTENCE_LENGTH];
    memset(count, 0, sentenceCount * MAX_SENTENCE_LENGTH * sizeof(int));

    for (i = 0; i < sentenceCount; i++) {
        wordCount = 0;
        word = strtok(sentence[i], " ");
        while (word != NULL) {
            for (j = 0; j < wordCount; j++) {
                if (strcmp(word, sentence[i] + count[i][j]) == 0) {
                    break;
                }
            }

            if (j == wordCount) {
                count[i][wordCount] = word - sentence[i];
                wordCount++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Assign a score to each sentence based on the number of unique words it contains
    for (i = 0; i < sentenceCount; i++) {
        score[i] = 0;

        for (j = 0; j < MAX_SENTENCE_LENGTH; j++) {
            if (count[i][j] != 0) {
                score[i]++;
            } else {
                break;
            }
        }
    }

    // Sort the sentences by score in descending order
    for (i = 0; i < sentenceCount; i++) {
        index[i] = i;
    }

    for (i = 0; i < sentenceCount; i++) {
        for (j = i + 1; j < sentenceCount; j++) {
            if (score[index[i]] < score[index[j]]) {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    // Print the top 3 sentences
    printf("Summary:\n");
    for (i = 0; i < 3; i++) {
        printf("%s.", sentence[index[i]]);
    }
}