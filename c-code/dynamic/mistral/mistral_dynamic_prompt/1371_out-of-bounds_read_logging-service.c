#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void log_entry(char *entry) {
    FILE *log_file = fopen("log.txt", "a");
    char buffer[BUFFER_SIZE];
    char *buf_ptr = buffer;

    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    snprintf(buf_ptr, BUFFER_SIZE, "%s\n", entry);
    fwrite(buffer, sizeof(char), strlen(buffer), log_file);
    fclose(log_file);
}

int main() {
    char user_input[10];
    printf("Enter a log entry (up to 10 characters): ");
    fgets(user_input, sizeof(user_input), stdin);

    log_entry(user_input);

    printf("Logged: %s\n", user_input);
    return 0;
}
