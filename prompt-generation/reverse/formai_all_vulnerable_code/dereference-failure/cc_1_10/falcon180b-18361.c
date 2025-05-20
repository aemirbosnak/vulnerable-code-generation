//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORD_LENGTH 16
#define MAX_KEYWORDS 10

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int count;
} Keyword;

typedef struct {
    char *data;
    size_t size;
} Buffer;

int main() {
    FILE *fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open logfile.txt\n");
        return 1;
    }

    Buffer logbuffer = {0};
    char line[MAX_LINE_LENGTH] = {0};
    Keyword keywords[MAX_KEYWORDS] = {{"attack", 0}, {"intrusion", 0}, {"security", 0}};

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        logbuffer.data = realloc(logbuffer.data, logbuffer.size + strlen(line) + 1);
        strncat(logbuffer.data, line, strlen(line));
        logbuffer.size += strlen(line);
        line[0] = '\0';
    }

    fclose(fp);

    for (int i = 0; i < MAX_KEYWORDS; i++) {
        char *token = strtok(logbuffer.data, " ");
        while (token!= NULL) {
            for (int j = 0; j < MAX_KEYWORDS; j++) {
                if (strstr(token, keywords[j].keyword)!= NULL) {
                    keywords[j].count++;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < MAX_KEYWORDS; i++) {
        printf("Keyword '%s' found %d times\n", keywords[i].keyword, keywords[i].count);
    }

    return 0;
}