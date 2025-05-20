//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *diary;
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50];
    char command[50];

    printf("Welcome to the Digital Diary!\n");

    // Check if diary file exists
    sprintf(filename, "diary.txt");
    if ((diary = fopen(filename, "r"))!= NULL) {
        fclose(diary);
    } else {
        diary = fopen(filename, "w");
        fprintf(diary, "Digital Diary\n");
        fclose(diary);
    }

    // Main loop
    while (1) {
        printf("\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", entries[num_entries].date);
            printf("Enter entry: ");
            scanf("%s", entries[num_entries].entry);
            num_entries++;

            // Write to diary file
            diary = fopen(filename, "a");
            fprintf(diary, "%s\n%s\n", entries[num_entries-1].date, entries[num_entries-1].entry);
            fclose(diary);

            printf("Entry added!\n");
        } else if (strcmp(command, "view") == 0) {
            printf("Viewing diary...\n");

            // Read from diary file
            diary = fopen(filename, "r");
            while (!feof(diary)) {
                fgets(command, 50, diary);
                printf("%s", command);
            }
            fclose(diary);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}