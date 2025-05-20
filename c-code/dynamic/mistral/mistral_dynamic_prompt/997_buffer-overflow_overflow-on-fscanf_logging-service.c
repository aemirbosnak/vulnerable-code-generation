#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100
#define LOG_FILE "logs.txt"

void log_message(char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Failed to open log file");
        return;
    }

    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    printf("Logging service started on %s\n", asctime(timeinfo));

    while (1) {
        printf("Enter a log message: ");
        fgets(input, BUFFER_SIZE, stdin);

        log_message(input);

        // Intentionally causing buffer overflow on fscanf by providing more than BUFFER_SIZE characters
        if (fscanf(stdin, "%s", input) >= BUFFER_SIZE) {
            printf("Buffer overflow detected. Terminating the service...\n");
            break;
        }
    }

    printf("Logging service terminated.\n");

    return 0;
}
