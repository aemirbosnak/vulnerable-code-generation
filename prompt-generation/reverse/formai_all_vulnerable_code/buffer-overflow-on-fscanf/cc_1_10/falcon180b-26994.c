//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    time_t now;

    diary = fopen("diary.txt", "r");
    if (diary == NULL) {
        fprintf(stderr, "Error: could not open diary file.\n");
        exit(1);
    }

    while (fscanf(diary, "%ld %s\n", &entries[num_entries].timestamp, entries[num_entries].text)!= EOF) {
        num_entries++;
    }

    fclose(diary);

    do {
        printf("1. Write a new entry\n");
        printf("2. Read an entry\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                time(&now);
                printf("Enter your entry:\n");
                fflush(stdout);
                fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].timestamp = now;
                num_entries++;
                break;
            case 2:
                printf("Entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%ld: %s\n", entries[i].timestamp, entries[i].text);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}