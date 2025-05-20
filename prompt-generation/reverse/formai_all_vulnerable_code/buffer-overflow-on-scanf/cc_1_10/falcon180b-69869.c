//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50] = "diary.txt";
    char input[MAX_ENTRY_LENGTH];
    time_t current_time;
    struct tm *time_info;

    diary = fopen(filename, "r");
    if (diary == NULL) {
        printf("Diary file not found. Creating a new one.\n");
        diary = fopen(filename, "w");
        if (diary == NULL) {
            printf("Cannot create diary file.\n");
            return 1;
        }
    } else {
        fclose(diary);
    }

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", input);
        current_time = time(NULL);
        time_info = localtime(&current_time);
        strftime(input, sizeof(input), "%Y-%m-%d", time_info);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (num_entries >= MAX_ENTRIES) {
            printf("Diary is full.\n");
            continue;
        }

        printf("Enter your entry: ");
        scanf("%[^\n]", entries[num_entries].entry);
        strcpy(entries[num_entries].date, input);
        num_entries++;
    }

    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Cannot open diary file.\n");
        return 1;
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(diary, "%s: %s\n", entries[i].date, entries[i].entry);
    }

    fclose(diary);
    return 0;
}