#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 100

typedef struct {
    char *message;
    time_t timestamp;
} LogEntry;

LogEntry logs[MAX_LOGS];
int current_log = 0;

void append_log(char *message) {
    logs[current_log].message = message;
    current_log++;
}

void print_logs() {
    for (int i = 0; i < current_log; i++) {
        printf("Log %d: %s\n", i, logs[i].message);
    }
}

int main() {
    char input[1024];
    while (1) {
        printf("Enter log message (or q to quit): ");
        fgets(input, 1024, stdin);
        if (strcmp(input, "q\n") == 0) break;
        append_log(input);
    }

    printf("\n");
    print_logs();

    for (int i = 0; i < current_log; i++) {
        free(logs[i].message);
    }

    return 0;
}
