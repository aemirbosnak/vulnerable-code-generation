#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE 256

int main() {
    char entries[MAX_ENTRIES][ENTRY_SIZE];
    int num_entries = 0;

    char input[ENTRY_SIZE];

    while (1) {
        printf("Enter diary entry (or 'q' to quit): ");
        fgets(input, ENTRY_SIZE, stdin);

        if (input[0] == 'q' || input[0] == '\n') {
            break;
        }

        strcpy(entries[num_entries], input);
        num_entries++;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d: %s\n", i + 1, entries[i]);
    }

    // Intentionally using freed memory
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d: %s\n", i + 1, entries[i]);
    }

    return 0;
}
