//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 1000

struct entry {
    char text[MAX_ENTRY_LEN];
    time_t timestamp;
};

int main() {
    FILE *diary;
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];

    diary = fopen("diary.txt", "r");
    if (diary == NULL) {
        fprintf(stderr, "Error: could not open diary file.\n");
        exit(1);
    }

    while (fscanf(diary, "%s %ld\n", entries[num_entries].text, &entries[num_entries].timestamp) == 2) {
        num_entries++;
        if (num_entries == MAX_ENTRIES) {
            fprintf(stderr, "Error: too many entries in diary.\n");
            exit(1);
        }
    }

    fclose(diary);

    diary = fopen("diary.txt", "a");
    if (diary == NULL) {
        fprintf(stderr, "Error: could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("Enter your thoughts:\n");
        fgets(entries[num_entries].text, MAX_ENTRY_LEN, stdin);
        entries[num_entries].timestamp = time(NULL);

        if (fwrite(&entries[num_entries], sizeof(struct entry), 1, diary)!= 1) {
            fprintf(stderr, "Error: could not write to diary file.\n");
            exit(1);
        }

        num_entries++;
        if (num_entries == MAX_ENTRIES) {
            fprintf(stderr, "Error: too many entries in diary.\n");
            exit(1);
        }

        printf("Entry saved.\n");
    }

    fclose(diary);

    return 0;
}