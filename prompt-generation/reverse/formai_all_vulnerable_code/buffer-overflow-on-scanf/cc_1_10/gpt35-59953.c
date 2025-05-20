//FormAI DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_ENTRIES  100
 
struct diary_entry {
    char date[20];
    char content[1000];
};
 
struct diary {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries;
};
 
void print_menu() {
    printf("\n**DIGITAL DIARY**\n\n");
    printf("1. View all entries\n");
    printf("2. Add an entry\n");
    printf("3. Exit\n\n");
    printf("Enter your choice: ");
}
 
void view_entries(struct diary *diary) {
    printf("\n**ALL ENTRIES**\n\n");
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Date: %s\n", diary->entries[i].date);
        printf("Content: %s\n", diary->entries[i].content);
        printf("---------------------------\n");
    }
}
 
void add_entry(struct diary *diary) {
    printf("\n**ADD AN ENTRY**\n\n");
    printf("Enter the date (DD-MM-YYYY): ");
    char date[20];
    scanf("%s", date);
    printf("\nEnter the content (max 1000 characters):\n");
    char content[1000];
    scanf(" %[^\n]", content);
 
    strcpy(diary->entries[diary->num_entries].date, date);
    strcpy(diary->entries[diary->num_entries].content, content);
    diary->num_entries++;
 
    printf("\nEntry added successfully!\n");
}
 
int main() {
    struct diary my_diary = { .num_entries = 0 };
    int choice;
 
    do {
        print_menu();
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                view_entries(&my_diary);
                break;
            case 2:
                add_entry(&my_diary);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
 
    } while (choice != 3);
 
    return 0;
}