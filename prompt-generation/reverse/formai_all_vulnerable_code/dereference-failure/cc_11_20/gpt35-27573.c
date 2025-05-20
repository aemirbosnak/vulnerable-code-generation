//FormAI DATASET v1.0 Category: File handling ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_SIZE], output_filename[MAX_SIZE], buffer[MAX_SIZE], token[MAX_SIZE];
    int word_count = 0, char_count = 0, sentence_count = 0;
    double avg_word_length = 0, avg_sentence_length = 0;
    int i, j, length, is_word, is_num, is_sentence;

    // Prompt the user for input and output filenames
    printf("Enter the input filename: ");
    scanf("%s", input_filename);
    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Process each line in the input file
    while (fgets(buffer, MAX_SIZE, input_file) != NULL) {
        length = strlen(buffer);
        is_sentence = 0;

        // Analyze each character in the line
        for (i = 0; i < length; i++) {
            is_word = 0;
            is_num = 0;

            // Check if character is a letter or digit
            if (isalpha(buffer[i]) || isdigit(buffer[i])) {
                is_word = 1;

                // Check if character is a number
                if (isdigit(buffer[i])) {
                    is_num = 1;
                }

                // Store character in token
                token[char_count++] = buffer[i];
            }
            // Check if character is a punctuation mark
            else if (ispunct(buffer[i])) {
                // Check if character is end of sentence punctuation
                if (buffer[i] == '.' || buffer[i] == '?' || buffer[i] == '!') {
                    is_sentence = 1;
                }

                // Increment sentence count
                if (is_sentence) {
                    sentence_count++;

                    // Add to average sentence length
                    avg_sentence_length += word_count;
                    word_count = 0;
                }

                // Add to average word length
                if (!is_num) {
                    avg_word_length += char_count - 1;
                }

                // Reset char_count
                char_count = 0;
            }
            // Check if character is whitespace
            else if (isspace(buffer[i])) {
                if (is_word) {
                    word_count++;
                }

                // Add to average word length
                if (!is_num) {
                    avg_word_length += char_count;
                }

                // Reset char_count
                char_count = 0;
            }
        }
    }

    // Calculate final average word length
    avg_word_length /= word_count;

    // Calculate final average sentence length
    avg_sentence_length /= sentence_count;

    // Write statistics to output file
    fprintf(output_file, "Word count: %d\n", word_count);
    fprintf(output_file, "Average word length: %.2f\n", avg_word_length);
    fprintf(output_file, "Sentence count: %d\n", sentence_count);
    fprintf(output_file, "Average sentence length: %.2f\n", avg_sentence_length);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}