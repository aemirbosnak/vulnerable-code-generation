//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY_SIZE 10

typedef struct History {
    char **commands;
    int size;
} History;

History *history_init() {
    History *h = malloc(sizeof(History));
    h->commands = NULL;
    h->size = 0;
    return h;
}

void history_add(History *h, char *command) {
    h->commands = realloc(h->commands, (h->size + 1) * sizeof(char *));
    h->commands[h->size++] = command;
}

void history_print(History *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%s\n", h->commands[i]);
    }
}

int main() {
    History *h = history_init();

    // Simulate calculator usage
    char *command;
    while (1) {
        printf("Enter a command: ");
        command = malloc(20);
        scanf("%s", command);

        history_add(h, command);

        // Execute command (this part is not included in the code)
        // ...

        free(command);
    }

    // Print history
    history_print(h);

    free(h);
    return 0;
}