//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_LENGTH];
};

FILE* diary_file = NULL;

void init_diary() {
    diary_file = fopen("diary.txt", "a+");
    if (diary_file == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }
}

int read_entries(struct entry* entries) {
    int count = 0;
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, diary_file)!= NULL) {
        if (count >= MAX_ENTRIES) {
            printf("Error: too many entries in diary.\n");
            exit(1);
        }
        struct entry entry;
        sscanf(line, "%ld %s", &entry.timestamp, entry.text);
        entries[count++] = entry;
    }
    return count;
}

void write_entry(const struct entry* entry) {
    fprintf(diary_file, "%ld %s\n", entry->timestamp, entry->text);
}

void close_diary() {
    fclose(diary_file);
}

void menu() {
    printf("Digital Diary\n");
    printf("1. Write an entry\n");
    printf("2. Read entries\n");
    printf("3. Exit\n");
}

int main() {
    init_diary();
    struct entry entries[MAX_ENTRIES];
    int entry_count = 0;
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter your entry:\n");
                fgets(entries[entry_count].text, MAX_LENGTH, stdin);
                entries[entry_count].timestamp = time(NULL);
                write_entry(&entries[entry_count]);
                entry_count++;
                break;
            case 2:
                printf("Reading entries...\n");
                int read_count = read_entries(entries);
                for (int i = 0; i < read_count; i++) {
                    printf("%ld: %s\n", entries[i].timestamp, entries[i].text);
                }
                break;
            case 3:
                close_diary();
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    return 0;
}