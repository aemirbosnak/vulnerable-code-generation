//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50] = "diary.txt";

    diary = fopen(filename, "a");

    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("Welcome to your digital diary!\n");
        printf("What would you like to do?\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter your new diary entry:\n");
            fflush(stdin);
            char input[MAX_ENTRY_LENGTH];
            fgets(input, MAX_ENTRY_LENGTH, stdin);

            int length = strlen(input);
            if (length > 0 && input[length - 1] == '\n') {
                input[length - 1] = '\0';
                length--;
            }

            struct entry new_entry = {time(NULL), input};

            if (num_entries >= MAX_ENTRIES) {
                printf("Error: maximum number of entries reached.\n");
            } else {
                entries[num_entries++] = new_entry;
            }

            fclose(diary);
            diary = fopen(filename, "w");

            for (int i = 0; i < num_entries; i++) {
                fprintf(diary, "%s\n", entries[i].text);
            }

            fprintf(diary, "%s\n", new_entry.text);

            fclose(diary);
            diary = fopen(filename, "a");

            printf("New entry added!\n");
            break;

        case 2:
            if (num_entries == 0) {
                printf("No entries found.\n");
            } else {
                printf("Previous entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    struct tm *timestamp = localtime(&entries[i].timestamp);
                    printf("%02d/%02d/%04d %02d:%02d:%02d - %s\n",
                            timestamp->tm_mon + 1,
                            timestamp->tm_mday,
                            timestamp->tm_year + 1900,
                            timestamp->tm_hour,
                            timestamp->tm_min,
                            timestamp->tm_sec,
                            entries[i].text);
                }
            }
            break;

        case 3:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}