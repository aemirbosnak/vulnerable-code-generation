//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 100
#define MAX_LENGTH 100

struct sentence {
    char words[MAX_LENGTH];
    int length;
};

struct document {
    int num_sentences;
    struct sentence sentences[MAX_SENTENCES];
};

void read_document(struct document *doc) {
    char input[MAX_LENGTH];
    int i = 0;

    printf("Enter the document:\n");
    fgets(input, MAX_LENGTH, stdin);

    char *token = strtok(input, ",.?!;:");
    while (token!= NULL) {
        if (i >= MAX_SENTENCES) {
            printf("Maximum number of sentences reached.\n");
            break;
        }

        int j = 0;
        while (j < MAX_LENGTH && token[j]!= '\0') {
            doc->sentences[i].words[j] = token[j];
            j++;
        }
        doc->sentences[i].length = j;
        i++;

        token = strtok(NULL, ",.?!;:");
    }

    printf("Number of sentences: %d\n", i);
}

void summarize_document(struct document *doc, int k) {
    int i, j, count = 0;
    char summary[MAX_LENGTH];

    for (i = 0; i < doc->num_sentences; i++) {
        if (count >= k) {
            break;
        }

        for (j = 0; j < doc->sentences[i].length; j++) {
            if (count >= MAX_LENGTH) {
                break;
            }

            summary[count] = doc->sentences[i].words[j];
            count++;
        }

        if (i < doc->num_sentences - 1) {
            summary[count] = '.';
            count++;
        }
    }

    printf("Summary:\n%s\n", summary);
}

int main() {
    struct document doc;

    read_document(&doc);
    int k;

    printf("Enter the number of sentences in the summary: ");
    scanf("%d", &k);

    summarize_document(&doc, k);

    return 0;
}