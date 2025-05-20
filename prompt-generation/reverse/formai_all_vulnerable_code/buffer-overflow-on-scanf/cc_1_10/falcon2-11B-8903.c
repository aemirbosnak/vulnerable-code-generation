//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diary_entry {
    char entry[100];
    char date[20];
    char time[20];
    struct diary_entry* next;
} diary_entry;

diary_entry* diary = NULL;
diary_entry* current = NULL;

void add_entry() {
    diary_entry* new_entry = (diary_entry*)malloc(sizeof(diary_entry));
    if (new_entry == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter your diary entry: ");
    scanf("%s", new_entry->entry);
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", new_entry->date);
    printf("Enter the time (hh:mm:ss): ");
    scanf("%s", new_entry->time);
    new_entry->next = NULL;

    if (diary == NULL) {
        diary = new_entry;
    } else {
        current->next = new_entry;
    }
    current = new_entry;
}

void delete_entry() {
    if (current == NULL) {
        printf("No entry to delete\n");
        return;
    }
    diary_entry* temp = diary;
    while (temp->next!= current) {
        temp = temp->next;
    }
    free(current);
    temp->next = NULL;
}

void view_entry() {
    if (current == NULL) {
        printf("No entry to view\n");
        return;
    }
    printf("Entry:\n%s\n", current->entry);
    printf("Date:\n%s\n", current->date);
    printf("Time:\n%s\n", current->time);
}

int main() {
    while (1) {
        printf("1. Add entry\n2. Delete entry\n3. View entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                delete_entry();
                break;
            case 3:
                view_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}