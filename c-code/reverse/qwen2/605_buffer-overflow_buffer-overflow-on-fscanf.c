#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRY_SIZE 256

void write_entry(const char* entry) {
    FILE* file = fopen("diary.txt", "a");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fprintf(file, "%s\n", entry);
    fclose(file);
}

int read_entries() {
    FILE* file = fopen("diary.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return -1;
    }

    char entry[MAX_ENTRY_SIZE];
    int count = 0;

    while (fgets(entry, sizeof(entry), file)) {
        printf("%s", entry);
        count++;
    }

    fclose(file);
    return count;
}

int main() {
    char entry[MAX_ENTRY_SIZE];

    printf("Enter your diary entry (or 'exit' to quit):\n");

    while (1) {
        fgets(entry, sizeof(entry), stdin);

        if (entry[0] == 'e' && entry[1] == 'x' && entry[2] == 'i' && entry[3] == 't') {
            break;
        }

        write_entry(entry);
    }

    printf("Entries read: %d\n", read_entries());

    return 0;
}
