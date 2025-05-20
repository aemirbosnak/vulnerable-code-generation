//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 100

typedef struct {
    char *key;
    int value;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s -> %d\n", entries[i].key, entries[i].value);
    }
}

int main() {
    char input[MAX_ENTRY_SIZE];
    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_ENTRY_SIZE, stdin);
        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "add") == 0) {
            char key[MAX_ENTRY_SIZE];
            int value;
            printf("Enter key: ");
            fgets(key, MAX_ENTRY_SIZE, stdin);
            printf("Enter value: ");
            scanf("%d", &value);
            strncpy(entries[num_entries].key, key, MAX_ENTRY_SIZE);
            entries[num_entries].value = value;
            num_entries++;
        } else if (strcmp(input, "search") == 0) {
            char key[MAX_ENTRY_SIZE];
            printf("Enter key: ");
            fgets(key, MAX_ENTRY_SIZE, stdin);
            int found = 0;
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(entries[i].key, key) == 0) {
                    printf("%s -> %d\n", entries[i].key, entries[i].value);
                    found = 1;
                }
            }
            if (!found) {
                printf("Not found.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}