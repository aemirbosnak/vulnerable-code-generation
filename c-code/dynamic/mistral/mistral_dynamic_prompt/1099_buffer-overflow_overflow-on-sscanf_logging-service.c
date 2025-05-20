#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void log_entry(char *buf) {
    char log_file[] = "log.txt";
    FILE *log_fd;
    time_t now;

    log_fd = fopen(log_file, "a");
    if (log_fd == NULL) {
        perror("Error opening log file");
        return;
    }

    now = time(NULL);
    fprintf(log_fd, "[%s] - ", ctime(&now));
    fputs(buf, log_fd);
    fputs("\n", log_fd);
    fclose(log_fd);
}

int main(int argc, char *argv[]) {
    char buffer[10];
    int num;

    printf("Enter a number: ");
    if (sscanf(argv[1], "%s%n", buffer, &num) != 1) {
        printf("Invalid input. Expected integer.\n");
        return 1;
    }

    printf("You entered: %s\n", buffer);
    log_entry(buffer);

    // Trigger the buffer overflow
    for (int i = 10; i < 200; ++i) {
        buffer[i] = 'A';
    }

    return 0;
}
