//FormAI DATASET v1.0 Category: Text Summarizer ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUMMARY_LENGTH 50

int main() {
    char input_text[1000];
    printf("Enter the text to be summarized: ");
    fgets(input_text, 1000, stdin);

    // Split the input text into individual sentences
    char *sentence_ptr = strtok(input_text, ".!?");
    char sentence_array[10][100];
    int sentence_count = 0;

    while (sentence_ptr != NULL) {
        strcpy(sentence_array[sentence_count], sentence_ptr);
        sentence_count++;
        sentence_ptr = strtok(NULL, ".!?");
    }

    // Calculate the importance score of each sentence
    int score_array[sentence_count];
    for (int i = 0; i < sentence_count; i++) {
        score_array[i] = 0;
        for (int j = 0; j < strlen(sentence_array[i]); j++) {
            if (sentence_array[i][j] == 'e' || sentence_array[i][j] == 'E') {
                score_array[i] += 2;
            } else if (sentence_array[i][j] == 'a' || sentence_array[i][j] == 'A') {
                score_array[i] += 1;
            }
        }
        score_array[i] *= sentence_count - i;
    }

    // Pick the sentences with the highest importance score to include in the summary
    char summary[MAX_SUMMARY_LENGTH] = "";
    for (int k = 0; k < MAX_SUMMARY_LENGTH; k++) {
        int max_index = 0;
        int max_score = -1;
        for (int l = 0; l < sentence_count; l++) {
            if (score_array[l] > max_score) {
                max_score = score_array[l];
                max_index = l;
            }
        }
        strcat(summary, sentence_array[max_index]);
        score_array[max_index] = -1;
    }

    printf("\nSummary: %s", summary);

    return 0;
}