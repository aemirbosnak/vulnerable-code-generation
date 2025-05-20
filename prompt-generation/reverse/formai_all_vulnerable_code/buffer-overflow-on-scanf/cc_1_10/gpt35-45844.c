//FormAI DATASET v1.0 Category: Text Summarizer ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCES 300
#define MAX_SUMMARY_SIZE 1000

void get_sentences(FILE *fp, char sentences[][100]) {
    char c, sentence[100];

    int i = 0, j = 0;
    while ((c = fgetc(fp)) != EOF && i < MAX_SENTENCES) {
        if (c == '.' || c == '?' || c == '!') {
            sentence[j++] = c;
            sentence[j] = '\n';
            strcpy(sentences[i++], sentence);
            j = 0;
        } else {
            sentence[j++] = c;
        }
    }
}

void remove_punctuations(char sentence[]) {
    for (int i = 0, j = 0; i < strlen(sentence); i++) {
        if (!ispunct(sentence[i]) || (sentence[i] == '.' && !isdigit(sentence[i + 1]))) {
            sentence[j++] = tolower(sentence[i]);
        }
    }
}

int number_of_occurrences(char sentence[], char target[]) {
    int count = 0;

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        if (strcmp(word, target) == 0) {
            count++;
        }
        word = strtok(NULL, " ");
    }

    return count;
}

void summarize(char sentences[][100], char summary[]) {
    char words[][20] = {"the", "a", "an", "is", "are", "was", "were", "has", "have", "had", "with", "in", "on", "at", "for", "to", "of", "by", "and", "or", "but"};

    int frequency[MAX_SENTENCES], sentence_count = 0;

    for (int i = 0; i < MAX_SENTENCES; i++) {
        remove_punctuations(sentences[i]);

        int count = 0;
        for (int j = 0; j < 21; j++) {
            count += number_of_occurrences(sentences[i], words[j]);
        }

        frequency[i] = count;
        sentence_count += (strlen(sentences[i]) > 0);
    }

    int summary_size = 0;
    for (int i = 0; i < MAX_SENTENCES; i++) {
        if (frequency[i] > (sentence_count / MAX_SENTENCES)) {
            strcat(summary, sentences[i]);
            summary_size += strlen(sentences[i]);
        }
        if (summary_size > MAX_SUMMARY_SIZE) {
            break;
        }
    }
}


int main() {
    FILE *fp;
    char path[100];

    printf("Enter file path: ");
    scanf("%s", path);

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    char sentences[MAX_SENTENCES][100], summary[MAX_SUMMARY_SIZE] = "";

    get_sentences(fp, sentences);
    summarize(sentences, summary);

    printf("\nSummary:\n%s", summary);

    fclose(fp);

    return 0;
}