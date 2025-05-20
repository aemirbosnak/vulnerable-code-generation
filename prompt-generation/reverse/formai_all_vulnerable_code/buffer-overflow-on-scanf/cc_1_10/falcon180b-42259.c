//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1000

char *tokens[MAX_TOKENS];
int num_tokens = 0;

void read_file(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (i >= MAX_TOKENS) {
                printf("Error: Too many tokens on line %d\n", num_tokens + 1);
                exit(1);
            }
            tokens[i] = strdup(token);
            i++;
            token = strtok(NULL, " ");
        }
        num_tokens++;
    }
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    read_file(fp);
    fclose(fp);

    printf("Enter output filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not create output file\n");
        exit(1);
    }

    for (int i = 0; i < num_tokens; i++) {
        fprintf(fp, "%s ", tokens[i]);
    }
    fprintf(fp, "\n");

    fclose(fp);
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    return 0;
}