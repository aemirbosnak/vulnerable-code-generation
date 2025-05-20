#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void log_message(char *message) {
    static char log[1024];
    strcpy(log, message);
    printf("%s\n", log);
}

int main() {
    char *messages[] = {"Initializing logs...", "Creating new log file...", "Connecting to server...", "Recieving message from client..."};
    char **message_ptr = messages;

    while (*message_ptr) {
        log_message(*message_ptr);
        message_ptr++;
    }

    char *user_input = (char *)malloc(64 * sizeof(char)); // Insufficient memory allocated for subsequent function calls

    printf("Enter a message to log: ");
    scanf("%s", user_input);

    log_message(user_input); // Dereference null pointer

    return 0;
}
