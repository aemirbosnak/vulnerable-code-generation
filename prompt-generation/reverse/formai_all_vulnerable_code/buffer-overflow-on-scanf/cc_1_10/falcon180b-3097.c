//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define SUMMARY_LENGTH 100

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence sentence[100];
    int count;
} Paragraph;

void addSentence(Paragraph *paragraph, char *sentence) {
    if (paragraph->count >= 100) {
        printf("Error: Paragraph can only contain 100 sentences.\n");
        return;
    }

    strcpy(paragraph->sentence[paragraph->count].text, sentence);
    paragraph->sentence[paragraph->count].length = strlen(sentence);
    paragraph->count++;
}

void summarize(Paragraph *paragraph, char *summary) {
    int i, j, k = 0;
    char word[MAX_SENTENCE_LENGTH];
    int wordCount = 0;

    for (i = 0; i < paragraph->count; i++) {
        j = 0;
        while (paragraph->sentence[i].text[j]!= '\0' && k < SUMMARY_LENGTH) {
            if (isalpha(paragraph->sentence[i].text[j])) {
                strncat(word, &paragraph->sentence[i].text[j], 1);
                j++;
            } else {
                strcat(word, " ");
                j++;
            }
            k++;
        }

        if (word[0]!= '\0') {
            strcat(summary, word);
            strcat(summary, " ");
        }
    }

    summary[strlen(summary) - 1] = '\0';
}

int main() {
    FILE *inputFile, *outputFile;
    char filename[100], line[MAX_SENTENCE_LENGTH];
    Paragraph paragraph;
    char summary[SUMMARY_LENGTH];

    printf("Enter input file name: ");
    scanf("%s", filename);

    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    paragraph.count = 0;

    while (fgets(line, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        addSentence(&paragraph, line);
    }

    fclose(inputFile);

    summarize(&paragraph, summary);

    printf("Enter output file name: ");
    scanf("%s", filename);

    outputFile = fopen(filename, "w");
    if (outputFile == NULL) {
        printf("Error: Output file not found.\n");
        return 1;
    }

    fprintf(outputFile, "%s", summary);

    fclose(outputFile);

    return 0;
}