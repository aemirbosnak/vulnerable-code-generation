//FormAI DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
    char title[50];
    char content[500];
    char date[20];
};

void print_menu(void);
void print_entry(struct entry *e);
void print_all_entries(struct entry *entries, int count);
void add_entry(struct entry **entries, int *count);
void list_entries_menu(struct entry *entries, int count);
void delete_entry(struct entry **entries, int *count);
void save_entries(struct entry *entries, int count);
void load_entries(struct entry **entries, int *count);

int main(void) {
    struct entry *entries = NULL;
    int count = 0;
    int choice;

    load_entries(&entries, &count);

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(&entries, &count);
                printf("Entry added!\n");
                break;
            case 2:
                list_entries_menu(entries, count);
                break;
            case 3:
                delete_entry(&entries, &count);
                printf("Entry deleted!\n");
                break;
            case 4:
                save_entries(entries, count);
                printf("Entries saved!\n");
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

void print_menu(void) {
    printf("\nMENU\n");
    printf("==========================\n");
    printf("1. Add Diary Entry\n");
    printf("2. List all Entries\n");
    printf("3. Delete an Entry\n");
    printf("4. Save Entries\n");
    printf("5. Exit\n");
}

void print_entry(struct entry *e) {
    printf("==========================\n");
    printf("Title: %s\n", e->title);
    printf("Date: %s\n", e->date);
    printf("--------------------------\n");
    printf("%s\n", e->content);
    printf("==========================\n");
}

void print_all_entries(struct entry *entries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, entries[i].title);
    }
}

void add_entry(struct entry **entries, int *count) {
    struct entry e;

    printf("Enter Title: ");
    scanf(" %[^\n]", e.title);

    printf("Enter Date (DD/MM/YYYY): ");
    scanf(" %[^\n]", e.date);

    printf("Enter Content: ");
    scanf(" %[^\n]", e.content);

    (*count)++;
    *entries = realloc(*entries, *count * sizeof(struct entry));
    (*entries)[*count - 1] = e;
}

void list_entries_menu(struct entry *entries, int count) {
    int choice;

    while (1) {
        printf("\nLIST ENTRIES MENU\n");
        printf("==========================\n");

        if (count == 0) {
            printf("No entries found!\n");
            return;
        }

        print_all_entries(entries, count);

        printf("Enter the entry number to view or 0 to return to main menu: ");
        scanf("%d", &choice);

        if (choice == 0) {
            return;
        } else if (choice > count || choice < 0) {
            printf("Invalid choice!\n");
        } else {
            print_entry(&entries[choice - 1]);
        }
    }
}

void delete_entry(struct entry **entries, int *count) {
    int choice;

    while (1) {
        printf("\nDELETE AN ENTRY\n");
        printf("==========================\n");

        if (*count == 0) {
            printf("No entries found!\n");
            return;
        }

        print_all_entries(*entries, *count);

        printf("Enter entry number to delete or 0 to return to main menu: ");
        scanf("%d", &choice);

        if (choice == 0) {
            return;
        } else if (choice > *count || choice < 0) {
            printf("Invalid choice!\n");
        } else {
            for (int i = choice - 1; i < *count - 1; i++) {
                (*entries)[i] = (*entries)[i + 1];
            }

            (*count)--;
            *entries = realloc(*entries, *count * sizeof(struct entry));
            return;
        }
    }
}

void save_entries(struct entry *entries, int count) {
    FILE *fp;

    fp = fopen("digital_diary.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", entries[i].title);
        fprintf(fp, "%s\n", entries[i].date);
        fprintf(fp, "%s\n", entries[i].content);
    }

    fclose(fp);
}

void load_entries(struct entry **entries, int *count) {
    FILE *fp;
    char title[50];
    char date[20];
    char content[500];

    fp = fopen("digital_diary.txt", "r");

    if (fp == NULL) {
        return;
    }

    while (fscanf(fp, " %[^\n]", title) != EOF &&
           fscanf(fp, " %[^\n]", date) != EOF &&
           fscanf(fp, " %[^\n]", content) != EOF) {
        struct entry e = {
            .title = "",
            .date = "",
            .content = ""
        };

        strcpy(e.title, title);
        strcpy(e.date, date);
        strcpy(e.content, content);

        (*count)++;
        *entries = realloc(*entries, *count * sizeof(struct entry));
        (*entries)[*count - 1] = e;
    }

    fclose(fp);
}