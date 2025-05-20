//FormAI DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

typedef struct phone_book_entry_t {
    char name[MAX_LENGTH];
    char phone_number[MAX_LENGTH];
    struct phone_book_entry_t* next;
} phone_book_entry;

phone_book_entry* create_entry(char name[], char phone_number[]);
void add_entry(phone_book_entry** head, char name[], char phone_number[]);
void delete_entry(phone_book_entry** head, char name[]);
void search_entry(phone_book_entry* head, char name[]);
void display_book(phone_book_entry* head);
void free_book(phone_book_entry** head);

int main() {
    phone_book_entry* phone_book = NULL;
    char user_input[MAX_LENGTH];
    int choice = 0;

    printf("Welcome to your C Phone Book!\n");

    while (1) {
        printf("\nPlease select an action:\n");
        printf("1. Add an entry\n");
        printf("2. Delete an entry\n");
        printf("3. Search for an entry\n");
        printf("4. Display the phone book\n");
        printf("5. Exit\n");

        scanf("%d", &choice);
        fflush(stdin); // clears input buffer

        switch(choice) {
            case 1:
                printf("Please enter the name: ");
                fgets(user_input, MAX_LENGTH, stdin);
                strtok(user_input, "\n"); // removes newline character from input
                char name[MAX_LENGTH];
                strcpy(name, user_input);

                printf("Please enter the phone number: ");
                fgets(user_input, MAX_LENGTH, stdin);
                strtok(user_input, "\n");
                char phone_number[MAX_LENGTH];
                strcpy(phone_number, user_input);

                add_entry(&phone_book, name, phone_number);
                printf("%s has been added to the phone book.\n", name);
                break;

            case 2:
                printf("Please enter the name of the entry you would like to delete: ");
                fgets(user_input, MAX_LENGTH, stdin);
                strtok(user_input, "\n");
                delete_entry(&phone_book, user_input);
                break;

            case 3:
                printf("Please enter the name of the entry you would like to search for: ");
                fgets(user_input, MAX_LENGTH, stdin);
                strtok(user_input, "\n");
                search_entry(phone_book, user_input);
                break;

            case 4:
                display_book(phone_book);
                break;

            case 5:
                free_book(&phone_book);
                printf("Thank you for using your C Phone Book!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

phone_book_entry* create_entry(char name[], char phone_number[]) {
    phone_book_entry* new_entry = (phone_book_entry*) malloc(sizeof(phone_book_entry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->phone_number, phone_number);
    new_entry->next = NULL;

    return new_entry;
}

void add_entry(phone_book_entry** head, char name[], char phone_number[]) {
    phone_book_entry* new_entry = create_entry(name, phone_number);

    if (*head == NULL) {
        *head = new_entry;
        return;
    }

    phone_book_entry* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_entry;
}

void delete_entry(phone_book_entry** head, char name[]) {
    if (*head == NULL) {
        printf("Phone book is already empty.\n");
        return;
    }

    phone_book_entry* current = *head;
    phone_book_entry* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%s not found in phone book.\n", name);
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    printf("%s has been deleted from the phone book.\n", name);
    free(current);
}

void search_entry(phone_book_entry* head, char name[]) {
    if (head == NULL) {
        printf("Phone book is empty.\n");
        return;
    }

    phone_book_entry* current = head;

    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("%s not found in phone book.\n", name);
    } else {
        printf("%s's phone number is %s.\n", current->name, current->phone_number);
    }
}

void display_book(phone_book_entry* head) {
    if (head == NULL) {
        printf("Phone book is empty.\n");
        return;
    }

    phone_book_entry* current = head;

    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone_number);
        current = current->next;
    }
}

void free_book(phone_book_entry** head) {
    phone_book_entry* current = *head;

    while (current != NULL) {
        phone_book_entry* temp = current;
        current = current->next;
        free(temp);
    }

    *head = NULL;
}