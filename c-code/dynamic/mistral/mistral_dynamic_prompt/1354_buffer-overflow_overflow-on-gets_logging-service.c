#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void log_message(const char *process_name, const char *message) {
    char log_file[MAX_BUFFER_SIZE] = {0};
    FILE *log_fp = fopen("log.txt", "a");

    if (log_fp != NULL) {
        fprintf(log_fp, "[%s] %s\n", process_name, message);
        fclose(log_fp);
    }
}

int main(int argc, char *argv[]) {
    char input[MAX_BUFFER_SIZE];
    printf("Enter log message (max 255 chars): ");
    gets(input);

    log_message("Logging Service", input);

    return 0;
}
