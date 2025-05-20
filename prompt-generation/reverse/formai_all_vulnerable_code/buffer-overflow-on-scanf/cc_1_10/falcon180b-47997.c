//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
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
    char filename[20] = "diary.txt";
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    time_t current_time;

    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error creating diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDiary Menu:\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter your entry:\n");
            fflush(stdin);
            fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
            current_time = time(NULL);
            entries[num_entries].timestamp = current_time;
            fprintf(diary, "%s - %s\n", ctime(&current_time), entries[num_entries].text);
            fclose(diary);
            diary = fopen(filename, "a+");
            num_entries++;
            printf("\nEntry saved.\n");
            break;

        case 2:
            rewind(diary);
            printf("\nDiary Entries:\n");
            while (fscanf(diary, "%s - %[^\n]\n", entries[num_entries].text, entries[num_entries].text)!= EOF) {
                printf("%s - %s\n", ctime(&entries[num_entries].timestamp), entries[num_entries].text);
                num_entries++;
            }
            printf("\n");
            break;

        case 3:
            fclose(diary);
            exit(0);

        default:
            printf("\nInvalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}