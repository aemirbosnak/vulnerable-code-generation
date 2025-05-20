//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    char filename[20];
    int entry_count = 0;
    struct entry entries[MAX_ENTRIES];

    printf("Welcome to your digital diary!\n");
    printf("Please enter a name for your diary file (without extension): ");
    scanf("%s", filename);

    diary = fopen(filename, "a+");

    if (diary == NULL) {
        printf("Could not open diary file. Exiting.\n");
        return 1;
    }

    while (entry_count < MAX_ENTRIES) {
        printf("\n");
        printf("------------------------------\n");
        printf("Entry %d\n", entry_count + 1);
        printf("------------------------------\n");
        printf("Write your thoughts here:\n");
        fgets(entries[entry_count].text, MAX_ENTRY_LENGTH, stdin);
        entries[entry_count].timestamp = time(NULL);
        entry_count++;
    }

    rewind(diary);

    for (int i = 0; i < entry_count; i++) {
        fprintf(diary, "Entry %d:\n", i + 1);
        fprintf(diary, "Timestamp: %s\n", ctime(&entries[i].timestamp));
        fprintf(diary, "%s\n", entries[i].text);
        fprintf(diary, "\n");
    }

    fclose(diary);

    printf("\nYour diary has been saved to %s.\n", filename);

    return 0;
}