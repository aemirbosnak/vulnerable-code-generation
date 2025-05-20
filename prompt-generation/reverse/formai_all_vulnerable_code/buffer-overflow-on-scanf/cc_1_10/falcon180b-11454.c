//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000

typedef struct {
    int length;
    char sentence[MAX_SENTENCE_LENGTH];
} Sentence;

int main(int argc, char *argv[]) {

    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    Sentence sentences[MAX_SENTENCES];
    int num_sentences = 0, i;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(sentences[num_sentences].sentence, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        sentences[num_sentences].length = strlen(sentences[num_sentences].sentence);
        num_sentences++;
    }

    fclose(input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (i = 0; i < num_sentences; i++) {
        fprintf(output_file, "%d %s\n", sentences[i].length, sentences[i].sentence);
    }

    fclose(output_file);

    return 0;
}