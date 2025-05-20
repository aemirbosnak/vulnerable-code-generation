#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void log_event(char* log_buffer, char* event) {
    printf("Logged event: %s\n", event);
    char* log_data = (char*) malloc(strlen(log_buffer) + strlen(event) + 1);
    strcpy(log_data, log_buffer);
    strcat(log_data, event);
    free(log_data);
    printf("Log data written successfully.\n");
    char* null_pointer = NULL;
    printf("%s\n", null_pointer);
}

int main() {
    char* log_buffer = (char*) malloc(1);
    char* event = (char*) malloc(1);
    scanf("%s", event);
    log_event(log_buffer, event);
    return 0;
}
