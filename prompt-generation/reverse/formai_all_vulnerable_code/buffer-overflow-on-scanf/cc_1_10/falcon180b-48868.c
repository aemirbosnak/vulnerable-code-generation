//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50];
    time_t now;
    srand(time(NULL));

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter the name of your diary file (without extension): ");
    scanf("%s", filename);

    diary = fopen(filename, "r");
    if (diary!= NULL) {
        printf("Reading existing diary...\n");
        while (fscanf(diary, "%s %ld\n", entries[num_entries].text, &entries[num_entries].timestamp)!= EOF) {
            num_entries++;
        }
        fclose(diary);
    }

    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        return 1;
    }

    time(&now);
    entries[num_entries].timestamp = now;
    printf("Please enter your first entry:\n");
    fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
    num_entries++;

    while (1) {
        time(&now);
        if (difftime(now, entries[num_entries - 1].timestamp) >= 86400) {
            printf("It's a new day! Please enter your entry for today:\n");
            fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
            entries[num_entries].timestamp = now;
            num_entries++;
        } else {
            printf("Please enter your entry for the day:\n");
            fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
            entries[num_entries].timestamp = now;
            num_entries++;
        }
    }

    fclose(diary);
    return 0;
}