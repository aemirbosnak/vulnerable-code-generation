//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIARY_ENTRIES 100

struct diary_entry {
    char title[50];
    char body[100];
    time_t date;
};

void print_diary_entry(struct diary_entry entry) {
    printf("%s\n\n", entry.title);
    printf("%s\n\n", entry.body);
    printf("Written on %s\n", ctime(&entry.date));
}

int main() {
    struct diary_entry diary[MAX_DIARY_ENTRIES];
    int num_entries = 0;

    printf("Welcome to your lively C digital diary!\n");
    printf("What would you like to do?\n");
    printf("1. Write a new entry\n");
    printf("2. View an existing entry\n");
    printf("3. Quit\n");

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_entries >= MAX_DIARY_ENTRIES) {
                    printf("Diary is full, please delete an entry first.\n");
                    break;
                }

                printf("Enter the title of your entry: ");
                scanf("%s", diary[num_entries].title);

                printf("Enter the body of your entry: ");
                scanf("%s", diary[num_entries].body);

                diary[num_entries].date = time(NULL);

                num_entries++;

                printf("Entry added successfully!\n");
                break;
            }

            case 2: {
                if (num_entries == 0) {
                    printf("No entries found.\n");
                    break;
                }

                printf("Which entry would you like to view? (1-%d): ", num_entries);
                int entry_num;
                scanf("%d", &entry_num);

                if (entry_num < 1 || entry_num > num_entries) {
                    printf("Invalid entry number.\n");
                    break;
                }

                print_diary_entry(diary[entry_num - 1]);
                break;
            }

            case 3: {
                printf("Goodbye!\n");
                return 0;
            }

            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }

    return 0;
}