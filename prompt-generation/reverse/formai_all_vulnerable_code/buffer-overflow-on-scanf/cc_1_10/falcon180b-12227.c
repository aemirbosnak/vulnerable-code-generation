//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    char filename[64];
    time_t now;
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];

    time(&now);
    strftime(filename, sizeof(filename), "diary_%Y%m%d_%H%M%S.txt", localtime(&now));

    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    fprintf(diary, "Digital Diary v1.0\n\n");

    while (1) {
        printf("1. Write a new entry\n2. Read entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Error: Maximum number of entries reached.\n");
                break;
            }

            printf("Enter your entry:\n");
            fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
            entries[num_entries].timestamp = time(NULL);
            num_entries++;

            fprintf(diary, "Entry #%d (%.24s): %s\n", num_entries, ctime(&entries[num_entries-1].timestamp), entries[num_entries-1].text);
            fflush(diary);

            break;

        case 2:
            fseek(diary, 0, SEEK_SET);
            rewind(diary);

            printf("Diary entries:\n");
            while (fgets(filename, sizeof(filename), diary)!= NULL) {
                printf("%s", filename);
            }

            break;

        case 3:
            fclose(diary);
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}