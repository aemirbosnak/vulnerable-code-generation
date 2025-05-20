//FormAI DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[20];
    char phone_number[13];
} Contact;

int index_of(char* name, Contact* list, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(name, list[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_contact(Contact* list, int* size) {
    if (*size >= MAX_SIZE) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", list[*size].name);
    printf("Enter phone number: ");
    scanf("%s", list[*size].phone_number);
    (*size)++;
}

void remove_contact(Contact* list, int* size) {
    char name[20];
    printf("Enter name of contact to remove: ");
    scanf("%s", name);
    int index = index_of(name, list, *size);
    if (index == -1) {
        printf("Contact not found!\n");
        return;
    }
    for (int i = index + 1; i < *size; i++) {
        list[i - 1] = list[i];
    }
    (*size)--;
    printf("Contact removed successfully.\n");
}

void show_contacts(Contact* list, int size) {
    if (size == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    printf("%-20s %-13s\n", "Name", "Phone Number");
    for (int i = 0; i < size; i++) {
        printf("%-20s %-13s\n", list[i].name, list[i].phone_number);
    }
}

void search_contacts(Contact* list, int size) {
    if (size == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    char name[20];
    printf("Enter name of contact to search: ");
    scanf("%s", name);
    int index = index_of(name, list, size);
    if (index == -1) {
        printf("Contact not found!\n");
        return;
    }
    printf("%-20s %-13s\n", "Name", "Phone Number");
    printf("%-20s %-13s\n", list[index].name, list[index].phone_number);
}

int main() {
    Contact phone_book[MAX_SIZE];
    int size = 0;
    int choice;
    do {
        printf("\n1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Show contacts\n");
        printf("4. Search contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(phone_book, &size);
                break;
            case 2:
                remove_contact(phone_book, &size);
                break;
            case 3:
                show_contacts(phone_book, size);
                break;
            case 4:
                search_contacts(phone_book, size);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}