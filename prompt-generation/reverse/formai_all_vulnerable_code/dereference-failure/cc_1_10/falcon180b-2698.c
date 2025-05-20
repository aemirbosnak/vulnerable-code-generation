//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_HIST 10

char input[MAX_LEN];
char history[MAX_HIST][MAX_LEN];
int pos = 0;
int hist_pos = 0;
int hist_size = 0;

void add_to_history(char *str) {
    strcpy(history[hist_size], str);
    hist_size++;
    if (hist_size > MAX_HIST) {
        hist_size = MAX_HIST;
    }
}

void print_history() {
    int i;
    for (i = 0; i < hist_size; i++) {
        printf("%s\n", history[i]);
    }
}

void clear() {
    pos = 0;
    memset(input, 0, MAX_LEN);
}

void backspace() {
    if (pos > 0) {
        pos--;
        input[pos] = '\0';
    }
}

void calculate() {
    int i;
    char *endptr;
    double num;

    if (strlen(input) == 0) {
        return;
    }

    num = strtod(input, &endptr);
    if (*endptr == '\0') {
        printf("Result: %g\n", num);
        add_to_history(input);
        clear();
    } else {
        printf("Error: Invalid input\n");
        clear();
    }
}

int main() {
    char ch;
    int i;

    printf("Welcome to the Scientific Calculator!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_LEN, stdin);

        for (i = 0; i < strlen(input); i++) {
            if (input[i] == '\n') {
                input[i] = '\0';
            }
        }

        if (strcmp(input, "q") == 0) {
            break;
        } else if (strcmp(input, "h") == 0) {
            print_history();
        } else if (strcmp(input, "c") == 0) {
            clear();
        } else if (strcmp(input, "b") == 0) {
            backspace();
        } else if (strcmp(input, "=") == 0) {
            calculate();
        } else {
            add_to_history(input);
            clear();
        }
    }

    return 0;
}