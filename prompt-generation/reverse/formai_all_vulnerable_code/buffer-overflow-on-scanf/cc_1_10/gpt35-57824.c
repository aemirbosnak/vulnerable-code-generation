//FormAI DATASET v1.0 Category: System boot optimizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

typedef struct {
    char name[BUFF_SIZE];
    int priority;
} BootProgram;

int compare(const void* a, const void* b) {
    BootProgram* p1 = (BootProgram*)a;
    BootProgram* p2 = (BootProgram*)b;
    return p2->priority - p1->priority;
}

int main() {
    // Initialize boot programs
    BootProgram bootList[BUFF_SIZE];
    int numPrograms = 0;
    char input[BUFF_SIZE];
    int priority;

    printf("Enter name of boot program (or 'done' to finish input):\n");
    while (1) {
        printf("> ");
        fgets(input, BUFF_SIZE, stdin);

        // Strip newline from input
        char* newline = strchr(input, '\n');
        if (newline) *newline = '\0';

        // Exit loop if user enters "done"
        if (strcmp(input, "done") == 0) break;

        printf("Enter priority for %s:\n", input);
        scanf("%d", &priority);
        getchar(); // Clear the newline character from input buffer

        // Add program to list
        strcpy(bootList[numPrograms].name, input);
        bootList[numPrograms].priority = priority;

        numPrograms++;
        printf("\n");
    }

    printf("Sorting boot programs by priority...\n");
    qsort(bootList, numPrograms, sizeof(BootProgram), compare);

    printf("Optimizing boot sequence...\n");
    for (int i = 0; i < numPrograms; i++) {
        printf("%d. %s\n", i+1, bootList[i].name);
    }

    printf("Boot optimization complete.\n");

    return 0;
}