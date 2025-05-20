//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_EVENT_LEN 1000
#define NUM_PRIORITIES 5
#define LOG_FILE "/apocalog.txt"

typedef struct {
    char message[MAX_EVENT_LEN];
    int priority;
} EventLogEntry;

int createLogFile() {
    int fd;
    if ((fd = open(LOG_FILE, O_CREAT | O_WRONLY | O_APPEND, 0644)) < 0) {
        perror("open");
        return 1;
    }
    return fd;
}

void logEvent(int priority, char* message) {
    int fd, len, ret;
    EventLogEntry entry;

    if ((fd = createLogFile()) < 0) {
        perror("createLogFile");
        return;
    }

    strcpy(entry.message, message);
    entry.priority = priority;

    len = strlen(entry.message) + sizeof(EventLogEntry);
    ret = write(fd, &entry, len);

    if (ret != len) {
        perror("write");
    } else {
        printf("Event logged: Priority %d - %s\n", priority, message);
    }

    close(fd);
}

int main() {
    clock_t start = clock();

    logEvent(4, "Day 1: The sun rose over the ashes of the old world.");
    logEvent(3, "Day 1: Gathered supplies and met survivor group.");
    logEvent(2, "Day 1: Faced first threat: a pack of roaming mutants.");
    logEvent(1, "Day 1: Survived first encounter with mutants.");
    logEvent(0, "Day 1: Established temporary shelter.");

    clock_t end = clock();
    double elapsed_secs = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nLogged %d events in %.2f seconds.\n", 5, elapsed_secs);

    return 0;
}