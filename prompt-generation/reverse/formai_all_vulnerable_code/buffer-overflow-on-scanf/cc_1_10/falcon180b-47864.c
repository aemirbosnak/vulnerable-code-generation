//Falcon-180B DATASET v1.0 Category: Text processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *value;
    int length;
} Token;

int main() {
    FILE *input_file, *output_file;
    char input_file_name[50], output_file_name[50];
    char line[1000];
    int num_tokens = 0, i;
    Token tokens[MAX_TOKENS];

    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    output_file = fopen(output_file_name, "w");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    while (fgets(line, 1000, input_file)!= NULL) {
        num_tokens = 0;
        char *token_start = line;
        char *token_end = line;

        while (num_tokens < MAX_TOKENS && *token_end!= '\0') {
            if (isspace(*token_end)) {
                *token_end = '\0';
                num_tokens++;
                token_end++;
            } else {
                token_end++;
            }
        }

        for (i = 0; i < num_tokens; i++) {
            tokens[i].value = token_start;
            tokens[i].length = token_end - token_start;

            fprintf(output_file, "%s\n", tokens[i].value);

            token_start = token_end;
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}