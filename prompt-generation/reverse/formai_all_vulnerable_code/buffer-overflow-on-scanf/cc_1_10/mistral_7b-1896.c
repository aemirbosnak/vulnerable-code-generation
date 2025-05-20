//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define LOG_FILE "event.log"

struct log_entry {
    time_t timestamp;
    int event_type;
    char message[256];
};

int main(void) {
    int fd;
    struct log_entry log_entry;
    char *message;

    fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    while (1) {
        time(&log_entry.timestamp);

        printf("Enter event type (1 for info, 2 for warning, 3 for error): ");
        scanf("%d", &log_entry.event_type);

        printf("Enter event message: ");
        message = (char*) malloc(256 * sizeof(char));
        fgets(message, 256, stdin);
        strtok(message, "\n");
        strcpy(log_entry.message, message);

        write(fd, &log_entry, sizeof(log_entry));

        printf("Event logged successfully!\n");

        printf("Do you want to log another event? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    close(fd);
    free(message);
    return EXIT_SUCCESS;
}