//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];
    time_t now;
    char filename[50];

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter a name for your diary file (without extension): ");
    scanf("%s", filename);

    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    time(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", localtime(&now));
    strftime(entries[num_entries].time, 10, "%H:%M:%S", localtime(&now));

    while (1) {
        printf("Enter your diary entry (up to %d characters):\n", MAX_ENTRY_LENGTH - 1);
        fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
        if (feof(stdin)) {
            break;
        }

        strcat(entries[num_entries].entry, "\n");
        fprintf(diary, "%s\n%s\n%s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].entry);

        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            printf("Diary is full. Exiting program.\n");
            fclose(diary);
            return 0;
        }
    }

    fclose(diary);
    printf("Thank you for using the Digital Diary!\n");

    return 0;
}