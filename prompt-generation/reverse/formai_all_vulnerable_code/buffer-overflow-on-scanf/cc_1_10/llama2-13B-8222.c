//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    char date[20];
    char entry[ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    if (num_entries == MAX_ENTRIES) {
        printf("Digital diary is full. Please delete some entries before adding new ones.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void view_entries() {
    printf("Digital Diary\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    while (1) {
        printf("Add Entry: ");
        char date[20];
        char entry[ENTRY_LENGTH];
        fgets(date, 20, stdin);
        fgets(entry, ENTRY_LENGTH, stdin);

        add_entry(date, entry);

        printf("View Entries: ");
        view_entries();

        printf("Quit: ");
        char quit;
        scanf("%c", &quit);

        if (quit == 'q' || quit == 'Q') {
            break;
        }
    }

    return 0;
}