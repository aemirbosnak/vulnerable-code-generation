//FormAI DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact{
    char name[20];
    char phone[10];
    struct contact *next;
};

void add_contact(struct contact **head_ref, char name[], char phone[]){
    struct contact *new_contact = (struct contact*)malloc(sizeof(struct contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    new_contact->next = *head_ref;
    *head_ref = new_contact;
    printf("%s %s added to phone book.\n", name, phone);
}

void display_contacts(struct contact *head){
    printf("Phone Book:\n");
    while(head != NULL){
        printf("%s %s\n", head->name, head->phone);
        head = head->next;
    }
}

void search_contact(struct contact *head, char name[]){
    while(head != NULL){
        if(strcmp(head->name, name) == 0){
            printf("%s %s\n", head->name, head->phone);
            return;
        }
        head = head->next;
    }
    printf("Contact not found.\n");
}

void delete_contact(struct contact **head_ref, char name[]){
    struct contact *temp = *head_ref, *prev;
    if(temp != NULL && strcmp(temp->name, name) == 0){
        *head_ref = temp->next;
        free(temp);
        printf("%s deleted from phone book.\n", name);
        return;
    }
    while(temp != NULL && strcmp(temp->name, name) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Contact not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%s deleted from phone book.\n", name);
}

int main(){
    struct contact *head = NULL;
    int choice;
    char name[20], phone[10];
    while(1){
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                add_contact(&head, name, phone);
                break;
            case 2:
                display_contacts(head);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_contact(head, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_contact(&head, name);
                break;
            case 5:
                printf("Exiting phone book.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}