//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char *text;
    int length;
} Sentence;

int main() {
    FILE *input_file, *output_file;
    char filename[100];
    char ch;
    int sentence_count = 0;
    int max_sentence_length = 0;
    Sentence sentences[MAX_SENTENCES];

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", filename);

    // Open input file
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read input file and store sentences in an array
    while ((ch = fgetc(input_file))!= EOF) {
        if (isspace(ch)) {
            sentences[sentence_count].text = malloc(sizeof(char) * (max_sentence_length + 2));
            strcpy(sentences[sentence_count].text, "");
            sentence_count++;
            max_sentence_length = 0;
        } else if (sentence_count < MAX_SENTENCES - 1 && max_sentence_length < MAX_SENTENCE_LENGTH - 2) {
            sentences[sentence_count].text = realloc(sentences[sentence_count].text, sizeof(char) * (max_sentence_length + 2));
            sentences[sentence_count].text[max_sentence_length] = ch;
            max_sentence_length++;
        }
    }

    // Close input file
    fclose(input_file);

    // Open output file
    output_file = fopen("summary.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    // Summarize sentences and write to output file
    for (int i = 0; i < sentence_count; i++) {
        fprintf(output_file, "%s\n", sentences[i].text);
    }

    // Close output file
    fclose(output_file);

    return 0;
}