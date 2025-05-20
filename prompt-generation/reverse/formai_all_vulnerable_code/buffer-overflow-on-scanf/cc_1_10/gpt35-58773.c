//FormAI DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void menu();
void add_entry();
void view_entry(int n);
void edit_entry(int n);
void delete_entry(int n);

struct diary {
    char date[20];
    char entry[1000];
};

struct diary diary_entries[100];
int entries_count = 0;

int main() {
    printf("Welcome to your digital diary!\n");
    menu();
    return 0;
}

void menu() {
    printf("\nWhat would you like to do?\n");
    printf("1. Add a new entry\n");
    printf("2. View an existing entry\n");
    printf("3. Edit an existing entry\n");
    printf("4. Delete an existing entry\n");
    printf("5. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1: add_entry(); break;
        case 2: {
            printf("\nEnter entry number: ");
            int n;
            scanf("%d", &n);
            view_entry(n);
            break;
        }
        case 3: {
            printf("\nEnter entry number: ");
            int n;
            scanf("%d", &n);
            edit_entry(n);
            break;
        }
        case 4: {
            printf("\nEnter entry number: ");
            int n;
            scanf("%d", &n);
            delete_entry(n);
            break;
        }
        case 5: exit(0); break;
        default: printf("\nInvalid choice. Try again.");
    }
    menu();
}

void add_entry() {
    printf("\nEnter date (YYYY-MM-DD): ");
    scanf("%s", diary_entries[entries_count].date);
    printf("\nEnter entry (max 1000 characters):\n");
    scanf(" %[^\n]", diary_entries[entries_count].entry);
    entries_count++;
}

void view_entry(int n) {
    if(n < 1 || n > entries_count) {
        printf("\nInvalid entry number.\n");
        return;
    }
    printf("\nDate: %s\n", diary_entries[n-1].date);
    printf("Entry:\n%s", diary_entries[n-1].entry);
}

void edit_entry(int n) {
    if(n < 1 || n > entries_count) {
        printf("\nInvalid entry number.\n");
        return;
    }
    printf("\nEnter new date (YYYY-MM-DD): ");
    scanf("%s", diary_entries[n-1].date);
    printf("\nEnter new entry (max 1000 characters):\n");
    scanf(" %[^\n]", diary_entries[n-1].entry);
    printf("\nEntry updated successfully!\n");
}

void delete_entry(int n) {
    if(n < 1 || n > entries_count) {
        printf("\nInvalid entry number.\n");
        return;
    }
    for(int i=n-1; i<entries_count-1; i++) {
        diary_entries[i] = diary_entries[i+1];
    }
    entries_count--;
    printf("\nEntry deleted successfully!\n");
}