#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "log.txt"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    char input[10];
    printf("Enter a message to log: ");
    fscanf(stdin, "%s", input); // Vulnerable to buffer overflow

    log_message(input);

    printf("Message logged successfully.\n");

    return 0;
}
