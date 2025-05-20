//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_LINE_LENGTH 1000

char *tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *token) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: too many tokens\n");
        exit(1);
    }
    tokens[num_tokens++] = token;
}

int main() {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    char *filename;
    int i;

    printf("Enter the filename: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error: couldn't open file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        int line_num = 1;
        char *ptr = line;

        while (*ptr!= '\0') {
            if (isspace(*ptr)) {
                line[line_num - 1] = '\0';
                add_token(line + line_num);
                line_num += strlen(line + line_num) + 1;
            } else if (isalpha(*ptr)) {
                line[line_num - 1] = '\0';
                add_token(line + line_num);
                line_num += strlen(line + line_num) + 1;
            } else if (isdigit(*ptr)) {
                line[line_num - 1] = '\0';
                add_token(line + line_num);
                line_num += strlen(line + line_num) + 1;
            } else {
                line[line_num - 1] = '\0';
                add_token(line + line_num);
                line_num += strlen(line + line_num) + 1;
            }
            ptr++;
        }
    }

    fclose(input_file);

    printf("Number of tokens: %d\n", num_tokens);

    for (i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}