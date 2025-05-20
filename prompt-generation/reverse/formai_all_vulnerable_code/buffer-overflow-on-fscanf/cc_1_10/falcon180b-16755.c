//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct entry *entries, int num_entries, char *date, char *time, char *content) {
    strncpy(entries[num_entries].date, date, 20);
    strncpy(entries[num_entries].time, time, 20);
    strncpy(entries[num_entries].content, content, MAX_ENTRY_LENGTH);
    num_entries++;
}

void print_entries(struct entry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

int main() {
    FILE *fp;
    char filename[50] = "diary.txt";
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    fp = fopen(filename, "a+");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    rewind(fp);
    while (fscanf(fp, "%s %s %s", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content)!= EOF) {
        num_entries++;
    }

    fclose(fp);

    int choice;
    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter time (HH:MM:SS): ");
                scanf("%s", entries[num_entries].time);
                printf("Enter content:\n");
                fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                add_entry(entries, num_entries, entries[num_entries].date, entries[num_entries].time, entries[num_entries].content);
                num_entries++;
                break;
            case 2:
                print_entries(entries, num_entries);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}