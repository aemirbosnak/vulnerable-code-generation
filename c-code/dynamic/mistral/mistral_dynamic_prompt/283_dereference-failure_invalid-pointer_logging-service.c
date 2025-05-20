#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024
#define NUM_LOG_ENTRIES 10

struct LogEntry {
    char message[MAX_LOG_SIZE];
    struct LogEntry *next;
};

void log_message(struct LogEntry **head, char *message) {
    struct LogEntry *new_entry = (struct LogEntry *)malloc(sizeof(struct LogEntry));
    if (!new_entry) {
        fprintf(stderr, "Out of memory!\n");
        return;
    }

    strcpy(new_entry->message, message);
    new_entry->next = *head;
    *head = new_entry;
}

void print_log(struct LogEntry *head) {
    struct LogEntry *current = head;
    while (current != NULL) {
        printf("%s\n", current->message);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    struct LogEntry *log_list = NULL;

    log_message(&log_list, "Application started");

    if (argc > 1) {
        log_message(&log_list, argv[1]);
    }

    print_log(log_list);

    // Intentionally dereference an invalid pointer after freeing the memory
    free(log_list);
    log_message(log_list, "This should cause a segmentation fault");

    return 0;
}
