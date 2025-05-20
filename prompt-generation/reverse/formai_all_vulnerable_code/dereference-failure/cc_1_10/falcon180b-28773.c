//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_LINE 100
#define MAX_HIST 100
#define MAX_ERR 100

typedef struct {
    char *line;
    char *result;
    int err;
} history_t;

history_t history[MAX_HIST];
int hist_idx = 0;

void add_history(char *line, char *result, int err) {
    strcpy(history[hist_idx].line, line);
    strcpy(history[hist_idx].result, result);
    history[hist_idx].err = err;
    hist_idx = (hist_idx + 1) % MAX_HIST;
}

void print_history() {
    printf("History:\n");
    for (int i = 0; i < MAX_HIST; i++) {
        if (history[i].line!= NULL) {
            printf("%d: %s = %s (%d)\n", i + 1, history[i].line, history[i].result, history[i].err);
        }
    }
}

int main() {
    char line[MAX_LINE];
    char *result;
    int err;

    srand(time(NULL));

    while (1) {
        printf("\nEnter an expression:");
        fgets(line, MAX_LINE, stdin);

        result = malloc(MAX_LINE);
        err = 0;

        if (line[0] == '\n') {
            strcpy(result, "");
        } else {
            char *token = strtok(line, " ");
            while (token!= NULL) {
                if (isalpha(token[0])) {
                    printf("Variable '%s' not defined.\n", token);
                    err = 1;
                } else {
                    double num = atof(token);
                    sprintf(result, "%s ", result);
                    sprintf(result, "%s%.2f", result, num);
                }
                token = strtok(NULL, " ");
            }
        }

        add_history(line, result, err);

        printf("\nResult: %s\n", result);

        if (err) {
            printf("\nError: %d\n", err);
        } else {
            printf("\nNo errors.\n");
        }

        free(result);
    }

    return 0;
}