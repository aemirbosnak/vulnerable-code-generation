//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 80
#define MAX_SENTENCES 100
#define MIN_SENTENCE_LENGTH 5

typedef struct sentence {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} sentence;

void add_sentence(sentence *sentences, int count, char *text) {
    if (count >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        exit(1);
    }
    strncpy(sentences[count].text, text, MAX_SENTENCE_LENGTH);
    sentences[count].length = strlen(text);
    count++;
}

int main() {
    sentence sentences[MAX_SENTENCES];
    int count = 0;
    char input[MAX_SENTENCE_LENGTH];
    char *token;
    FILE *file;

    printf("Enter the name of the text file: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while ((token = strtok(NULL, " \t\n\r\f.?!"))!= NULL) {
        if (token[0] == '\0') continue;
        if (strlen(token) < MIN_SENTENCE_LENGTH) continue;
        add_sentence(sentences, count, token);
    }

    fclose(file);

    if (count == 0) {
        printf("Error: No sentences found in file.\n");
        exit(1);
    }

    printf("Enter the number of sentences to summarize: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("%s\n", sentences[i].text);
    }

    return 0;
}