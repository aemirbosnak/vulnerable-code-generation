//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10

typedef struct {
    char *keyword;
    int (*callback)(char *data);
} keyword_t;

int count_callback(char *data) {
    int count = 0;
    char *token;

    token = strtok(data, " ");
    while (token!= NULL) {
        if (strcasecmp(token, "attack") == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    return count;
}

int alert_callback(char *data) {
    printf("Possible attack detected: %s\n", data);
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    keyword_t keywords[] = {{"attack", count_callback}, {"alert", alert_callback}};

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_number++;
        int i;
        for (i = 0; i < MAX_KEYWORDS; i++) {
            if (keywords[i].callback!= NULL) {
                int result = keywords[i].callback(line);
                if (result!= 0) {
                    printf("Line %d: %s\n", line_number, line);
                }
            }
        }
    }

    fclose(fp);
    return 0;
}