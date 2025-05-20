//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 10000

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char input[MAX_ENTRY_LENGTH];
    printf("Enter your entry:\n");
    fgets(input, MAX_ENTRY_LENGTH, stdin);
    int input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n') {
        input[input_length - 1] = '\0';
    }
    strcpy(entries[num_entries].entry, input);
    time_t now = time(NULL);
    strftime(entries[num_entries].timestamp, 26, "%Y-%m-%d %H:%M:%S", localtime(&now));
    num_entries++;
}

void view_entries() {
    printf("Viewing %d entries:\n", num_entries);
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].timestamp, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("1. Add entry\n2. View entries\n3. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}