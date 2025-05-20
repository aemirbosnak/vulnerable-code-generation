//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 1024

struct entry {
    time_t timestamp;
    char content[MAX_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    time_t now;

    diary = fopen("diary.txt", "a+");
    if (diary == NULL) {
        fprintf(stderr, "Error: Could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read an entry\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter your entry:\n");
            fflush(stdout);
            fgets(entries[num_entries].content, MAX_LENGTH, stdin);
            entries[num_entries].timestamp = time(NULL);
            num_entries++;
            if (num_entries >= MAX_ENTRIES) {
                printf("Diary is full. Please delete some entries.\n");
            }
            break;

        case 2:
            printf("Which entry would you like to read? (0 for the latest)\n");
            scanf("%d", &choice);
            if (choice >= num_entries) {
                printf("No such entry.\n");
            } else {
                printf("Entry %d:\n%s", choice, entries[choice].content);
            }
            break;

        case 3:
            fclose(diary);
            diary = fopen("diary.txt", "w");
            for (int i = 0; i < num_entries; i++) {
                fprintf(diary, "%s\n", entries[i].content);
            }
            fclose(diary);
            printf("Diary saved.\n");
            exit(0);

        case 4:
            printf("Are you sure you want to exit without saving? (y/n)\n");
            char answer[2];
            scanf("%s", answer);
            if (answer[0] == 'y' || answer[0] == 'Y') {
                exit(0);
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}