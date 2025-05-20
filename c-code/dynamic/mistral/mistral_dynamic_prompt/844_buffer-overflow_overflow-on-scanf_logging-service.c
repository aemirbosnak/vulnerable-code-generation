#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void log_message(char *message) {
    FILE *log_file = fopen("log.txt", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    }
}

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER];

    printf("Log Service - Enter your log message:\n");
    scanf("%s", buffer); // Buffer overflow potential

    log_message(buffer);

    return 0;
}
