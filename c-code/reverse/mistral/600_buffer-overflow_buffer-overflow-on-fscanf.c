#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100
#define MAX_ENTRY_LENGTH 200

struct Entry {
    char name[MAX_NAME_LENGTH];
    char entry[MAX_ENTRY_LENGTH];
};

void read_entries(struct Entry entries[], int max_entries, FILE *file) {
    for (int i = 0; i < max_entries; ++i) {
        fscanf(file, "%s%s", entries[i].name, entries[i].entry);
    }
}

int main() {
    struct Entry diary[10];
    FILE *file = fopen("diary.txt", "r");

    read_entries(diary, 10, file);

    // Buffer overflow vulnerability: fixed-size array is exceeded by the input
    char input_name[5];
    char input_entry[256];
    printf("Enter your name: ");
    fgets(input_name, sizeof(input_name), stdin);
    printf("Enter your entry: ");
    fgets(input_entry, sizeof(input_entry), stdin);

    // Adding an entry with a large name and entry
    strcpy(diary[9].name, input_name);
    strcpy(diary[9].entry, input_entry);

    // Printing all entries
    for (int i = 0; i < 10; ++i) {
        printf("Name: %s\nEntry: %s\n", diary[i].name, diary[i].entry);
    }

    fclose(file);
    return 0;
}
