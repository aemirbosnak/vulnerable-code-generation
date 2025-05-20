//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define ENTRY_LENGTH 100

typedef struct {
    char title[ENTRY_LENGTH];
    char content[ENTRY_LENGTH];
    int index;
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *title, char *content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    strcpy(diary[num_entries].title, title);
    strcpy(diary[num_entries].content, content);
    diary[num_entries].index = num_entries;
    num_entries++;
}

void view_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid entry index.\n");
        return;
    }

    printf("\nTitle: %s\n", diary[index].title);
    printf("Content:\n%s\n", diary[index].content);
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid entry index.\n");
        return;
    }

    for (int i = index; i < num_entries - 1; i++) {
        diary[i] = diary[i + 1];
    }

    num_entries--;
}

void print_menu() {
    printf("\nDigital Diary\n");
    printf("1. Add entry\n");
    printf("2. View entry\n");
    printf("3. Delete entry\n");
    printf("4. Exit\n");
}

int main() {
    char title[ENTRY_LENGTH], content[ENTRY_LENGTH];
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]", content);
                add_entry(title, content);
                break;
            case 2:
                printf("Enter entry index: ");
                scanf("%d", &choice);
                view_entry(choice);
                break;
            case 3:
                printf("Enter entry index: ");
                scanf("%d", &choice);
                delete_entry(choice);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}