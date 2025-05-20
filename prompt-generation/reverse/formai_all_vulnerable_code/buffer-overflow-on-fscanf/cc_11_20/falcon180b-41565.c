//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary_file;
    char filename[20] = "diary.txt";
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];

    diary_file = fopen(filename, "r");
    if (diary_file == NULL) {
        printf("Diary file not found, creating new file.\n");
    } else {
        printf("Reading existing diary entries...\n");
        while (fscanf(diary_file, "%s %s\n", &entries[num_entries].timestamp, entries[num_entries].text)!= EOF) {
            num_entries++;
        }
        fclose(diary_file);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Diary is full, cannot write new entry.\n");
            } else {
                time_t now = time(NULL);
                strftime(entries[num_entries].timestamp, sizeof(entries[num_entries].timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
                printf("Enter your entry:\n");
                scanf("%[^\n]", entries[num_entries].text);
                entries[num_entries].text[strcspn(entries[num_entries].text, "\n")] = '\0';
                num_entries++;
                printf("Entry saved.\n");
            }
            break;

        case 2:
            if (num_entries == 0) {
                printf("No entries yet.\n");
            } else {
                for (int i = 0; i < num_entries; i++) {
                    printf("%s: %s\n", ctime(&entries[i].timestamp), entries[i].text);
                }
            }
            break;

        case 3:
            diary_file = fopen(filename, "w");
            if (diary_file == NULL) {
                printf("Error: could not open diary file for writing.\n");
            } else {
                for (int i = 0; i < num_entries; i++) {
                    fprintf(diary_file, "%s %s\n", entries[i].timestamp, entries[i].text);
                }
                fclose(diary_file);
            }
            exit(0);

        default:
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}