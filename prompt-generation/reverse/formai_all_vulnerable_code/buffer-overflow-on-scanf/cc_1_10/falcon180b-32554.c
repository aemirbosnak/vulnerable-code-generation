//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 200

typedef struct {
    char name[50];
    char phone[15];
} entry;

void menu() {
    printf("Phone Book Menu:\n");
    printf("1. Add entry\n");
    printf("2. Search entry\n");
    printf("3. Display all entries\n");
    printf("4. Exit\n");
}

int main() {
    entry entries[MAX_ENTRIES];
    int num_entries = 0;
    
    printf("Welcome to the Phone Book!\n");
    while(1) {
        menu();
        int choice = scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", entries[num_entries].name);
                printf("Enter phone number: ");
                scanf("%s", entries[num_entries].phone);
                num_entries++;
                break;
            case 2:
                printf("Enter name to search: ");
                char search_name[50];
                scanf("%s", search_name);
                int found = 0;
                for(int i=0; i<num_entries; i++) {
                    if(strcmp(entries[i].name, search_name) == 0) {
                        printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Entry not found.\n");
                }
                break;
            case 3:
                printf("All entries:\n");
                for(int i=0; i<num_entries; i++) {
                    printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
                }
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}