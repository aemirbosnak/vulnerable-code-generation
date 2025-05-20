//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000

typedef struct sentence {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main() {
    FILE *input_file, *output_file;
    char input_filename[50], output_filename[50];
    Sentence sentences[MAX_SENTENCES];
    int num_sentences = 0;

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read sentences from input file
    while (fgets(sentences[num_sentences].text, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        sentences[num_sentences].length = strlen(sentences[num_sentences].text);
        num_sentences++;
        if (num_sentences >= MAX_SENTENCES) {
            printf("Error: Too many sentences.\n");
            exit(1);
        }
    }

    // Close input file
    fclose(input_file);

    // Prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Generate summary
    int total_sentence_length = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (total_sentence_length + sentences[i].length <= MAX_SENTENCE_LENGTH * 5) {
            fprintf(output_file, "%s ", sentences[i].text);
            total_sentence_length += sentences[i].length + 1;
        }
    }

    // Close output file
    fclose(output_file);

    return 0;
}