//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_COMMAND_LENGTH 64

typedef struct {
    char name[MAX_LINE_LENGTH];
    char command[MAX_LINE_LENGTH];
} program_t;

program_t programs[MAX_LINE_LENGTH];
int num_programs = 0;

void add_program(char* name, char* command) {
    if (num_programs >= MAX_LINE_LENGTH) {
        printf("Error: too many programs\n");
        return;
    }

    strcpy(programs[num_programs].name, name);
    strcpy(programs[num_programs].command, command);

    num_programs++;
}

void run_program(char* name) {
    int i;

    for (i = 0; i < num_programs; i++) {
        if (strcmp(programs[i].name, name) == 0) {
            system(programs[i].command);
            break;
        }
    }
}

void optimize_boot() {
    char input[MAX_LINE_LENGTH];
    char name[MAX_LINE_LENGTH];
    char command[MAX_LINE_LENGTH];

    printf("Optimizing boot...\n");

    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        sscanf(input, "%s %s", name, command);

        if (strcmp(name, "add_program") == 0) {
            add_program(command, command);
        } else if (strcmp(name, "run_program") == 0) {
            run_program(command);
        } else {
            printf("Invalid command: %s\n", name);
        }
    }
}

int main() {
    optimize_boot();

    return 0;
}