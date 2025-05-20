//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[15];
} contact;

contact phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
}

void display_contacts() {
    printf("Phone Book:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].number);
    }
}

void search_contact() {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("%s - %s\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

void delete_contact() {
    char delete_name[50];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(phonebook[j].name, phonebook[j+1].name);
                strcpy(phonebook[j].number, phonebook[j+1].number);
            }
            num_entries--;
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add contact\n2. Display contacts\n3. Search contact\n4. Delete contact\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);
    return 0;
}