//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 200
#define MAX_CHARACTERS 10000

int main(int argc, char *argv[]) {
    int desired_sentences;
    char input_text[MAX_CHARACTERS];
    char *sentences[MAX_SENTENCES];
    int sentence_count = 0;
    int i,j;
    int *sentence_scores;

    printf("Welcome to the Peaceful Text Summarizer!\n");
    printf("Please enter the text you want to summarize:\n");

    fgets(input_text, MAX_CHARACTERS, stdin);

    printf("How many sentences do you want the summary to have?\n");
    scanf("%d", &desired_sentences);

    char *sentence = strtok(input_text, ".!?");

    while (sentence && sentence_count < MAX_SENTENCES) {
        sentences[sentence_count++] = sentence;
        sentence = strtok(NULL, ".!?");
    }

    sentence_scores = (int*) calloc(sentence_count, sizeof(int));

    for (i = 0; i < sentence_count; i++) {
        for (j = 0; j < sentence_count; j++) {
            if (strcmp(sentences[i], sentences[j]) != 0) {
                char *word = strtok(sentences[i], " ");
                int count = 0;

                while (word) {
                    if (strstr(sentences[j], word)) {
                        count++;
                    }
                    word = strtok(NULL, " ");
                }

                sentence_scores[i] += count;
            }
        }
    }

    for (i = 0; i < desired_sentences; i++) {
        int highest_score = 0;
        int sentence_index = 0;

        for (j = 0; j < sentence_count; j++) {
            if (sentence_scores[j] > highest_score) {
                highest_score = sentence_scores[j];
                sentence_index = j;
            }
        }

        printf("%s.\n", sentences[sentence_index]);

        sentence_scores[sentence_index] = 0;
    }

    free(sentence_scores);

    return 0;
}