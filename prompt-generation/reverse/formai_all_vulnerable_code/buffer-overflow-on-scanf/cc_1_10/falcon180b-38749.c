//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t current_time;

    srand(time(NULL));
    current_time = time(NULL);

    while (1) {
        printf("Welcome to your digital diary!\n");
        printf("Press 'n' to write a new entry, 'r' to read an entry, or 'q' to quit.\n");
        scanf(" %c", &choice);

        switch (choice) {
        case 'n':
            if (num_entries >= MAX_ENTRIES) {
                printf("Sorry, you have reached the maximum number of entries.\n");
            } else {
                printf("Enter your new entry:\n");
                fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].timestamp = current_time;
                num_entries++;
                printf("Entry saved!\n");
            }
            break;
        case 'r':
            printf("Enter the index of the entry you want to read (0 to %d):\n", num_entries - 1);
            scanf("%d", &choice);
            if (choice >= 0 && choice < num_entries) {
                printf("Entry #%d:\n%s\n", choice, entries[choice].text);
            } else {
                printf("Invalid entry index.\n");
            }
            break;
        case 'q':
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}