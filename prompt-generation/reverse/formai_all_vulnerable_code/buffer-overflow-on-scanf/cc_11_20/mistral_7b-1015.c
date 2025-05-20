//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ENTRIES 20
#define ENTRY_SIZE 100

typedef struct {
    char title[50];
    char description[ENTRY_SIZE];
    int happiness_level;
} DiaryEntry;

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice, title_length;
    char input[ENTRY_SIZE];

    printf("\n*********************************\n");
    printf("* Welcome to the Cheerful Diary! *\n");
    printf("*********************************\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Delete an entry\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_entries >= MAX_ENTRIES) {
                    printf("Sorry, your diary is full!\n");
                    continue;
                }
                printf("Enter a title for your entry: ");
                scanf("%s", input);
                title_length = strlen(input);
                strcpy(entries[num_entries].title, input);
                printf("Enter a description: ");
                fgets(entries[num_entries].description, ENTRY_SIZE, stdin);
                entries[num_entries].happiness_level = 5; // Default happiness level is 5
                num_entries++;
                break;
            case 2:
                if (num_entries == 0) {
                    printf("No entries to view!\n");
                    continue;
                }
                printf("\n--- Today's Entries ---\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("\n%s\n", entries[i].title);
                    printf("%s", entries[i].description);
                    printf("\nHappiness level: %d", entries[i].happiness_level);
                }
                break;
            case 3:
                if (num_entries == 0) {
                    printf("No entries to delete!\n");
                    continue;
                }
                printf("Enter the number of the entry you'd like to delete: ");
                int entry_number;
                scanf("%d", &entry_number);
                if (entry_number < 0 || entry_number >= num_entries) {
                    printf("Invalid entry number!\n");
                    continue;
                }
                for (int i = entry_number; i < num_entries - 1; i++) {
                    entries[i] = entries[i+1];
                }
                num_entries--;
                break;
            case 4:
                printf("\nGoodbye and have a wonderful day!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}