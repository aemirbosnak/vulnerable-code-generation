#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
} MigrationTask;

void executeMigration(MigrationTask *task) {
    printf("Executing migration: %s\n", task->data);
}

int main() {
    MigrationTask *tasks = (MigrationTask *)malloc(10 * sizeof(MigrationTask));
    if (tasks == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        tasks[i].data = (char *)malloc(20 * sizeof(char));
        if (tasks[i].data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        snprintf(tasks[i].data, 20, "Migration %d", i);
    }

    // Simulate some migrations being executed
    for (int i = 0; i < 5; i++) {
        executeMigration(&tasks[i]);
    }

    // Free the first half of the tasks
    for (int i = 0; i < 5; i++) {
        free(tasks[i].data);
        tasks[i].data = NULL;
    }

    // Use-after-free vulnerability
    for (int i = 5; i < 10; i++) {
        executeMigration(&tasks[i]); // This will access freed memory
    }

    // Clean up remaining tasks
    for (int i = 5; i < 10; i++) {
        free(tasks[i].data);
        tasks[i].data = NULL;
    }

    free(tasks);

    return 0;
}
