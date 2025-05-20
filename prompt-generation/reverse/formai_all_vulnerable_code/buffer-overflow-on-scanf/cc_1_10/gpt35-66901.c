//FormAI DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char title[50];
    char date[20];
    char content[500];
} DiaryEntry;

int num_entries = 0;
DiaryEntry *entries;

void save_entry(DiaryEntry entry) {
    FILE *fp = fopen("diary.txt", "a");
    fprintf(fp, "%s\n%s\n%s\n\n", entry.title, entry.date, entry.content);
    fclose(fp);
}

void display_menu() {
    printf("\nWelcome to your Digital Diary!\n");
    printf("Enter the number corresponding to the option you want:\n");
    printf("1 - View all entries\n");
    printf("2 - Add a new entry\n");
    printf("3 - Exit\n");
}

void view_entries() {
    if(num_entries == 0) {
        printf("\nYour digital diary is empty!\n");
    } else {
        printf("\nHere are all your entries:\n");
        for(int i = 0; i < num_entries; i++) {
            printf("\n---------------------------\n");
            printf("Title: %s", entries[i].title);
            printf("Date: %s", entries[i].date);
            printf("Content:\n%s", entries[i].content);
        }
    }
}

void add_entry() {
    DiaryEntry new_entry;
    printf("\nEnter the title for your new entry:\n");
    fgets(new_entry.title, 50, stdin);
    new_entry.title[strcspn(new_entry.title, "\n")] = 0;
    printf("\nEnter the date for your new entry (YYYY/MM/DD):\n");
    fgets(new_entry.date, 20, stdin);
    new_entry.date[strcspn(new_entry.date, "\n")] = 0;
    printf("\nEnter the content for your new entry:\n");
    fgets(new_entry.content, 500, stdin);
    new_entry.content[strcspn(new_entry.content, "\n")] = 0;
    printf("\nEntry added!\n");
    save_entry(new_entry);
    num_entries++;
    entries = realloc(entries, num_entries * sizeof(DiaryEntry));
    entries[num_entries-1] = new_entry;
}

int main() {
    entries = malloc(0);

    printf("Enter password to continue: ");
    char password[20];
    scanf("%s", password); 
    if(strcmp(password, "digitaldiary123") == 0) {
        int choice = 0;
        while(choice != 3) {
            display_menu();
            scanf("%d", &choice);
            while(getchar() != '\n');
            switch(choice) {
                case 1:
                    view_entries();
                    break;
                case 2:
                    add_entry();
                    break;
                case 3:
                    printf("\nExiting Digital Diary...\n");
                    break;
                default:
                    printf("\nInvalid choice. Please try again.\n");
                    break;
            }
        }
    } else {
        printf("\nInvalid password. Access denied.\n");
        return 1;
    }

    free(entries);
    return 0;
}