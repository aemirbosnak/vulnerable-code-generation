#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 10

void log_message(char *message) {
    char log_file[100];
    snprintf(log_file, sizeof(log_file), "/var/log/app-%d.log", getpid());
    FILE *log_fp = fopen(log_file, "a");
    fprintf(log_fp, "%s\n", message);
    fclose(log_fp);
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];

    printf("Log Service started\n");
    printf("Enter log messages (or Ctrl+C to exit):\n");

    while (1) {
        scanf("%s", input);
        log_message(input);
    }

    return 0;
}
