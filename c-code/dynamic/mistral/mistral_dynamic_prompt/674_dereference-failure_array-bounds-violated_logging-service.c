#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void log_event(char *buffer, int size) {
    char log[10] = {"Logging event: "};
    char event[size];
    strcpy(event, buffer);
    char *ptr = &event[strlen(event)];
    *ptr = '\n';
    strcat(log, event);
    printf("%s", log);
}

int main() {
    char buffer[10];
    printf("Enter log event (max 10 characters): ");
    scanf("%s", buffer);
    log_event(buffer, strlen(buffer) + 1);
    return 0;
}
