//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 20

typedef struct {
    char keyword[MAX_LINE_LENGTH];
    int count;
} Keyword;

void read_keywords(Keyword* keywords, int num_keywords) {
    for (int i = 0; i < num_keywords; i++) {
        printf("Enter keyword %d: ", i + 1);
        scanf("%s", keywords[i].keyword);
    }
}

void count_keywords(char* line, Keyword* keywords, int num_keywords) {
    char* token = strtok(line, " ");
    while (token!= NULL) {
        for (int i = 0; i < num_keywords; i++) {
            if (strcmp(token, keywords[i].keyword) == 0) {
                keywords[i].count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}

void print_keyword_counts(Keyword* keywords, int num_keywords) {
    printf("Keyword Counts:\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    Keyword keywords[MAX_NUM_KEYWORDS];
    int num_keywords = 0;

    printf("Enter the number of keywords to count: ");
    scanf("%d", &num_keywords);

    printf("Enter the keywords to count (separated by spaces): ");
    read_keywords(keywords, num_keywords);

    FILE* logfile = fopen("logfile.txt", "r");

    if (logfile == NULL) {
        printf("Error: logfile.txt not found.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, logfile)!= NULL) {
        count_keywords(line, keywords, num_keywords);
    }

    fclose(logfile);

    print_keyword_counts(keywords, num_keywords);

    return 0;
}