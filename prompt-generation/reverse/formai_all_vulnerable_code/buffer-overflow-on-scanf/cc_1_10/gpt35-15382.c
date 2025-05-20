//FormAI DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// phone book structure
typedef struct {
    char name[50];
    char number[20];
} entry;

// function prototypes
void add_entry(entry* pb, int* p_size);
int find_entry(entry* pb, int size, char* search_name);
void display_all(entry* pb, int size);
void delete_entry(entry* pb, int* p_size, int index);

int main() {
    entry phonebook[100];
    int size = 0;
    int choice;

    printf("Welcome to your Phone Book!\n");

    while (1) {
        // display menu
        printf("\n---MENU---\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Display all entries\n");
        printf("4. Delete an entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // handle user choice
        switch (choice) {
            case 1:
                add_entry(phonebook, &size);
                break;
            case 2: {
                char search_name[50];
                printf("Enter the name to search for: ");
                scanf("%s", search_name);
                int index = find_entry(phonebook, size, search_name);
                if (index != -1) {
                    printf("%s's number is %s\n", phonebook[index].name, phonebook[index].number);
                } else {
                    printf("Entry not found.\n");
                }
                break;
            }
            case 3:
                display_all(phonebook, size);
                break;
            case 4: {
                char search_name[50];
                printf("Enter the name to delete: ");
                scanf("%s", search_name);
                int index = find_entry(phonebook, size, search_name);
                if (index != -1) {
                    delete_entry(phonebook, &size, index);
                    printf("%s's entry has been deleted.\n", search_name);
                } else {
                    printf("Entry not found.\n");
                }
                break;
            }
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// function to add an entry to the phone book
void add_entry(entry* pb, int* p_size) {
    if (*p_size >= 100) {
        printf("Phone book is full. Cannot add entry.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", pb[*p_size].name);
    printf("Enter number: ");
    scanf("%s", pb[*p_size].number);

    (*p_size)++;
}

// function to search for an entry in the phone book
int find_entry(entry* pb, int size, char* search_name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(pb[i].name, search_name) == 0) {
            return i;
        }
    }

    return -1;
}

// function to display all entries in the phone book
void display_all(entry* pb, int size) {
    if (size == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("\n---PHONE BOOK---\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", pb[i].name, pb[i].number);
    }
}

// function to delete an entry from the phone book
void delete_entry(entry* pb, int* p_size, int index) {
    for (int i = index + 1; i < *p_size; i++) {
        strcpy(pb[i - 1].name, pb[i].name);
        strcpy(pb[i - 1].number, pb[i].number);
    }

    (*p_size)--;
}