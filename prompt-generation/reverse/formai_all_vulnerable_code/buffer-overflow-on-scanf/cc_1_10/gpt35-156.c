//FormAI DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DiaryEntry {
    char date[20];
    char title[50];
    char entry[500];
};

void print_menu();
void add_entry();
void view_entries();
void search_entries();
void save_entries();

struct DiaryEntry diary[100];
int num_entries = 0;

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                save_entries();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void print_menu() {
    printf("Digital Diary Menu:\n");
    printf("1. Add new diary entry\n");
    printf("2. View existing entries\n");
    printf("3. Search for an entry\n");
    printf("4. Save entries to file\n");
    printf("5. Exit program\n");
}

void add_entry() {
    printf("Please enter the date (MM/DD/YYYY): ");
    scanf("%s", diary[num_entries].date);
    printf("Please enter the title of the entry: ");
    scanf("%s", diary[num_entries].title);
    printf("Please enter the entry: ");
    scanf("%s", diary[num_entries].entry);
    num_entries++;
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Title: %s\n", diary[i].title);
        printf("Entry: %s\n", diary[i].entry);
        printf("----------------------------\n");
    }
}

void search_entries() {
    char query[50];
    printf("Please enter a search query: ");
    scanf("%s", query);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].entry, query) != NULL || strstr(diary[i].title, query) != NULL) {
            printf("Date: %s\n", diary[i].date);
            printf("Title: %s\n", diary[i].title);
            printf("Entry: %s\n", diary[i].entry);
            printf("----------------------------\n");
        }
    }
}

void save_entries() {
    FILE *fptr;
    fptr = fopen("diary.txt", "w");
    if (fptr == NULL) {
        printf("Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_entries; i++) {
        fprintf(fptr, "%s\n%s\n%s\n", diary[i].date, diary[i].title, diary[i].entry);
        fprintf(fptr, "----------------------------\n");
    }
    fclose(fptr);
    printf("Diary entries successfully saved to file.\n");
}