//FormAI DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[MAX_BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log-file-path>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
        exit(1);
    }

    printf("Welcome, dear Watson. Today, we shall analyze this log file:\n\n");

    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        int i, j, num_colons = 0;
        char *level, *timestamp, *message;

        // Find the first colon and split the line into three parts
        for (i = 0; i < strlen(buffer) && num_colons < 2; i++) {
            if (buffer[i] == ':') {
                num_colons++;
            }
        }
        if (num_colons < 2) {
            printf("Invalid log line: %s\n", buffer);
            continue;
        }

        level = strndup(buffer, i - 1);
        timestamp = strndup(buffer + i + 2, 19);
        message = strdup(buffer + i + 22);

        // Remove trailing newline characters
        for (j = strlen(message) - 1; j >= 0 && (message[j] == '\n' || message[j] == '\r'); j--) {
            message[j] = '\0';
        }

        printf("%s [%s]: %s\n", timestamp, level, message);

        free(level);
        free(timestamp);
        free(message);
    }

    printf("\nThat concludes our analysis, Watson. The game's afoot!\n");

    fclose(file);
    return 0;
}