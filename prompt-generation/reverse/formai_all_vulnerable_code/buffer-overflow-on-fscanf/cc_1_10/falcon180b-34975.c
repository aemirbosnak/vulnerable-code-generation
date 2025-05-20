//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 1000

struct entry {
    char date[11];
    char time[9];
    char content[500];
};

int main() {
    FILE *file;
    char filename[20] = "diary.txt";
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    while (fscanf(file, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content)!= EOF) {
        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached!\n");
            break;
        }
    }

    fclose(file);

    while (1) {
        printf("Digital Diary\n");
        printf("-----------------\n");
        printf("1. View Entries\n");
        printf("2. Add Entry\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("View Entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s %s %s\n", entries[i].date, entries[i].time, entries[i].content);
            }
            break;
        case 2:
            printf("Add Entry:\n");
            printf("Date (YYYY-MM-DD): ");
            scanf("%s", entries[num_entries].date);
            printf("Time (HH:MM:SS): ");
            scanf("%s", entries[num_entries].time);
            printf("Content:\n");
            fgets(entries[num_entries].content, 500, stdin);
            num_entries++;
            if (num_entries >= MAX_ENTRIES) {
                printf("Maximum number of entries reached!\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}