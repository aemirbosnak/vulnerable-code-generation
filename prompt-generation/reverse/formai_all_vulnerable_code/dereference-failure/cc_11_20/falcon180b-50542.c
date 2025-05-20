//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 256
#define MAX_TOKENS 1024

typedef struct {
    char *text;
    int length;
} Token;

int main(int argc, char *argv[])
{
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char token[MAX_TOKEN_LENGTH];
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;
    int i;

    // Get input and output file names from command line arguments
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Read input file line by line and tokenize
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        num_tokens = 0;
        strcpy(token, "");
        for (i = 0; i < strlen(line); i++) {
            if (isspace(line[i]) || line[i] == '<') {
                // End of token reached, add it to the list
                if (strlen(token) > 0) {
                    tokens[num_tokens].text = strdup(token);
                    tokens[num_tokens].length = strlen(token);
                    num_tokens++;
                }
                strcpy(token, "");
            } else {
                // Append character to token
                strncat(token, &line[i], 1);
            }
        }
        // Add last token to the list
        if (strlen(token) > 0) {
            tokens[num_tokens].text = strdup(token);
            tokens[num_tokens].length = strlen(token);
            num_tokens++;
        }
    }

    // Write formatted HTML to output file
    fprintf(output_file, "<!DOCTYPE html>\n<html>\n<head>\n<meta charset=\"UTF-8\">\n<title>");
    for (i = 0; i < num_tokens; i++) {
        fprintf(output_file, "%s", tokens[i].text);
    }
    fprintf(output_file, "</title>\n</head>\n<body>\n");
    for (i = 0; i < num_tokens; i++) {
        if (i == 0 && strcmp(tokens[i].text, "html") == 0) {
            fprintf(output_file, "<%s", tokens[i].text);
        } else if (i > 0 && strcmp(tokens[i].text, "body") == 0) {
            fprintf(output_file, ">\n");
        } else {
            fprintf(output_file, " %s", tokens[i].text);
        }
    }
    fprintf(output_file, "</body>\n</html>");

    // Close files and exit
    fclose(input_file);
    fclose(output_file);
    return 0;
}