#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void log_event(char *buffer, size_t size) {
    char log_file[] = "events.log";
    FILE *file = fopen(log_file, "a");
    if (file != NULL) {
        fprintf(file, "%s", buffer);
        fclose(file);
    }
}

int main() {
    char event[256];
    printf("Enter log event (max 256 chars): ");
    sscanf(gets(event), "%255s", event);
    log_event(event, sizeof(event));
    printf("Logged: %s\n", event);
    return 0;
}
