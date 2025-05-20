//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_HISTORY 10

typedef struct {
    int line_number;
    char line[MAX_LINE];
} History_Entry;

History_Entry history[MAX_HISTORY];
int history_index = 0;

void print_history() {
    printf("Time Travel History:\n");
    for (int i = 0; i < history_index; i++) {
        printf("%d: %s", history[i].line_number, history[i].line);
    }
    printf("\n");
}

void travel_back(int steps) {
    if (steps > history_index) {
        printf("Error: Time travel beyond the available history.\n");
        return;
    }

    printf("Time travel to line %d: %s\n", history[history_index - steps - 1].line_number, history[history_index - steps - 1].line);
    history_index -= steps;
}

int main() {
    int current_line_number = 0;
    char current_line[MAX_LINE];
    char command[MAX_LINE];

    while (1) {
        printf("Line %d > ", current_line_number);
        fgets(current_line, MAX_LINE, stdin);
        current_line[strlen(current_line) - 1] = '\0';

        if (strcmp(current_line, "quit") == 0) {
            break;
        }

        if (strcmp(current_line, "history") == 0) {
            print_history();
            continue;
        }

        if (strcmp(current_line, "time_travel") == 0) {
            sscanf(current_line, "time_travel %s", command);
            int steps = atoi(command);
            travel_back(steps);
            continue;
        }

        strcpy(history[history_index].line, current_line);
        history_index++;

        if (history_index >= MAX_HISTORY) {
            printf("Error: Maximum history size reached.\n");
            history_index--;
            continue;
        }

        printf("Executing line %d: %s\n", current_line_number, current_line);
        current_line_number++;
    }

    return 0;
}