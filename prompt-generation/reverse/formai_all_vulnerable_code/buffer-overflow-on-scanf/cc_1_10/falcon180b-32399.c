//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LEN);
    strncpy(entries[num_entries].value, value, MAX_VALUE_LEN);

    num_entries++;
}

void remove_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memset(&entries[i], 0, sizeof(entry_t));
            num_entries--;
            break;
        }
    }
}

void update_entry(char* name, char* value) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            strncpy(entries[i].value, value, MAX_VALUE_LEN);
            break;
        }
    }
}

void print_entries() {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].value);
    }
}

int main() {
    char command[100];
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];

    while (1) {
        printf("Enter command (add/remove/update/print/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter value: ");
            scanf("%s", value);
            add_entry(name, value);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            remove_entry(name);
        } else if (strcmp(command, "update") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter value: ");
            scanf("%s", value);
            update_entry(name, value);
        } else if (strcmp(command, "print") == 0) {
            print_entries();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}