//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for contact
struct contact {
    char name[50];
    char phone_number[15];
    struct contact *next;
};

// Declare function prototypes
void add_contact(struct contact **list);
void delete_contact(struct contact **list, char name[]);
void search_contact(struct contact *list, char name[]);
void display_contacts(struct contact *list);
void save_contacts(struct contact *list);
void load_contacts(struct contact **list);

// Main function
int main() {
    struct contact *list = NULL;
    int choice;
    char name[50];
    
    load_contacts(&list);
    
    do {
        printf("\n\n--- Phone Book ---\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_contact(&list);
                break;
            case 2:
                printf("Enter the name of contact to delete: ");
                scanf("%s", name);
                delete_contact(&list, name);
                break;
            case 3:
                printf("Enter the name of contact to search: ");
                scanf("%s", name);
                search_contact(list, name);
                break;
            case 4:
                display_contacts(list);
                break;
            case 5:
                save_contacts(list);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);
    
    return 0;
}

// Function to add a contact
void add_contact(struct contact **list) {
    struct contact *new_contact = malloc(sizeof(struct contact));
    printf("Enter the name of contact: ");
    scanf("%s", new_contact->name);
    printf("Enter the phone number of contact: ");
    scanf("%s", new_contact->phone_number);
    new_contact->next = NULL;
    
    if(*list == NULL) {
        *list = new_contact;
    }
    else {
        struct contact *temp = *list;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_contact;
    }
    
    printf("Contact added successfully!\n");
}

// Function to delete a contact
void delete_contact(struct contact **list, char name[]) {
    struct contact *prev = NULL, *curr = *list;
    
    while(curr != NULL) {
        if(strcmp(curr->name, name) == 0) {
            if(prev == NULL) {
                *list = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Contact deleted successfully!\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    
    printf("Contact not found!\n");
}

// Function to search a contact
void search_contact(struct contact *list, char name[]) {
    if(list == NULL) {
        printf("Phone book is empty!\n");
        return;
    }
    
    if(strcmp(list->name, name) == 0) {
        printf("Name: %s\nPhone number: %s\n", list->name, list->phone_number);
        return;
    }
    
    search_contact(list->next, name);
}

// Function to display all contacts
void display_contacts(struct contact *list) {
    if(list == NULL) {
        printf("Phone book is empty!\n");
        return;
    }
    
    printf("Contact List:\n");
    while(list != NULL) {
        printf("Name: %s\nPhone number: %s\n\n", list->name, list->phone_number);
        list = list->next;
    }
}

// Function to save contacts to file
void save_contacts(struct contact *list) {
    FILE *file = fopen("phonebook.dat", "w");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    while(list != NULL) {
        fprintf(file, "%s,%s\n", list->name, list->phone_number);
        list = list->next;
    }
    
    fclose(file);
}

// Function to load contacts from file
void load_contacts(struct contact **list) {
    FILE *file = fopen("phonebook.dat", "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    char line[100], *token;
    struct contact *last_contact = NULL;
    
    while(fgets(line, sizeof(line), file) != NULL) {
        struct contact *new_contact = malloc(sizeof(struct contact));
        token = strtok(line, ",");
        strcpy(new_contact->name, token);
        token = strtok(NULL, ",");
        strcpy(new_contact->phone_number, token);
        new_contact->next = NULL;
        
        if(*list == NULL) {
            *list = new_contact;
        }
        else {
            last_contact->next = new_contact;
        }
        
        last_contact = new_contact;
    }
    
    fclose(file);
}