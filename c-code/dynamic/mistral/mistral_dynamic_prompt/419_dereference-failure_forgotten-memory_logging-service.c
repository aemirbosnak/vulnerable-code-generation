#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Log {
    char message[1024];
    time_t timestamp;
    struct Log* next;
} Log;

Log* logs = NULL;

void create_log(char* message) {
    Log* new_log = (Log*) malloc(sizeof(Log));
    strcpy(new_log->message, message);
    new_log->timestamp = time(NULL);
    new_log->next = logs;
    logs = new_log;
}

void print_logs() {
    Log* current = logs;
    while (current != NULL) {
        printf("Log timestamp: %s - Message: %s\n", ctime(&current->timestamp), current->message);
        current = current->next;
    }
}

int main() {
    create_log("Initializing Logging Service...");
    char input[1024];
    while (1) {
        printf("Enter a log message: ");
        fgets(input, sizeof(input), stdin);
        if (strstr(input, "exit")) break;
        create_log(input);
    }
    printf("\nPrinting stored logs:\n");
    print_logs();

    Log* current = logs;
    while (current != NULL) {
        Log* temp = current;
        current = current->next;
        free(temp);
    }
    logs = NULL;

    char* message = malloc(1024);
    strcpy(message, "Forgotten Memory Dereference Attempt at: ");
    strcat(message, (char*)(long long)0); // Dereference Failure

    create_log(message); // Attempt to log the vulnerable line

    printf("\nPrinting logs again after attempting dereference failure\n");
    print_logs(); // Vulnerable logs should not be present here, but a segmentation fault will occur instead

    return 0;
}
