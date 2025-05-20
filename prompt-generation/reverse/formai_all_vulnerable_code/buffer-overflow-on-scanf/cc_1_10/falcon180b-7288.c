//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
    int position;
} Sentence;

int main() {
    FILE *fp;
    char filename[100];
    char input_text[MAX_SENTENCE_LENGTH];
    int num_sentences = 0;
    Sentence sentences[MAX_SENTENCES];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(input_text, MAX_SENTENCE_LENGTH, fp)!= NULL) {
        if (num_sentences >= MAX_SENTENCES) {
            printf("Error: Maximum number of sentences reached.\n");
            exit(1);
        }

        sentences[num_sentences].length = strlen(input_text);
        strcpy(sentences[num_sentences].text, input_text);
        sentences[num_sentences].position = ftell(fp);
        num_sentences++;
    }

    fclose(fp);

    printf("Enter the number of sentences to summarize: ");
    scanf("%d", &num_sentences);

    if (num_sentences > MAX_SENTENCES) {
        printf("Error: Maximum number of sentences exceeded.\n");
        exit(1);
    }

    for (int i = 0; i < num_sentences; i++) {
        fseek(fp, sentences[i].position, SEEK_SET);
        fgets(input_text, MAX_SENTENCE_LENGTH, fp);
        printf("%s", input_text);
    }

    fclose(fp);

    return 0;
}