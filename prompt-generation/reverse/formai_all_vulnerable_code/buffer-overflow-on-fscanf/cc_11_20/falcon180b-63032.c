//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 50

typedef struct {
    char *keyword;
    int count;
} Keyword;

int main(int argc, char *argv[]) {
    FILE *input_file;
    char input_line[MAX_LINE_LENGTH];
    char *token;
    int num_keywords = 0;
    Keyword *keywords = malloc(MAX_NUM_KEYWORDS * sizeof(Keyword));

    if (argc!= 3) {
        printf("Usage: %s <input_file> <keywords_file>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE *keywords_file = fopen(argv[2], "r");
    if (keywords_file == NULL) {
        printf("Error: Could not open keywords file.\n");
        exit(1);
    }

    while (fscanf(keywords_file, "%s", input_line)!= EOF) {
        if (num_keywords >= MAX_NUM_KEYWORDS) {
            printf("Error: Too many keywords specified.\n");
            exit(1);
        }
        keywords[num_keywords].keyword = strdup(input_line);
        num_keywords++;
    }
    fclose(keywords_file);

    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        token = strtok(input_line, " \t\n\r\f\v");
        while (token!= NULL) {
            for (int i = 0; i < num_keywords; i++) {
                if (strcmp(token, keywords[i].keyword) == 0) {
                    keywords[i].count++;
                    break;
                }
            }
            token = strtok(NULL, " \t\n\r\f\v");
        }
    }

    for (int i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }

    fclose(input_file);
    for (int i = 0; i < num_keywords; i++) {
        free(keywords[i].keyword);
    }
    free(keywords);

    return 0;
}