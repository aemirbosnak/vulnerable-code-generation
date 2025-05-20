//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 10
#define KEYWORD_DELIMITER ";"

typedef struct {
    char *name;
    int line_number;
} keyword_t;

int main(int argc, char **argv) {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *keywords[MAX_NUM_KEYWORDS];
    int num_keywords = 0;
    int line_number = 0;
    keyword_t *results = NULL;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    printf("Enter keywords (separated by %s): ", KEYWORD_DELIMITER);
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        keywords[num_keywords] = strdup(line);
        num_keywords++;
    }

    results = (keyword_t *)malloc(num_keywords * sizeof(keyword_t));
    if (results == NULL) {
        printf("Error: could not allocate memory.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_number++;
        char *token = strtok(line, " \t\n\r\f");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_keywords; i++) {
                if (strcasecmp(token, keywords[i]) == 0) {
                    results[i].name = strdup(keywords[i]);
                    results[i].line_number = line_number;
                    break;
                }
            }
            if (i == num_keywords) {
                printf("Keyword not found: %s\n", token);
            }
            token = strtok(NULL, " \t\n\r\f");
        }
    }

    fclose(fp);

    printf("Search results:\n");
    for (int i = 0; i < num_keywords; i++) {
        if (results[i].name!= NULL) {
            printf("%s: %s\n", results[i].name, filename);
        } else {
            printf("%s: not found\n", keywords[i]);
        }
    }

    for (int i = 0; i < num_keywords; i++) {
        free(results[i].name);
        free(keywords[i]);
    }
    free(results);

    return 0;
}