//FormAI DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[20];
} PhoneBookEntry;

int count = 0;
PhoneBookEntry phonebook[MAX_ENTRIES];

void add_entry();
void delete_entry();
void search_entry();
void display_all();
void save_to_file();
void read_from_file();

int main() {

    int choice;

    read_from_file();

    while (1) {
        printf("\n------Menu------\n1. Add New Entry\n2. Delete an Entry\n3. Search\n4. Display All Entries\n5. Save to File\n6. Exit\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice) {
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
                display_all();
                break;

            case 5:
                save_to_file();
                break;

            case 6:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void add_entry() {
    if (count == MAX_ENTRIES) {
        printf("\nPhonebook is full. Cannot add more entries.\n");
        return;
    }

    printf("\nEnter Name:");
    scanf("%s", phonebook[count].name);

    printf("Enter Phone Number:");
    scanf("%s", phonebook[count].number);

    count++;
    printf("\nEntry added successfully!\n");
}

void delete_entry() {
    if (count == 0) {
        printf("\nPhonebook is empty.\n");
        return;
    }

    char nameToDelete[50];
    printf("\nEnter name to delete:");
    scanf("%s", nameToDelete);

    int idxToDelete = -1;

    for (int i = 0; i < count; i++) {
        if (strcmp(nameToDelete, phonebook[i].name) == 0) {
            idxToDelete = i;
            break;
        }
    }

    if (idxToDelete == -1) {
        printf("\nEntry not found.\n");
        return;
    }

    for (int i = idxToDelete; i < count - 1; i++) {
        phonebook[i] = phonebook[i + 1];
    }

    count--;
    printf("\nEntry deleted successfully!\n");
}

void search_entry() {
    if (count == 0) {
        printf("\nPhonebook is empty.\n");
        return;
    }

    char nameToSearch[50];
    printf("\nEnter name to search:");
    scanf("%s", nameToSearch);

    for (int i = 0; i < count; i++) {
        if (strcmp(nameToSearch, phonebook[i].name) == 0) {
            printf("\nName: %s\nPhone Number: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("\nEntry not found.\n");
}

void display_all() {
    if (count == 0) {
        printf("\nPhonebook is empty.\n");
        return;
    }

    printf("\n------All Phonebook Entries------\n");

    for (int i = 0; i < count; i++) {
        printf("Name: %s\nPhone Number: %s\n\n", phonebook[i].name, phonebook[i].number);
    }
}

void save_to_file() {
    FILE* fptr;
    fptr = fopen("phonebook.txt", "w");
    if (fptr == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fptr, "%s\n%s\n", phonebook[i].name, phonebook[i].number);
    }

    fclose(fptr);
    printf("\nEntries saved to file successfully!\n");
}

void read_from_file() {
    FILE* fptr;
    fptr = fopen("phonebook.txt", "r");
    if (fptr == NULL) {
        printf("\nFile not found.\n");
        return;
    }

    char name[50], number[20];
    while (fscanf(fptr, "%s%s", name, number) == 2) {
        strcpy(phonebook[count].name, name);
        strcpy(phonebook[count].number, number);
        count++;
    }

    fclose(fptr);
    printf("\nEntries loaded from file successfully!\n");
}