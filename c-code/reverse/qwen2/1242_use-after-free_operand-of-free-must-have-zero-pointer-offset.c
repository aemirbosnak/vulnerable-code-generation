#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_ENTRIES 5

int main() {
    char entries[MAX_ENTRIES][100];
    int count = 0;

    printf("Enter up to %d diary entries:\n", MAX_ENTRIES);
    while (count < MAX_ENTRIES) {
        printf("Entry %d: ", count + 1);
        if (fgets(entries[count], sizeof(entries[count]), stdin)) {
            // Remove newline character if present
            size_t len = strlen(entries[count]);
            if (len > 0 && entries[count][len - 1] == '\n') {
                entries[count][len - 1] = '\0';
            }
            count++;
        } else {
            break;
        }
    }

    printf("\nDisplaying all entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", entries[i]);
    }

    // Intentionally introduce a use-after-free vulnerability by accessing freed memory
    printf("\nAccessing freed memory:\n");
    for (int i = 0; i < MAX_ENTRIES; i++) {
        printf("%s\n", entries[i]); // This will access freed memory after the loop ends
    }

    return 0;
}
