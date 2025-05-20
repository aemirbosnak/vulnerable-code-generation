//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact{
    char name[20];
    char phone[20];
    char email[50];
    struct contact *next;
};

typedef struct contact Contact;

Contact* createContact(char *name, char *phone, char *email){
    Contact *newContact = malloc(sizeof(Contact));
    if(newContact == NULL){
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    strcpy(newContact->email, email);
    newContact->next = NULL;
    return newContact;
}

Contact* addContact(Contact *head, Contact *newContact){
    if(head == NULL){
        return newContact;
    }
    Contact *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newContact;
    return head;
}

void deleteContact(Contact **head, char *name){
    Contact *temp = *head;
    Contact *prev;
    if(temp != NULL && strcmp(temp->name, name) == 0){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && strcmp(temp->name, name) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Contact not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

Contact* searchContact(Contact *head, char *name){
    Contact *temp = head;
    while(temp != NULL){
        if(strcmp(temp->name, name) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printList(Contact *head){
    Contact *temp = head;
    if(temp == NULL){
        printf("Phone book is empty\n");
        return;
    }
    printf("************PHONE BOOK**************\n");
    while(temp != NULL){
        printf("Name: %s\nPhone: %s\nEmail: %s\n", temp->name, temp->phone, temp->email);
        temp = temp->next;
    }
}

int main(){
    Contact *head = NULL;
    int choice;
    char name[20], phone[20], email[50];

    printf("*************CYBERPUNK PHONE BOOK***************\n");
    while(1){
        printf("\nEnter your choice:\n1. Add a contact\n2. Delete a contact\n3. Search a contact\n4. Display all contacts\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the name: ");
                scanf("%s", name);
                printf("Enter the phone: ");
                scanf("%s", phone);
                printf("Enter the email: ");
                scanf("%s", email);
                head = addContact(head, createContact(name, phone, email));
                printf("Contact added successfully!\n");
                break;
            case 2:
                printf("\nEnter the name of the contact to be deleted: ");
                scanf("%s", name);
                deleteContact(&head, name);
                break;
            case 3:
                printf("\nEnter the name to be searched: ");
                scanf("%s", name);
                Contact *search = searchContact(head, name);
                if(search == NULL){
                    printf("Contact not found\n");
                }
                else{
                    printf("Name: %s\nPhone: %s\nEmail: %s\n", search->name, search->phone, search->email);
                }
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}