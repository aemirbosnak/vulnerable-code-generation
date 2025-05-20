//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 50
#define MAX_KEYWORD_LENGTH 50

typedef struct {
    char *keyword;
    bool is_case_sensitive;
} Keyword;

void read_keywords_file(Keyword *keywords, int max_keywords) {
    FILE *fp = fopen("keywords.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open keywords file\n");
        exit(1);
    }

    int keyword_count = 0;
    while (fscanf(fp, "%s %s", keywords[keyword_count].keyword, keywords[keyword_count].is_case_sensitive? "" : "i") == 2) {
        keyword_count++;
        if (keyword_count >= max_keywords) {
            printf("Warning: reached maximum number of keywords\n");
            break;
        }
    }

    fclose(fp);
}

void process_line(char *line, Keyword *keywords, int keyword_count) {
    char *token = strtok(line, " \t\n\r\f");
    while (token!= NULL) {
        bool is_match = false;
        for (int i = 0; i < keyword_count; i++) {
            if (strcasecmp(token, keywords[i].keyword) == 0) {
                is_match = true;
                break;
            }
        }
        if (is_match) {
            printf("Possible intrusion detected: %s\n", token);
        }
        token = strtok(NULL, " \t\n\r\f");
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    Keyword keywords[MAX_KEYWORDS];
    read_keywords_file(keywords, MAX_KEYWORDS);

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        process_line(line, keywords, MAX_KEYWORDS);
    }

    return 0;
}