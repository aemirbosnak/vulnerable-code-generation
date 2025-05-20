//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];

    diary = fopen(filename, "r");
    if (diary == NULL) {
        printf("Diary file not found. Creating a new one.\n");
        diary = fopen(filename, "w");
        fprintf(diary, "Welcome to your digital diary!\n");
        fprintf(diary, "=================================\n");
    } else {
        printf("Diary file found. Reading existing entries...\n");
        while (fscanf(diary, "%s %s %s", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content)!= EOF) {
            num_entries++;
        }
        fclose(diary);
        diary = fopen(filename, "a");
    }

    while (1) {
        printf("\n=================================\n");
        printf("Date: ");
        scanf("%s", entries[num_entries].date);
        printf("Time: ");
        scanf("%s", entries[num_entries].time);

        printf("\nEnter your diary entry:\n");
        fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);

        fprintf(diary, "%s %s\n%s\n=================================\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content);
        num_entries++;

        if (num_entries >= MAX_ENTRIES) {
            printf("\nDiary is full. Exiting program.\n");
            break;
        }
    }

    fclose(diary);
    return 0;
}