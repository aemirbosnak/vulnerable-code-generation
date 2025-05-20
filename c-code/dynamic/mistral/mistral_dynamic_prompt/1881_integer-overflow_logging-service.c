#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void log_message(char *message, int severity) {
    char log_file[256];
    static int log_file_counter = 0;

    sprintf(log_file, "logs/log_%d.txt", log_file_counter);
    FILE *file = fopen(log_file, "a+");

    if (file == NULL) {
        printf("Error: Unable to open log file.\n");
        return;
    }

    fprintf(file, "%s [Severity: %d]\n", message, severity);
    fclose(file);

    log_file_counter++;
}

int main(int argc, char *argv[]) {
    int num_log_messages = atoi(argv[1]);
    int message_size = atoi(argv[2]);
    int severity;
    char *message;

    message = (char *) malloc(message_size * sizeof(char));

    for (int i = 0; i < num_log_messages; i++) {
        printf("Enter message [%d]: ", i + 1);
        scanf("%s", message);

        printf("Enter severity (1-5): ");
        scanf("%d", &severity);

        log_message(message, severity);

        // Intentional integer overflow
        message[message_size] = 'A';
    }

    free(message);

    return 0;
}
