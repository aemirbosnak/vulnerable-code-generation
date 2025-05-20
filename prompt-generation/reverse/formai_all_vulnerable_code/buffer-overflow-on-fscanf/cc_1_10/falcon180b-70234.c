//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];
    char filename[50] = "diary.txt";
    char input[MAX_ENTRY_LENGTH];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // Open diary file for reading
    diary = fopen(filename, "r");
    if (diary == NULL) {
        printf("Diary file not found. Creating new file.\n");
        diary = fopen(filename, "w");
        if (diary == NULL) {
            printf("Error creating diary file.\n");
            return 1;
        }
    }
    
    // Read existing entries from file
    while (fscanf(diary, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].entry)!= EOF) {
        num_entries++;
    }
    fclose(diary);
    
    // Get user input for new entry
    printf("What's on your mind today?\n");
    fgets(input, MAX_ENTRY_LENGTH, stdin);
    
    // Format and write new entry to file
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", t);
    strftime(entries[num_entries].time, 10, "%H:%M:%S", t);
    strcat(entries[num_entries].entry, input);
    strcat(entries[num_entries].entry, "\n");
    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Error writing to diary file.\n");
        return 1;
    }
    fprintf(diary, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].entry);
    fclose(diary);
    
    printf("New entry added to diary.\n");
    return 0;
}