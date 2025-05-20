#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 10
#define LOG_SIZE 2048

typedef struct {
    char data[LOG_SIZE];
    time_t timestamp;
} LogEntry;

LogEntry logs[MAX_LOGS];
int logs_count = 0;

void log(char* message) {
    if (logs_count >= MAX_LOGS) {
        printf("Log buffer is full.\n");
        return;
    }

    strcpy(logs[logs_count].data, message);
    logs[logs_count].timestamp = time(NULL);
    logs_count++;
}

void print_logs() {
    for (int i = 0; i < logs_count; i++) {
        printf("Log #%d: %s\n", i, logs[i].data);
    }
}

int main(int argc, char* argv[]) {
    char* example_log = malloc(LOG_SIZE * sizeof(char));
    if (!example_log) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Invalid pointer dereference
    printf("%s\n", example_log[-1]);

    log(argv[0]);
    log("This is a dummy log entry.");

    printf("\nLogged entries:\n");
    print_logs();

    free(example_log);

    return 0;
}
