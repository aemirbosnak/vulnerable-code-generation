//FormAI DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20

struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    struct Contact* next;
};

struct Contact* head = NULL;

void printMenu() {
    printf("1. Add contact\n");
    printf("2. List contacts\n");
    printf("3. Search contact\n");
    printf("4. Delete contact\n");
    printf("5. Save contacts to file\n");
    printf("6. Load contacts from file\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void addContact() {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    
    printf("Enter contact name: ");
    scanf("%s", newContact->name);
    
    printf("Enter contact email: ");
    scanf("%s", newContact->email);
    
    printf("Enter contact phone: ");
    scanf("%s", newContact->phone);
    
    newContact->next = NULL;
    
    if(head == NULL) {
        head = newContact;
    } else {
        struct Contact* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
    
    printf("Contact added successfully!\n");
}

void listContacts() {
    if(head == NULL) {
        printf("No contacts found!\n");
        return;
    }
    
    printf("Name\tEmail\t\t\tPhone\n");
    printf("----\t-----\t\t\t-----\n");
    
    struct Contact* current = head;
    while(current != NULL) {
        printf("%s\t%s\t\t%s\n", current->name, current->email, current->phone);
        current = current->next;
    }
}

void searchContact() {
    if(head == NULL) {
        printf("No contacts found!\n");
        return;
    }
    
    char name[MAX_NAME_LENGTH];
    printf("Enter contact name to search: ");
    scanf("%s", name);
    
    struct Contact* current = head;
    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            printf("Name\tEmail\t\t\tPhone\n");
            printf("----\t-----\t\t\t-----\n");
            printf("%s\t%s\t\t%s\n", current->name, current->email, current->phone);
            return;
        }
        current = current->next;
    }
    
    printf("Contact not found!\n");
}

void deleteContact() {
    if(head == NULL) {
        printf("No contacts found!\n");
        return;
    }
    
    char name[MAX_NAME_LENGTH];
    printf("Enter contact name to delete: ");
    scanf("%s", name);
    
    if(strcmp(head->name, name) == 0) {
        struct Contact* temp = head;
        head = head->next;
        free(temp);
        printf("Contact deleted successfully!\n");
        return;
    }
    
    struct Contact* current = head;
    while(current->next != NULL) {
        if(strcmp(current->next->name, name) == 0) {
            struct Contact* temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("Contact deleted successfully!\n");
            return;
        }
        current = current->next;
    }
    
    printf("Contact not found!\n");
}

void saveContactsToFile() {
    if(head == NULL) {
        printf("No contacts found!\n");
        return;
    }
    
    char filename[MAX_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    FILE* fp = fopen(filename, "w");
    
    if(fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }
    
    struct Contact* current = head;
    while(current != NULL) {
        fprintf(fp, "%s,%s,%s\n", current->name, current->email, current->phone);
        current = current->next;
    }
    
    fclose(fp);
    printf("Contacts saved to file successfully!\n");
}

void loadContactsFromFile() {
    char filename[MAX_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    FILE* fp = fopen(filename, "r");
    
    if(fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }
    
    char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + MAX_PHONE_LENGTH + 2];
    while(fgets(line, sizeof(line), fp) != NULL) {
        char* name = strtok(line, ",");
        char* email = strtok(NULL, ",");
        char* phone = strtok(NULL, ",");
        
        name[strcspn(name, "\r\n")] = 0;
        email[strcspn(email, "\r\n")] = 0;
        phone[strcspn(phone, "\r\n")] = 0;
        
        struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
        strcpy(newContact->name, name);
        strcpy(newContact->email, email);
        strcpy(newContact->phone, phone);
        newContact->next = NULL;
        
        if(head == NULL) {
            head = newContact;
        } else {
            struct Contact* current = head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = newContact;
        }
    }
    
    fclose(fp);
    printf("Contacts loaded from file successfully!\n");
}

int main() {
    while(1) {
        printMenu();
        
        int choice;
        scanf("%d", &choice);
        
        if(choice == 1) {
            addContact();
        } else if(choice == 2) {
            listContacts();
        } else if(choice == 3) {
            searchContact();
        } else if(choice == 4) {
            deleteContact();
        } else if(choice == 5) {
            saveContactsToFile();
        } else if(choice == 6) {
            loadContactsFromFile();
        } else if(choice == 7) {
            exit(0);
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}