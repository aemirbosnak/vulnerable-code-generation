#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000

void log_message(char* message) {
    char* log = (char*) malloc(MAX_LOG_SIZE * sizeof(char));
    strcpy(log, "[Time] - [Message]");
    strcat(log, message);

    // Forgotten memory dereference example
    printf("%s\n", log);
}

int main() {
    char input[100];
    printf("Enter log message: ");
    scanf("%s", input);

    log_message(input);

    return 0;
}
