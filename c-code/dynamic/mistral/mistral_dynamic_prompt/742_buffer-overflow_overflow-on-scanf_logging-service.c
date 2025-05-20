#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void log_message(char *message) {
    FILE *log_file;
    char log_filename[256];

    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    strftime(log_filename, sizeof(log_filename), "./logs/log_%Y-%m-%d_%H-%M-%S.txt", tm_now);
    log_file = fopen(log_filename, "a");
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

int main(int argc, char **argv) {
    char buffer[10];

    printf("Log service started. Press CTRL+C to stop.\n");
    int counter = 1;

    while (1) {
        printf("\nEnter log message (up to 10 characters): ");
        fgets(buffer, sizeof(buffer), stdin);
        log_message(buffer);
        counter++;
    }

    return 0;
}
