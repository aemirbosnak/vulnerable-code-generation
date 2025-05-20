#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int main(int argc, char **argv) {
    char buffer[10];
    char *username, *log_message;
    int i;

    printf("Logging Service: Enter your username:\n");
    fgets(buffer, sizeof(buffer), stdin);
    username = malloc(strlen(buffer) + 1);
    strcpy(username, buffer);

    printf("Logging Service: Enter log message (up to 1000 characters):\n");
    fgets(buffer, sizeof(buffer), stdin);
    log_message = malloc(1000);
    strcpy(log_message, buffer);

    // Excessive memory allocation and no bounds checking on fgets.
    // The goal is to create a buffer overflow condition.
    char *extra_memory = malloc(1000000);

    // Vulnerable function call where the input from fgets can overwrite the stack.
    sprintf(extra_memory, "%s %s\n", username, log_message);

    printf("Logged: %s\n", log_message);

    return 0;
}
