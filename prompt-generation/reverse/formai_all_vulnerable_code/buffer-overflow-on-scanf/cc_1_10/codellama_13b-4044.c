//Code Llama-13B DATASET v1.0 Category: System boot optimizer ; Style: sophisticated
// boot_optimizer.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char name[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} configuration_entry;

bool is_entry_valid(configuration_entry *entry) {
    if (strlen(entry->name) == 0 || strlen(entry->value) == 0) {
        return false;
    }

    for (int i = 0; i < strlen(entry->name); i++) {
        if (!isalnum(entry->name[i])) {
            return false;
        }
    }

    for (int i = 0; i < strlen(entry->value); i++) {
        if (!isalnum(entry->value[i]) && entry->value[i] != '_') {
            return false;
        }
    }

    return true;
}

int main() {
    configuration_entry *entries = malloc(sizeof(configuration_entry) * 100);
    int num_entries = 0;

    while (true) {
        configuration_entry entry;
        printf("Enter name and value for entry %d: ", num_entries + 1);
        scanf("%s %s", entry.name, entry.value);

        if (is_entry_valid(&entry)) {
            entries[num_entries++] = entry;
        } else {
            printf("Invalid entry. Please try again.\n");
        }
    }

    return 0;
}