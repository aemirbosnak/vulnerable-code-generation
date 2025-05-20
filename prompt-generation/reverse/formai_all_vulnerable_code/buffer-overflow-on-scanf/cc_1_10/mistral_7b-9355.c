//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char title[50];
    char description[200];
    char date[20];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void print_menu() {
    printf("\nDigital Diary Menu:\n");
    printf("1. Add new entry\n");
    printf("2. View entry\n");
    printf("3. Delete entry\n");
    printf("4. Search entry\n");
    printf("5. Exit\n");
}

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    printf("Enter title: ");
    fgets(diary[num_entries].title, ENTRY_SIZE, stdin);
    diary[num_entries].title[strcspn(diary[num_entries].title, "\n")] = '\0';

    printf("Enter description: ");
    fgets(diary[num_entries].description, ENTRY_SIZE, stdin);
    diary[num_entries].description[strcspn(diary[num_entries].description, "\n")] = '\0';

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);

    num_entries++;
}

void view_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index!\n");
        return;
    }

    printf("\nTitle: %s\n", diary[index].title);
    printf("Description: %s\n", diary[index].description);
    printf("Date: %s\n", diary[index].date);
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < num_entries; i++) {
        diary[i] = diary[i+1];
    }

    num_entries--;
}

void search_entry(char keyword[]) {
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].title, keyword) || strstr(diary[i].description, keyword)) {
            view_entry(i);
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    int choice;
    char keyword[20];

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &choice);
                view_entry(choice);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &choice);
                delete_entry(choice);
                break;
            case 4:
                printf("Enter keyword: ");
                scanf("%s", keyword);
                search_entry(keyword);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}