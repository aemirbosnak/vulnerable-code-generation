//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_TOKENS 100

typedef struct {
    char *text;
    int length;
} Token;

char *read_line(FILE *file) {
    char *line = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading line.\n");
        exit(1);
    }
    return line;
}

void split_line(char *line, Token *tokens) {
    int i = 0;
    char *word = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    char *delimiters = " \t\r\n\a";
    char *p = strtok(line, delimiters);
    while (p!= NULL && i < MAX_TOKENS) {
        strcpy(word, p);
        tokens[i].text = word;
        tokens[i].length = strlen(word);
        i++;
        p = strtok(NULL, delimiters);
    }
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char *line = read_line(file);
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;
    while (line!= NULL) {
        split_line(line, tokens);
        for (int i = 0; i < num_tokens; i++) {
            if (strcmp(tokens[i].text, "Name") == 0) {
                printf("Name: %s\n", tokens[i+1].text);
            } else if (strcmp(tokens[i].text, "Email") == 0) {
                printf("Email: %s\n", tokens[i+1].text);
            } else if (strcmp(tokens[i].text, "Phone") == 0) {
                printf("Phone: %s\n", tokens[i+1].text);
            } else if (strcmp(tokens[i].text, "Education") == 0) {
                printf("Education:\n");
                while (strcmp(tokens[i+1].text, "Experience")!= 0) {
                    printf("\t%s\n", tokens[i+1].text);
                    i++;
                }
            } else if (strcmp(tokens[i].text, "Experience") == 0) {
                printf("Experience:\n");
                while (strcmp(tokens[i+1].text, "Skills")!= 0) {
                    printf("\t%s\n", tokens[i+1].text);
                    i++;
                }
            } else if (strcmp(tokens[i].text, "Skills") == 0) {
                printf("Skills:\n");
                while (i < num_tokens) {
                    printf("\t%s\n", tokens[i].text);
                    i++;
                }
            }
        }
        num_tokens = 0;
        line = read_line(file);
    }
    fclose(file);
    return 0;
}