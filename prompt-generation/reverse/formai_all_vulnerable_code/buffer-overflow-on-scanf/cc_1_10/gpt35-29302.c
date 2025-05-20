//FormAI DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_ENTRIES 1000

struct Entry {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int count = 0;
struct Entry entries[MAX_ENTRIES];

void print_menu()
{
    printf("\n");
    printf("Manage Mailing List\n");
    printf("===================\n");
    printf("1. Add New Entry\n");
    printf("2. Delete Entry\n");
    printf("3. Search for Entry by Name\n");
    printf("4. List All Entries\n");
    printf("5. Exit\n");
}

void add_entry()
{
    if(count >= MAX_ENTRIES) {
        printf("Mailing list is full. Cannot add any more entries.\n");
        return;
    }
    
    struct Entry new_entry;
    printf("Enter name: ");
    scanf("%s", new_entry.name);
    printf("Enter email: ");
    scanf("%s", new_entry.email);
    
    entries[count++] = new_entry;
    printf("Entry added successfully.\n");
}

void delete_entry()
{
    char name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    
    int deleted = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            for(int j = i; j < count - 1; j++) {
                entries[j] = entries[j+1];
            }
            count--;
            printf("Entry deleted successfully.\n");
            deleted = 1;
            break;
        }
    }
    
    if(!deleted) {
        printf("No entry found with name '%s'.\n", name);
    }
}

void search_entry()
{
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Email: %s\n", entries[i].email);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("No entry found with name '%s'.\n", name);
    }
}

void list_entries()
{
    for(int i = 0; i < count; i++) {
        printf("Name: %s\n", entries[i].name);
        printf("Email: %s\n", entries[i].email);
        printf("------------------------\n");
    }
    
    if(count == 0) {
        printf("Mailing list is empty.\n");
    }
}

int main()
{
    int choice = 0;
    while(choice != 5) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                delete_entry();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                list_entries();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}