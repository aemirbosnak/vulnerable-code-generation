#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

int main() {
    char *entries[MAX_ENTRIES];
    int count = 0;

    printf("Enter your diary entries. Type 'exit' to finish.\n");

    while (count < MAX_ENTRIES) {
        entries[count] = (char *)malloc(ENTRY_SIZE);
        if (!entries[count]) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        printf("Entry %d: ", count + 1);
        fgets(entries[count], ENTRY_SIZE, stdin);

        // Remove newline character if present
        size_t len = strlen(entries[count]);
        if (len > 0 && entries[count][len - 1] == '\n') {
            entries[count][len - 1] = '\0';
        }

        if (strcmp(entries[count], "exit") == 0) {
            break;
        }

        count++;
    }

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", entries[i]);
        free(entries[i]); // Free allocated memory
    }

    return 0;
}
