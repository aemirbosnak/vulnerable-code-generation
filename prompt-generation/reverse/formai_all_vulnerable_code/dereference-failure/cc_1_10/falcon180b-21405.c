//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int line_count;
} Keyword;

void read_keywords(Keyword *keywords, int num_keywords) {
    FILE *fp = fopen("keywords.txt", "r");
    if (fp == NULL) {
        printf("Error opening keywords file.\n");
        exit(1);
    }

    int num_read = 0;
    while (num_read < num_keywords && fscanf(fp, "%s", keywords[num_read].keyword)!= EOF) {
        num_read++;
    }

    fclose(fp);
}

void extract_metadata(FILE *fp, Keyword *keywords, int num_keywords) {
    char line[MAX_LINE_LENGTH];
    int line_num = 1;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int keyword_found = 0;
        for (int i = 0; i < num_keywords; i++) {
            if (strstr(line, keywords[i].keyword)!= NULL) {
                keywords[i].line_count++;
                keyword_found = 1;
                break;
            }
        }

        if (!keyword_found) {
            printf("No keywords found in line %d.\n", line_num);
        }

        line_num++;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <keywords_file>\n", argv[0]);
        return 1;
    }

    FILE *input_fp = fopen(argv[1], "r");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    Keyword keywords[MAX_KEYWORDS];
    int num_keywords = 0;
    read_keywords(keywords, num_keywords);

    if (num_keywords == 0) {
        printf("No keywords found in keywords file.\n");
        return 1;
    }

    extract_metadata(input_fp, keywords, num_keywords);

    fclose(input_fp);
    return 0;
}