//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_SIZE 100

typedef struct {
    char *token;
    int token_size;
} Token;

int main() {
    char input_file[MAX_TOKEN_SIZE];
    char output_file[MAX_TOKEN_SIZE];
    FILE *input_fp;
    FILE *output_fp;
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;

    // Get input and output file names from command line arguments
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file for reading
    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read input file and tokenize
    char line[MAX_TOKEN_SIZE];
    while (fgets(line, MAX_TOKEN_SIZE, input_fp)!= NULL) {
        int i = 0;
        while (i < strlen(line)) {
            // Check for whitespace
            if (isspace(line[i])) {
                // End of token
                line[i] = '\0';
                tokens[num_tokens].token = &line[0];
                tokens[num_tokens].token_size = i;
                num_tokens++;
                i++;
            } else {
                // Continue token
                i++;
            }
        }
    }

    // Close input file
    fclose(input_fp);

    // Open output file for writing
    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write tokenized data to output file
    for (int i = 0; i < num_tokens; i++) {
        fprintf(output_fp, "%s\n", tokens[i].token);
    }

    // Close output file
    fclose(output_fp);

    return 0;
}