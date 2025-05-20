#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct LogEntry {
    char* message;
    struct LogEntry* next;
} LogEntry;

LogEntry* head = NULL;

void add_entry(char* message) {
    LogEntry* new_entry = (LogEntry*)malloc(sizeof(LogEntry));
    new_entry->message = (char*)malloc((strlen(message) + 1) * sizeof(char));
    strcpy(new_entry->message, message);
    new_entry->next = head;
    head = new_entry;
}

void print_log() {
    LogEntry* current = head;
    while (current != NULL) {
        printf("%s\n", current->message);
        current = current->next;
    }
}

void free_log() {
    LogEntry* current = head;
    LogEntry* next;

    while (current != NULL) {
        next = current->next;
        free(current->message);
        free(current);
        current = next;
    }

    head = NULL;
}

int main() {
    char input[1024];

    while (1) {
        printf("Enter log message: ");
        fgets(input, sizeof(input), stdin);

        add_entry(input);

        sleep(1); // Simulate delay between log entries
        system("clear"); // Clear console on Unix systems
        print_log();
    }

    return 0;
}
