#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LEN 1024

void log_entry(char* message) {
    char log_data[MAX_LOG_LEN];
    memset(log_data, 0, sizeof(log_data));

    int result;
    result = snprintf(log_data, sizeof(log_data), "%s\n", message);
    if (result >= sizeof(log_data)) {
        fprintf(stderr, "Error: log_entry() buffer overflow\n");
    }

    FILE* log_file = fopen("logs.log", "a");
    if (log_file != NULL) {
        fprintf(log_file, "%s", log_data);
        fclose(log_file);
    } else {
        fprintf(stderr, "Error: Could not open log file\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_message>\n", argv[0]);
        return 1;
    }

    log_entry(argv[1]);
    return 0;
}
