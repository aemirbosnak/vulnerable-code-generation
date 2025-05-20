//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LEN 100

struct diary_entry {
    char date[20];
    char content[MAX_LEN];
};

struct diary_entry entries[MAX_ENTRIES];
int entry_count = 0;

int main() {
    char choice;
    int i;

    printf("Welcome to the Digital Diary!\n");
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add entry\n");
        printf("2. View entry\n");
        printf("3. Delete entry\n");
        printf("4. Search entry\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[entry_count].date);
                printf("Enter your entry: ");
                fgets(entries[entry_count].content, MAX_LEN, stdin);
                entry_count++;
                break;
            case '2':
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[0].date);
                printf("Entry: %s\n", entries[0].content);
                break;
            case '3':
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[0].date);
                printf("Entry: %s\n", entries[0].content);
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[entry_count-1].date);
                printf("Entry: %s\n", entries[entry_count-1].content);
                entry_count--;
                break;
            case '4':
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[0].date);
                printf("Enter the search term: ");
                scanf("%s", entries[0].content);
                printf("Entry: %s\n", entries[0].content);
                break;
            case '5':
                printf("Bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}