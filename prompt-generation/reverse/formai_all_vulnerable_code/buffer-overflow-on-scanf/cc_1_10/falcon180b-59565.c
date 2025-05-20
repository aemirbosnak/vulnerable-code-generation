//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

void add_entry(entry_t *entries, int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);
    
    printf("Enter phone number: ");
    scanf("%s", entries[count].phone);
    
    count++;
}

void search_entry(entry_t *entries, int count, char *name) {
    int i;
    
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }
    
    printf("Entry not found.\n");
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;
    
    printf("Phone Book\n");
    
    while (count < MAX_ENTRIES) {
        printf("1. Add Entry\n2. Search Entry\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_entry(entries, count);
                break;
                
            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(entries, count, name);
                break;
                
            case 3:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}