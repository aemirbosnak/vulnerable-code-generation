#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char entry[256];
    int index;
} DiaryEntry;

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int num_entries = 0;

    char input[256];

    while (1) {
        printf("Enter diary entry (or 'q' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strchr(input, 'q') != NULL) {
            break;
        }

        if (num_entries >= MAX_ENTRIES) {
            printf("Diary is full.\n");
            continue;
        }

        strcpy(diary[num_entries].entry, input);
        diary[num_entries].index = num_entries;
        num_entries++;
    }

    printf("\nDiary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d: %s\n", diary[i].index, diary[i].entry);
    }

    return 0;
}
