//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[15];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void delete_entry() {
    int index;
    printf("Enter index of entry to delete: ");
    scanf("%d", &index);
    if(index >= 0 && index < num_entries) {
        memset(&entries[index], 0, sizeof(entry_t));
        num_entries--;
    } else {
        printf("Invalid index.\n");
    }
}

void search_entry() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int index = -1;
    for(int i = 0; i < num_entries; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if(index!= -1) {
        printf("Phone number: %s\n", entries[index].number);
    } else {
        printf("Entry not found.\n");
    }
}

void print_entries() {
    for(int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Print entries\n");
        printf("5. Exit\n");
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
                print_entries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}