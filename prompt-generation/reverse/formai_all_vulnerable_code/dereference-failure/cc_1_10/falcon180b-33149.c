//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 50

typedef struct {
    char *keyword;
    int (*callback)(char *data);
} keyword_t;

int count_callback(char *data) {
    int count = 0;
    char *token;

    token = strtok(data, " ");
    while (token!= NULL) {
        if (strcmp(token, "attack") == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    return count;
}

int alarm_callback(char *data) {
    printf("Possible intrusion detected!\n");
    return 0;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *data = NULL;
    size_t len = 0;
    ssize_t read;
    keyword_t keywords[] = {{"attack", count_callback}, {"intrusion", alarm_callback}};

    fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        data = realloc(data, len + strlen(line) + 1);
        if (data == NULL) {
            printf("Memory error.\n");
            exit(1);
        }
        strcat(data, line);
    }

    fclose(fp);

    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (keywords[i].keyword!= NULL) {
            keywords[i].callback(data);
        }
    }

    free(data);
    return 0;
}