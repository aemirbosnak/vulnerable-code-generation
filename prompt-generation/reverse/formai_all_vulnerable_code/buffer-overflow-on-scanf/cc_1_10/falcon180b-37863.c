//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone_number[20];
} entry;

void add_entry(entry* entries, int num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].phone_number);
    num_entries++;
}

void search_entry(entry* entries, int num_entries) {
    printf("Enter name to search: ");
    char search_name[50];
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", entries[i].name, entries[i].phone_number);
            found = 1;
        }
    }
    if (!found) {
        printf("No entry found.\n");
    }
}

void delete_entry(entry* entries, int num_entries) {
    printf("Enter name to delete: ");
    char delete_name[50];
    scanf("%s", delete_name);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, delete_name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(entries[j].name, entries[j+1].name);
                strcpy(entries[j].phone_number, entries[j+1].phone_number);
            }
            num_entries--;
            found = 1;
        }
    }
    if (!found) {
        printf("No entry found.\n");
    }
}

int main() {
    entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                add_entry(entries, num_entries);
                break;
            case '2':
                search_entry(entries, num_entries);
                break;
            case '3':
                delete_entry(entries, num_entries);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '4');
    return 0;
}