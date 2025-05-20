#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char log[MAX_LOG_SIZE];
} LogEntry;

void write_log(LogEntry *entry, const char *message) {
    int i = 0;
    while (message[i] != '\0') {
        entry->log[i] = message[i];
        i++;
    }
}

int main() {
    LogEntry logs[10];
    const char *malicious_message = "This is a malicious log message that will cause an array bounds violation.";

    // Simulate writing logs
    for (int j = 0; j < 10; j++) {
        write_log(&logs[j], malicious_message);
    }

    // Intentionally access out-of-bounds memory to demonstrate vulnerability
    printf("Log entry 10: %s\n", logs[9].log);

    return 0;
}
