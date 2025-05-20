//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary_file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[30];
    time_t now;
    struct tm *t;

    printf("Welcome to your digital diary!\n");
    printf("Please enter a filename for your diary: ");
    scanf("%s", filename);

    diary_file = fopen(filename, "a+");
    if (diary_file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read existing entries from file
    rewind(diary_file);
    while (fscanf(diary_file, "%s %s\n", entries[num_entries].date, entries[num_entries].entry)!= EOF) {
        num_entries++;
    }

    // Get current date and time
    time(&now);
    t = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d %H:%M:%S", t);

    printf("\n%s\n", entries[num_entries].date);
    printf("Press enter to start writing your entry.\n");
    fflush(stdout);
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);

    // Write new entry to file
    fprintf(diary_file, "%s %s\n", entries[num_entries].date, entries[num_entries].entry);
    fclose(diary_file);

    printf("\nEntry saved!\n");
    return 0;
}