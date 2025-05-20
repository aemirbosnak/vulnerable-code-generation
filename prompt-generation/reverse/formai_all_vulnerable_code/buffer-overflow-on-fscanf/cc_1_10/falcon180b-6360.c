//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 20

typedef struct {
    char *keyword;
    int count;
} Keyword;

void read_keywords(Keyword *keywords, int num_keywords) {
    FILE *file = fopen("keywords.txt", "r");
    if (file == NULL) {
        printf("Error: could not open keywords.txt\n");
        exit(1);
    }
    for (int i = 0; i < num_keywords; i++) {
        char keyword[MAX_KEYWORD_LENGTH];
        if (fscanf(file, "%s", keyword)!= 1) {
            printf("Error: invalid keyword in keywords.txt\n");
            exit(1);
        }
        keywords[i].keyword = strdup(keyword);
        keywords[i].count = 0;
    }
    fclose(file);
}

void free_keywords(Keyword *keywords, int num_keywords) {
    for (int i = 0; i < num_keywords; i++) {
        free(keywords[i].keyword);
    }
    free(keywords);
}

bool is_keyword(char *line, Keyword *keywords, int num_keywords) {
    for (int i = 0; i < num_keywords; i++) {
        if (strstr(line, keywords[i].keyword)!= NULL) {
            keywords[i].count++;
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: could not open log file\n");
        exit(1);
    }
    Keyword keywords[MAX_KEYWORDS];
    int num_keywords = 0;
    read_keywords(keywords, MAX_KEYWORDS);
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        if (is_keyword(line, keywords, num_keywords)) {
            printf("Possible intrusion detected: %s\n", line);
        }
    }
    free_keywords(keywords, num_keywords);
    fclose(log_file);
    return 0;
}