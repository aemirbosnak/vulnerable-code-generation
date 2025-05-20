//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

int main() {
    FILE *diary;
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[20];
    char choice;

    printf("Welcome to your digital diary!\n");
    printf("Please enter a filename for your diary: ");
    scanf("%s", filename);

    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add a new entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Save and exit\n");
        printf("Please choose an option: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Error: diary is full.\n");
                } else {
                    printf("Enter a date (YYYY-MM-DD): ");
                    scanf("%s", entries[num_entries].date);
                    printf("Enter your entry:\n");
                    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                    num_entries++;
                    printf("Entry added successfully!\n");
                }
                break;
            case '2':
                printf("Viewing all entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s - %s\n", entries[i].date, entries[i].entry);
                }
                break;
            case '3':
                printf("Enter a date to search for (YYYY-MM-DD): ");
                scanf("%s", filename);
                rewind(diary);
                while (fgets(entries[num_entries].date, 20, diary)!= NULL) {
                    if (strcmp(entries[num_entries].date, filename) == 0) {
                        printf("%s - %s\n", entries[num_entries].date, entries[num_entries].entry);
                    }
                    num_entries++;
                }
                break;
            case '4':
                printf("Saving diary and exiting...\n");
                for (int i = 0; i < num_entries; i++) {
                    fprintf(diary, "%s - %s\n", entries[i].date, entries[i].entry);
                }
                fclose(diary);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}