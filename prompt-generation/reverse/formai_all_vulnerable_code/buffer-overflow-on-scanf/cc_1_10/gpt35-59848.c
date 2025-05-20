//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct phonebook {
    char name[30];
    char phone[15];
    struct phonebook* next;
};

void add_contact(struct phonebook** head) {
    struct phonebook* new_contact = (struct phonebook*)malloc(sizeof(struct phonebook));
    printf("Enter name:\n");
    gets(new_contact->name);
    printf("Enter phone number:\n");
    gets(new_contact->phone);
    new_contact->next = (*head);
    (*head) = new_contact;
    printf("%s has been added to your phone book!\n\n", new_contact->name);
}

void search_contact(struct phonebook* head, char* search_name) {
    if (head == NULL) { 
        printf("%s is not in your phone book.\n\n", search_name);
        return;
    }
    if (strcmp(head->name, search_name) == 0) {
        printf("Name: %s\nPhone Number: %s\n\n", head->name, head->phone);
        return;
    }
    search_contact(head->next, search_name);
}

void delete_contact(struct phonebook** head, char* delete_name) {
    struct phonebook* temp = *head, *prev;
    if (temp != NULL && strcmp(temp->name, delete_name) == 0) {
        *head = temp->next;
        free(temp);
        printf("%s has been deleted from your phone book!\n\n", delete_name);
        return;
    }
    while (temp != NULL && strcmp(temp->name, delete_name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%s is not in your phone book.\n\n", delete_name);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%s has been deleted from your phone book!\n\n", delete_name);
}

void display_phonebook(struct phonebook* head) {
    if (head == NULL) {
        printf("Your phone book is empty.\n\n");
        return;
    }
    printf("Your phone book:\n");
    while (head != NULL) {
        printf("---------------------------\n");
        printf("Name: %s\n", head->name);
        printf("Phone Number: %s\n", head->phone);
        head = head->next;
    }
    printf("---------------------------\n\n");
}

int main() {
    struct phonebook* head = NULL;
    int choice;
    char search_name[30], delete_name[30];
    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Display phone book\n5. Quit\n");
        scanf("%d", &choice);
        getchar(); //to get rid of the newline character in the input buffer
        switch (choice) {
        case 1:
            add_contact(&head);
            break;
        case 2:
            printf("Enter name to search:\n");
            gets(search_name);
            search_contact(head, search_name);
            break;
        case 3:
            printf("Enter name to delete:\n");
            gets(delete_name);
            delete_contact(&head, delete_name);
            break;
        case 4:
            display_phonebook(head);
            break;
        case 5:
            printf("Thank you for using the C Phone Book program!\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n\n");
        }
    }
    return 0;
}