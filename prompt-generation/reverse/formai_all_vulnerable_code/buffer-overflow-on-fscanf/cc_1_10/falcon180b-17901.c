//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[32];
    char time[32];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    time_t current_time;
    FILE *diary_file;

    // Open diary file
    diary_file = fopen("diary.txt", "r");
    if (diary_file == NULL) {
        printf("Error: Diary file not found. Creating new file...\n");
        diary_file = fopen("diary.txt", "w");
        if (diary_file == NULL) {
            printf("Error: Unable to create diary file.\n");
            exit(1);
        }
    }

    // Read existing entries from diary file
    while (fscanf(diary_file, "%s %s %s", diary[num_entries].date, diary[num_entries].time, diary[num_entries].content)!= EOF) {
        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            break;
        }
    }
    fclose(diary_file);

    // Main program loop
    while (1) {
        time(&current_time);
        printf("Enter your diary entry for ");
        printf("%s ", ctime(&current_time));
        fgets(diary[num_entries].content, MAX_ENTRY_LENGTH, stdin);
        strftime(diary[num_entries].date, 32, "%Y-%m-%d", localtime(&current_time));
        strftime(diary[num_entries].time, 32, "%H:%M:%S", localtime(&current_time));
        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            printf("Diary is full. Exiting program.\n");
            break;
        }

        // Save entry to diary file
        diary_file = fopen("diary.txt", "a");
        if (diary_file == NULL) {
            printf("Error: Unable to write to diary file.\n");
            exit(1);
        }
        fprintf(diary_file, "%s %s %s\n", diary[num_entries - 1].date, diary[num_entries - 1].time, diary[num_entries - 1].content);
        fclose(diary_file);
    }

    return 0;
}