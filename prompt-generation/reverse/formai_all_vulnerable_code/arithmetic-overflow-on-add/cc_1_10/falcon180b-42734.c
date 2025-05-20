//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    char input[MAX_ENTRY_LENGTH];
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    int current_entry = 0;
    FILE *file;

    srand(time(NULL));

    printf("Welcome to your digital diary!\n\n");

    while (1) {
        printf("What's on your mind?\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            printf("Nothing to say? That's okay.\n\n");
            continue;
        }

        if (num_entries >= MAX_ENTRIES) {
            printf("Diary is full! Please delete an entry to make room.\n\n");
            continue;
        }

        diary[num_entries].timestamp = time(NULL);
        strcpy(diary[num_entries].text, input);
        num_entries++;

        printf("Entry saved at %s\n\n", ctime(&diary[num_entries - 1].timestamp));

        if (num_entries == 1) {
            printf("This is your first entry! Would you like to set a reminder to write every day? (y/n)\n");
            char choice;
            scanf("%c", &choice);

            if (choice == 'y' || choice == 'Y') {
                printf("What time would you like your daily reminder? (HH:MM)\n");
                scanf("%s", input);
                struct tm reminder_time;
                strptime(input, "%H:%M", &reminder_time);
                time_t reminder_timestamp = mktime(&reminder_time) + 24 * 60 * 60; // add one day

                while (1) {
                    time_t current_timestamp = time(NULL);

                    if (current_timestamp >= reminder_timestamp) {
                        printf("Don't forget to write in your diary today!\n\n");
                        break;
                    }

                    sleep(60);
                }
            }
        }

        printf("\n");
        printf("Press enter to continue...\n");
        getchar();
    }

    return 0;
}