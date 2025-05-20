//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[30];
    int phone_number;
}entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if(num_entries == MAX_ENTRIES) {
        printf("Phonebook is full!\n");
        return;
    }
    printf("Enter the name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter the phone number: ");
    scanf("%d", &phonebook[num_entries].phone_number);
    num_entries++;
    printf("Entry added successfully!\n");
}

void search_entry() {
    printf("Enter the name to search: ");
    char name[30];
    scanf("%s", name);
    int i = 0;
    while(i < num_entries) {
        if(strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s\nPhone Number: %d\n", phonebook[i].name, phonebook[i].phone_number);
            return;
        }
        i++;
    }
    printf("Entry not found!\n");
}

void delete_entry() {
    printf("Enter the name to delete: ");
    char name[30];
    scanf("%s", name);
    int i = 0;
    while(i < num_entries) {
        if(strcmp(name, phonebook[i].name) == 0) {
            for(int j = i; j < num_entries - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            num_entries--;
            return;
        }
        i++;
    }
    printf("Entry not found!\n");
}

void view_entries() {
    int i = 0;
    while(i < num_entries) {
        printf("Name: %s\nPhone Number: %d\n", phonebook[i].name, phonebook[i].phone_number);
        i++;
    }
}

int main() {
    int choice;
    do {
        printf("\nPhonebook\n1. Add Entry\n2. Search Entry\n3. Delete Entry\n4. View Entries\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                view_entries();
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