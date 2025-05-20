//Falcon-180B DATASET v1.0 Category: Text processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_WORD_LENGTH], output_filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    int i, j, word_count = 0;
    char *words[MAX_WORDS];

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                words[word_count] = (char *) malloc(MAX_WORD_LENGTH);
                strcpy(words[word_count], "");
                while (isalpha(line[i])) {
                    strcat(words[word_count], line[i]);
                    i++;
                }
                words[word_count][strlen(words[word_count]) - 1] = '\0';
                word_count++;
            }
        }
    }

    for (i = 0; i < word_count; i++) {
        fprintf(output_file, "%s\n", words[i]);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}