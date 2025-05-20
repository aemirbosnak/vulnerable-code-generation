//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *file;
    char *text = NULL, *word = NULL, *sentence = NULL, *summary = NULL;
    size_t text_size = 0, word_size = 0, sentence_size = 0, summary_size = 0;
    int word_count = 0;

    printf("Enter the path to the text file: ");
    scanf("%s", file);

    file = fopen(file, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    text_size = ftell(file);
    rewind(file);

    text = malloc(text_size + 1);

    if (text == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    fread(text, text_size, 1, file);
    fclose(file);

    text[text_size] = '\0';

    word = strtok(text, ",.?!;:");

    while (word!= NULL) {
        word_size = strlen(word);

        if (word_size > 0) {
            word_count++;
        }

        sentence = realloc(sentence, sentence_size + word_size + 1);

        if (sentence == NULL) {
            printf("Error: Could not allocate memory.\n");
            exit(1);
        }

        strcat(sentence, word);
        strcat(sentence, " ");

        word = strtok(NULL, ",.?!;:");
    }

    summary = malloc(100);

    if (summary == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    sprintf(summary, "The text contains %d words and %d sentences.\n", word_count, word_count / 5);

    printf("%s", summary);

    free(text);
    free(sentence);
    free(summary);

    return 0;
}