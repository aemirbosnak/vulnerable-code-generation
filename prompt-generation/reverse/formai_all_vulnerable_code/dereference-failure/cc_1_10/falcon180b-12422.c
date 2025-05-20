//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 100
#define MAX_HISTORY_SIZE 10

typedef struct {
    char *input;
    double result;
} HistoryEntry;

int history_size;
int history_index;
HistoryEntry history[MAX_HISTORY_SIZE];

void init_history() {
    history_size = 0;
    history_index = -1;
}

void add_history(char *input, double result) {
    if (history_size >= MAX_HISTORY_SIZE) {
        history_size--;
        history_index--;
    }
    history[++history_size] = (HistoryEntry) {
       .input = strdup(input),
       .result = result
    };
    history_index++;
}

void print_history() {
    printf("History:\n");
    for (int i = history_index; i >= 0 && i < history_size; i--) {
        printf("%d. %s = %f\n", i+1, history[i].input, history[i].result);
    }
}

char *read_line() {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t read;

    getline(&line, &capacity, stdin);
    if (line[strcspn(line, "\n")]!= '\0') {
        fprintf(stderr, "Error: Input too long.\n");
        exit(1);
    }

    return line;
}

int main() {
    init_history();

    while (1) {
        printf("> ");
        char *input = read_line();

        if (strcmp(input, "q") == 0) {
            break;
        } else if (strcmp(input, "h") == 0) {
            print_history();
        } else {
            char *endptr;
            double num1 = strtod(input, &endptr);

            if (*endptr!= '\0') {
                fprintf(stderr, "Error: Invalid input.\n");
            } else {
                printf("Result: %f\n", num1);
                add_history(input, num1);
            }
        }
    }

    return 0;
}