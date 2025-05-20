//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    int count;
} Keyword;

typedef struct {
    Keyword *keywords;
    int num_keywords;
} LogAnalyzer;

void log_analyzer_init(LogAnalyzer *analyzer) {
    analyzer->keywords = NULL;
    analyzer->num_keywords = 0;
}

void log_analyzer_add_keyword(LogAnalyzer *analyzer, char *key) {
    Keyword *keyword = malloc(sizeof(Keyword));
    keyword->key = strdup(key);
    keyword->count = 0;
    analyzer->keywords = realloc(analyzer->keywords, sizeof(Keyword) * (analyzer->num_keywords + 1));
    analyzer->keywords[analyzer->num_keywords++] = *keyword;
    free(keyword);
}

void log_analyzer_analyze_line(LogAnalyzer *analyzer, char *line) {
    char *token;
    int i;

    token = strtok(line, " ");
    while (token!= NULL) {
        for (i = 0; i < analyzer->num_keywords; i++) {
            if (strcmp(token, analyzer->keywords[i].key) == 0) {
                analyzer->keywords[i].count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}

void log_analyzer_print_results(LogAnalyzer *analyzer) {
    int i;

    for (i = 0; i < analyzer->num_keywords; i++) {
        printf("%s: %d\n", analyzer->keywords[i].key, analyzer->keywords[i].count);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *filename = "example.log";
    FILE *file;
    LogAnalyzer analyzer;

    log_analyzer_init(&analyzer);
    log_analyzer_add_keyword(&analyzer, "error");
    log_analyzer_add_keyword(&analyzer, "warning");

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        log_analyzer_analyze_line(&analyzer, line);
    }

    fclose(file);
    log_analyzer_print_results(&analyzer);

    return 0;
}