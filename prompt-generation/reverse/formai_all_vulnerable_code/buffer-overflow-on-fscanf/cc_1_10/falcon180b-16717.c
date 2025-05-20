//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000
#define FILENAME "diary.txt"

struct entry {
    char date[20];
    char content[MAX_ENTRY_LENGTH];
};

void read_entries(struct entry entries[]) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No diary file found.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", entries[count].date, entries[count].content)!= EOF) {
        count++;
    }
    fclose(file);
}

void write_entry(struct entry entries[], int count, char date[], char content[]) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error writing to diary file.\n");
        exit(1);
    }

    fprintf(file, "%s %s\n", date, content);
    fclose(file);
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    read_entries(entries);

    while (1) {
        printf("1. Write entry\n2. Read entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char date[20];
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);

                char content[MAX_ENTRY_LENGTH];
                printf("Enter content:\n");
                scanf("%s", content);

                write_entry(entries, count, date, content);
                count++;
                break;
            }
            case 2: {
                printf("Entries:\n");
                for (int i = 0; i < count; i++) {
                    printf("%s %s\n", entries[i].date, entries[i].content);
                }
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}