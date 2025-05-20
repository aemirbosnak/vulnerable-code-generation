//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 2048

struct Entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main(void) {
    FILE *diary_file = fopen("diary.txt", "r");
    if (diary_file == NULL) {
        printf("Diary file not found. Creating a new one.\n");
        diary_file = fopen("diary.txt", "w");
        if (diary_file == NULL) {
            printf("Error creating diary file.\n");
            return 1;
        }
    }

    struct Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES && fscanf(diary_file, "%ld %[^\n]", &entries[num_entries].timestamp, entries[num_entries].text)!= EOF) {
        num_entries++;
    }

    fclose(diary_file);

    diary_file = fopen("diary.txt", "a");
    if (diary_file == NULL) {
        printf("Error opening diary file for writing.\n");
        return 1;
    }

    char input[MAX_ENTRY_LENGTH];
    while (1) {
        printf("Enter your thoughts for today (press ENTER to quit):\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);

        if (strcmp(input, "\n") == 0) {
            break;
        }

        time_t timestamp = time(NULL);
        struct tm *tm = localtime(&timestamp);
        char date_str[32];
        strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm);

        fprintf(diary_file, "%ld %s\n", timestamp, input);
        printf("Thought saved.\n");
    }

    fclose(diary_file);
    return 0;
}