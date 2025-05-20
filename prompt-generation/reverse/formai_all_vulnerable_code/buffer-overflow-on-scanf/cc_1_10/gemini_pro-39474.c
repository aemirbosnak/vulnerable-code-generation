//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIST_SIZE 100

typedef struct mail_list_entry {
    char name[50];
    char email[50];
    struct mail_list_entry *next;
} mail_list_entry;

mail_list_entry *head = NULL;
int list_size = 0;

void add_entry(char *name, char *email) {
    mail_list_entry *new_entry = malloc(sizeof(mail_list_entry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);
    new_entry->next = NULL;
    if (head == NULL) {
        head = new_entry;
    } else {
        mail_list_entry *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
    list_size++;
}

void remove_entry(char *name) {
    if (head == NULL) {
        return;
    }
    if (strcmp(head->name, name) == 0) {
        head = head->next;
        free(head);
        list_size--;
        return;
    }
    mail_list_entry *current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->name, name) == 0) {
            mail_list_entry *temp = current->next;
            current->next = current->next->next;
            free(temp);
            list_size--;
            return;
        }
        current = current->next;
    }
}

void print_list() {
    mail_list_entry *current = head;
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    char input[100];
    char name[50];
    char email[50];
    int choice;
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add an entry\n");
        printf("2. Remove an entry\n");
        printf("3. Print the list\n");
        printf("4. Quit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the name: ");
                scanf(" %[^\n]", name);
                printf("Enter the email: ");
                scanf(" %[^\n]", email);
                add_entry(name, email);
                break;
            case 2:
                printf("Enter the name to remove: ");
                scanf(" %[^\n]", name);
                remove_entry(name);
                break;
            case 3:
                print_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}