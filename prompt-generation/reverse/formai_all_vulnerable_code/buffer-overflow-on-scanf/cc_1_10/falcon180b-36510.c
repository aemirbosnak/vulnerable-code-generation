//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main() {
    FILE *input_file;
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read in the entire file
    char *file_contents = NULL;
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);
    file_contents = malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Error: could not allocate memory for file contents\n");
        exit(1);
    }
    fread(file_contents, file_size, 1, input_file);
    file_contents[file_size] = '\0';

    // Split the file contents into sentences
    int num_sentences = 0;
    Sentence sentences[MAX_SENTENCES];
    char *sentence_start = file_contents;
    while (num_sentences < MAX_SENTENCES && sentence_start!= NULL) {
        char *sentence_end = strpbrk(sentence_start, ".?!");
        if (sentence_end == NULL) {
            break;
        }
        *sentence_end = '\0';
        int sentence_length = strlen(sentence_start);
        if (sentence_length > MAX_SENTENCE_LENGTH) {
            printf("Warning: sentence is too long and will be truncated\n");
            sentence_length = MAX_SENTENCE_LENGTH;
        }
        strncpy(sentences[num_sentences].text, sentence_start, sentence_length);
        sentences[num_sentences].length = sentence_length;
        sentence_start = sentence_end + 1;
        num_sentences++;
    }

    // Print out the summary
    printf("Summary:\n");
    for (int i = 0; i < num_sentences; i++) {
        printf("%d. %s\n", i + 1, sentences[i].text);
    }

    free(file_contents);
    fclose(input_file);
    return 0;
}