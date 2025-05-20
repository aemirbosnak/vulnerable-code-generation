#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 256

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    time_t timestamp;
} DiaryEntry;

void add_entry(const char* filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    DiaryEntry entry;
    printf("Enter your diary entry: ");
    fgets(entry.entry, sizeof(entry.entry), stdin);
    entry.timestamp = time(NULL);

    fprintf(file, "%s\t%ld\n", entry.entry, entry.timestamp);
    fclose(file);
}

void view_entries(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    DiaryEntry entry;
    while (fscanf(file, "%[^\t]\t%ld\n", entry.entry, &entry.timestamp) != EOF) {
        printf("Entry: %sTimestamp: %s", entry.entry, ctime(&entry.timestamp));
    }
    fclose(file);
}

int main() {
    const char* filename = "diary.txt";
    int choice;

    while (1) {
        printf("\n1. Add Entry\n2. View Entries\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                add_entry(filename);
                break;
            case 2:
                view_entries(filename);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
