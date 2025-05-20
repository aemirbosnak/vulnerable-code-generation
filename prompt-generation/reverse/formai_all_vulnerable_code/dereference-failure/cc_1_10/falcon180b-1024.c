//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LENGTH 80
#define HASH_TABLE_SIZE 101

typedef struct {
    char *name;
    void (*function)();
} command_t;

typedef struct {
    char *key;
    int value;
} hash_entry_t;

command_t commands[MAX_COMMANDS];
hash_entry_t hash_table[HASH_TABLE_SIZE];

void add_command(char *name, void (*function)()) {
    int i;
    for (i = 0; i < MAX_COMMANDS && commands[i].name!= NULL; i++) {
        if (strcmp(name, commands[i].name) == 0) {
            printf("Error: Command '%s' already exists.\n", name);
            return;
        }
    }
    if (i == MAX_COMMANDS) {
        printf("Error: Too many commands.\n");
        return;
    }
    strcpy(commands[i].name, name);
    commands[i].function = function;
}

void execute_command(char *input) {
    int hash = 0;
    while (*input) {
        hash = (hash * 31 + *input++) % HASH_TABLE_SIZE;
    }
    hash_entry_t *entry = &hash_table[hash];
    while (entry->key!= NULL) {
        if (strcmp(entry->key, input) == 0) {
            entry->value++;
            return;
        }
        entry++;
    }
    strcpy(entry->key, input);
    entry->value = 1;
}

void print_hash_table() {
    int i;
    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        hash_entry_t *entry = &hash_table[i];
        while (entry->key!= NULL) {
            printf("%s: %d\n", entry->key, entry->value);
            entry++;
        }
    }
}

int main() {
    add_command("add", &execute_command);
    add_command("print", &print_hash_table);

    char input[MAX_COMMAND_LENGTH];
    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        char *token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }
        execute_command(token);
    }

    return 0;
}