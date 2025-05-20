//FormAI DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    char date[11];
    char title[50];
    char content[500];
};

struct DiaryEntry diary[MAX_ENTRIES];
int num_entries = 0;

void display_menu() {
    printf("\nDigital Diary\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Edit Entry\n");
    printf("4. Delete Entry\n");
    printf("5. View All Entries\n");
    printf("6. Exit\n\n");
}

void get_date(char *date) {
    time_t now;
    struct tm *tm;

    now = time(0);
    tm = localtime(&now);

    sprintf(date, "%02d/%02d/%04d", tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900);
}

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("Diary is full\n");
        return;
    }

    char date[11];
    get_date(date);

    printf("Title: ");
    scanf(" %[^\n]s", diary[num_entries].title);
    printf("Content: ");
    scanf(" %[^\n]s", diary[num_entries].content);

    strcpy(diary[num_entries].date, date);

    num_entries++;

    printf("Entry Added Successfully!\n");
}

void view_entry() {
    if (num_entries == 0) {
        printf("Diary is Empty\n");
        return;
    }

    int index;
    printf("Enter Index of Entry to View: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_entries) {
        printf("Invalid Index\n");
        return;
    }

    struct DiaryEntry entry = diary[index];

    printf("Date: %s\n", entry.date);
    printf("Title: %s\n", entry.title);
    printf("Content: %s\n", entry.content);
}

void edit_entry() {
    if (num_entries == 0) {
        printf("Diary is Empty\n");
        return;
    }

    int index;
    printf("Enter Index of Entry to Edit: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_entries) {
        printf("Invalid Index\n");
        return;
    }

    printf("Title: ");
    scanf(" %[^\n]s", diary[index].title);
    printf("Content: ");
    scanf(" %[^\n]s", diary[index].content);

    printf("Entry Edited Successfully!\n");
}

void delete_entry() {
    if (num_entries == 0) {
        printf("Diary is Empty\n");
        return;
    }

    int index;
    printf("Enter Index of Entry to Delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_entries) {
        printf("Invalid Index\n");
        return;
    }

    for (int i = index; i < num_entries-1; i++) {
        diary[i] = diary[i+1];
    }

    num_entries--;

    printf("Entry Deleted Successfully!\n");
}

void view_all_entries() {
    if (num_entries == 0) {
        printf("Diary is Empty\n");
        return;
    }

    printf("Digital Diary - All Entries\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%d. %s - %s\n", i, diary[i].date, diary[i].title);
    }
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entry();
                break;
            case 3:
                edit_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                view_all_entries();
                break;
            case 6:
                printf("Thank You for Using Digital Diary!\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (choice != 6);

    return 0;
}