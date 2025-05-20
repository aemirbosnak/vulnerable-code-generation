//Falcon-180B DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_LENGTH], output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    WordCount words[1000];
    int num_words = 0;
    int i, j;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isspace(line[i])) {
                line[i] = '\0';
            }
        }

        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                for (j = 0; j < num_words; j++) {
                    if (strcmp(words[j].word, line) == 0) {
                        words[j].count++;
                        break;
                    }
                }
                if (j == num_words) {
                    strcpy(words[num_words].word, line);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
        }
    }

    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}