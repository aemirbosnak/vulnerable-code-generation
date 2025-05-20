//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIARY_ENTRIES 30

struct DiaryEntry {
    char message[100];
    time_t timestamp;
};

int main() {
    struct DiaryEntry entries[MAX_DIARY_ENTRIES];
    int num_entries = 0;

    printf("Welcome to your romantic digital diary!\n");

    while (1) {
        char command[100];
        printf("Enter a command (add, read, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (num_entries >= MAX_DIARY_ENTRIES) {
                printf("Sorry, your diary is full. Delete some entries to make room.\n");
                continue;
            }
            printf("Enter a message to add to your diary: ");
            scanf("%s", entries[num_entries].message);
            entries[num_entries].timestamp = time(NULL);
            num_entries++;
        } else if (strcmp(command, "read") == 0) {
            if (num_entries == 0) {
                printf("Your diary is empty. Add some entries to read.\n");
                continue;
            }
            printf("Here's your diary:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s (%s)\n", entries[i].message, ctime(&entries[i].timestamp));
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    printf("Goodbye!\n");

    return 0;
}