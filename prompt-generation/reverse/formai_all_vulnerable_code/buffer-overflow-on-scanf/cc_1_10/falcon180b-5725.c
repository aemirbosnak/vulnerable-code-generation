//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100
#define STOP_WORDS_COUNT 10

char stop_words[STOP_WORDS_COUNT][20] = {"the", "a", "an", "and", "or", "but", "for", "nor", "on", "at"};

void remove_stop_words(char* sentence) {
    int i, j;
    char* token;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < STOP_WORDS_COUNT; i++) {
            if (strcmp(token, stop_words[i]) == 0) {
                strcpy(token, "");
                break;
            }
        }
        strcat(sentence, token);
        strcat(sentence, " ");
        token = strtok(NULL, " ");
    }
}

void generate_sentence_summary(char* summary, char* sentence) {
    int sentence_length = strlen(sentence);
    int summary_length = strlen(summary);

    if (summary_length + sentence_length >= MAX_SENTENCE_LENGTH) {
        strcat(summary, "...");
        return;
    }

    strcat(summary, sentence);
}

int main() {
    FILE* input_file;
    char filename[100];
    char sentence[MAX_SENTENCE_LENGTH];
    char summary[MAX_SENTENCE_LENGTH];
    int sentence_count = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        remove_stop_words(sentence);
        strcpy(summary, "");
        generate_sentence_summary(summary, sentence);
        printf("%s\n", summary);
        sentence_count++;

        if (sentence_count >= MAX_SENTENCES) {
            break;
        }
    }

    fclose(input_file);

    return 0;
}