#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define LOG_FILE "log.txt"

void log_message(const char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    char input[10];
    printf("Enter a log message: ");
    gets(input); // Vulnerable to buffer overflow

    log_message(input);

    return 0;
}
