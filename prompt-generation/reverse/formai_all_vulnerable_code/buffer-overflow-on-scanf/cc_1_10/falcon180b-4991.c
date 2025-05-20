//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500

struct entry {
    time_t timestamp;
    char text[MAX_LENGTH];
};

FILE *diary_file;

void init_diary() {
    diary_file = fopen("diary.txt", "a");
    if (diary_file == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }
}

void write_entry(struct entry entry) {
    fprintf(diary_file, "%s\n", ctime(&entry.timestamp));
    fprintf(diary_file, "%s", entry.text);
}

void read_entries() {
    rewind(diary_file);
    struct entry entry;
    while (fscanf(diary_file, "%s %s", &entry.timestamp, entry.text)!= EOF) {
        printf("%s\n%s\n", ctime(&entry.timestamp), entry.text);
    }
}

void add_entry() {
    char text[MAX_LENGTH];
    printf("Enter your diary entry:\n");
    fgets(text, MAX_LENGTH, stdin);
    struct entry entry = { time(NULL), text };
    write_entry(entry);
    printf("Entry added successfully.\n");
}

int main() {
    init_diary();
    int choice;
    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                read_entries();
                break;
            case 3:
                fclose(diary_file);
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}