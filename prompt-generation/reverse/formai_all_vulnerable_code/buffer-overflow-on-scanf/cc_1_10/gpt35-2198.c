//FormAI DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct Entry {
    char title[50];
    char text[500];
    char date[20];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void display_menu() {
    clear_screen();
    printf("Welcome to your digital diary!\n");
    printf("1. Add a new entry\n");
    printf("2. Edit an existing entry\n");
    printf("3. Delete an entry\n");
    printf("4. View all entries\n");
    printf("5. Search entries\n");
    printf("6. Exit\n");
}

void add_entry() {
    clear_screen();
    Entry new_entry;

    printf("Enter title: ");
    fgets(new_entry.title, 50, stdin);
    printf("Enter entry text: ");
    fgets(new_entry.text, 500, stdin);

    time_t now = time(NULL);
    strftime(new_entry.date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    diary[num_entries++] = new_entry;

    printf("\nEntry added successfully!\n\n");
}

void edit_entry() {
    clear_screen();
    int id;
    printf("Enter the ID of the entry to edit: ");
    scanf("%d", &id);
    getchar();
    id--;
    if (id >= 0 && id < num_entries) {
        Entry *entry = &diary[id];
        printf("Current title: %s", entry->title);
        printf("Enter new title: ");
        fgets(entry->title, 50, stdin);
        printf("Current entry text: %s", entry->text);
        printf("Enter new entry text: ");
        fgets(entry->text, 500, stdin);
        time_t now = time(NULL);
        strftime(entry->date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
        printf("\nEntry edited successfully!\n\n");
    } else {
        printf("Invalid ID\n\n");
    }
}

void delete_entry() {
    clear_screen();
    int id;
    printf("Enter the ID of the entry to delete: ");
    scanf("%d", &id);
    getchar();
    id--;
    if (id >= 0 && id < num_entries) {
        for (int i = id; i < num_entries - 1; i++) {
            diary[i] = diary[i + 1];
        }
        num_entries--;
        printf("\nEntry deleted successfully!\n\n");
    } else {
        printf("Invalid ID\n\n");
    }
}

void view_all_entries() {
    clear_screen();
    if (num_entries == 0) {
        printf("No entries yet.\n");
    } else {
        printf("All entries:\n");
        for (int i = 0; i < num_entries; i++) {
            printf("ID: %d\n", i + 1);
            printf("Title: %s", diary[i].title);
            printf("Date: %s\n", diary[i].date);
            printf("Text: %s\n", diary[i].text);
            printf("\n");
        }
    }
}

void search_entries() {
    clear_screen();
    char search_str[50];
    printf("Enter search string: ");
    fgets(search_str, 50, stdin);
    printf("\nResults:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].title, search_str) != NULL ||
            strstr(diary[i].text, search_str) != NULL) {
            printf("ID: %d\n", i + 1);
            printf("Title: %s", diary[i].title);
            printf("Date: %s\n", diary[i].date);
            printf("Text: %s\n", diary[i].text);
            printf("\n");
        }
    }
}

void save_entries() {
    FILE *fp;
    fp = fopen("diary.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file for writing.\n");
        exit(1);
    }
    fwrite(diary, sizeof(Entry), num_entries, fp);
    fclose(fp);
}

void load_entries() {
    FILE *fp;
    fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file for reading.\n");
        exit(1);
    }
    num_entries = fread(diary, sizeof(Entry), MAX_ENTRIES, fp);
    fclose(fp);
}

int main() {
    load_entries();

    while (1) {
        display_menu();

        int choice;
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            edit_entry();
            break;
        case 3:
            delete_entry();
            break;
        case 4:
            view_all_entries();
            break;
        case 5:
            search_entries();
            break;
        case 6:
            save_entries();
            printf("\nGoodbye!\n");
            exit(0);
        default:
            printf("Invalid choice\n\n");
        }
    }

    return 0;
}