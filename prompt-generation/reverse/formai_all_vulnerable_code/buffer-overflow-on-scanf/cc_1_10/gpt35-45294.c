//FormAI DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    int day;
    int month;
    int year;
    char entry[200];
};

struct DigitalDiary {
    int num_entries;
    struct DiaryEntry entries[MAX_ENTRIES];
};

/* Function to print the current entries in the diary */
void printEntries(struct DigitalDiary diary) {
    printf("\n\nDigital Diary Entries:\n\n");
    for(int i=0; i<diary.num_entries; i++) {
        printf("%d/%d/%d: %s\n", diary.entries[i].day, diary.entries[i].month, diary.entries[i].year, diary.entries[i].entry);
    }
}

int main() {
    printf("Welcome to the Brave Digital Diary!\n\n");
    printf("This diary can hold up to %d entries.\n", MAX_ENTRIES);

    /* Initialize the diary */
    struct DigitalDiary diary;
    diary.num_entries = 0;

    /* Keep asking the user for input until they decide to quit */
    while(1) {
        /* Print the menu options */
        printf("\nMenu Options:\n");
        printf("1. Add Entry\n");
        printf("2. Delete Entry\n");
        printf("3. View Entries\n");
        printf("4. Quit\n");
        printf("Enter option number (1-4): ");

        /* Read the user's choice */
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            /* Add Entry */
            case 1:
                /* Check if the diary is full */
                if(diary.num_entries >= MAX_ENTRIES) {
                    printf("\nThe diary is full.\n");
                    break;
                }

                /* Ask the user for input */
                printf("\nEnter the date for your entry (dd mm yyyy): ");
                int day, month, year;
                scanf("%d %d %d", &day, &month, &year);
                printf("\nEnter your diary entry (max 200 characters): ");
                char entry[200];
                scanf(" %[^\n]s", entry);

                /* Add the entry to the diary */
                diary.entries[diary.num_entries].day = day;
                diary.entries[diary.num_entries].month = month;
                diary.entries[diary.num_entries].year = year;
                strncpy(diary.entries[diary.num_entries].entry, entry, 200);
                diary.num_entries++;
                printf("\nEntry added to diary.\n");
                break;

            /* Delete Entry */
            case 2:
                /* Check if the diary is empty */
                if(diary.num_entries == 0) {
                    printf("\nThe diary is empty.\n");
                    break;
                }

                /* Ask the user for the entry number to delete */
                printf("\nEnter the entry number to delete (1-%d): ", diary.num_entries);
                int entry_num;
                scanf("%d", &entry_num);

                /* Delete the corresponding entry */
                for(int i=entry_num-1; i<diary.num_entries-1; i++) {
                    diary.entries[i] = diary.entries[i+1];
                }
                diary.num_entries--;
                printf("\nEntry deleted from diary.\n");
                break;

            /* View Entries */
            case 3:
                /* Check if the diary is empty */
                if(diary.num_entries == 0) {
                    printf("\nThe diary is empty.\n");
                    break;
                }

                /* Print the entries */
                printEntries(diary);
                break;

            /* Quit */
            case 4:
                printf("\nGoodbye!\n");
                exit(0);

            /* Invalid Choice */
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}