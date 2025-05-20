//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].phone);

    num_entries++;
}

void view_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    printf("Name: %s\nPhone number: %s\n", phonebook[index].name, phonebook[index].phone);
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    num_entries--;

    for (int i = index; i < num_entries; i++) {
        strcpy(phonebook[i].name, phonebook[i+1].name);
        strcpy(phonebook[i].phone, phonebook[i+1].phone);
    }
}

void search_entry(char *name) {
    int index = -1;

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Entry not found.\n");
    } else {
        view_entry(index);
    }
}

int main() {
    int choice;

    do {
        printf("\nPhone book options:\n");
        printf("1. Add entry\n2. View entry\n3. Delete entry\n4. Search entry\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                printf("Enter index: ");
                int index;
                scanf("%d", &index);
                view_entry(index);
                break;
            case 3:
                printf("Enter index: ");
                int index_del;
                scanf("%d", &index_del);
                delete_entry(index_del);
                break;
            case 4:
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                search_entry(name);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}