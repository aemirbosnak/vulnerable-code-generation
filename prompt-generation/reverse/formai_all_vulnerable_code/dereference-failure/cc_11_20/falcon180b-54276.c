//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 20

typedef struct {
    char *keyword;
    int line_number;
} Keyword;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    int num_keywords = 0;
    Keyword keywords[MAX_KEYWORDS];

    char *keywords_list = "int float double char string if else while for return";
    char *token = strtok(keywords_list, " ");
    while (token!= NULL && num_keywords < MAX_KEYWORDS) {
        strcpy(keywords[num_keywords].keyword, token);
        num_keywords++;
        token = strtok(NULL, " ");
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int keyword_index = -1;
        for (int i = 0; i < num_keywords; i++) {
            char *keyword = keywords[i].keyword;
            int keyword_length = strlen(keyword);
            if (strncmp(line, keyword, keyword_length) == 0) {
                keyword_index = i;
                break;
            }
        }

        if (keyword_index >= 0) {
            keywords[keyword_index].line_number = line_number;
        }

        line_number++;
    }

    fclose(file);

    printf("Keywords found:\n");
    for (int i = 0; i < num_keywords; i++) {
        if (keywords[i].line_number!= 0) {
            printf("%s: %d\n", keywords[i].keyword, keywords[i].line_number);
        }
    }

    return 0;
}