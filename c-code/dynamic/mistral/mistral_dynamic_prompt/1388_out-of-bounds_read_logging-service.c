#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void log_message(char *message, int log_index) {
    FILE *log_file;
    log_file = fopen("log.txt", "a");
    if (log_file != NULL) {
        char log_line[BUFFER_SIZE];
        sprintf(log_line, "%d: %s\n", log_index, message);
        fwrite(log_line, strlen(log_line), 1, log_file);
        fclose(log_file);
    } else {
        printf("Error: Unable to open log file\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    char user_input[BUFFER_SIZE];
    strcpy(user_input, argv[1]);
    int len = strlen(user_input);

    char *token = strtok(user_input, " ");
    while (token != NULL) {
        log_message(token, __LINE__);
        token = strtok(NULL, " ");
    }

    return 0;
}
