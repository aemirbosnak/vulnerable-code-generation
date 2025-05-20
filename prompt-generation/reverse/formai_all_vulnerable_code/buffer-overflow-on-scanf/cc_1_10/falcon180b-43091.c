//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

char *tokens[MAX_TOKENS];
int num_tokens = 0;

char line[MAX_LINE_LENGTH];
char word[MAX_WORD_LENGTH];

void process_line(char *line) {
    int i = 0;
    char *token;

    token = strtok(line, " ");
    while (token!= NULL) {
        strcpy(tokens[num_tokens], token);
        num_tokens++;
        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    int i;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        process_line(line);
    }

    fclose(file);

    printf("Number of tokens: %d\n", num_tokens);

    for (i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}