//FormAI DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct diary_entry {
    char date[20];
    char title[50];
    char content[1000];
} diary_entry;

void print_menu() {
    printf("\nChoose an option:\n");
    printf("1. Write a new entry\n");
    printf("2. View an existing entry\n");
    printf("3. Exit\n");
}

void write_entry(diary_entry *entries, int *num_entries) {
    printf("\nEnter the date (DD/MM/YYYY): ");
    scanf("%s", entries[*num_entries].date);
    printf("Enter a title: ");
    scanf(" %[^\n]s", entries[*num_entries].title);
    printf("Enter content: ");
    scanf(" %[^\n]s", entries[*num_entries].content);
    (*num_entries)++;
    printf("\nEntry added!\n");
}

void view_entry(diary_entry *entries, int num_entries) {
    char search_date[20], search_title[50];
    int found = 0;

    printf("\nEnter the date of the entry you want to view (DD/MM/YYYY): ");
    scanf("%s", search_date);
    printf("Enter the title of the entry: ");
    scanf(" %[^\n]s", search_title);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(search_date, entries[i].date) == 0 && strcmp(search_title, entries[i].title) == 0) {
            printf("\n%s", entries[i].date);
            printf("\n%s", entries[i].title);
            printf("\n%s\n", entries[i].content);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo entry found with that date and title.\n");
    }
}

int main() {
    diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int option = 0;

    printf("Welcome to your digital diary!\n");

    while (option != 3) {
        print_menu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                write_entry(entries, &num_entries);
                break;
            case 2:
                view_entry(entries, num_entries);
                break;
            case 3:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}