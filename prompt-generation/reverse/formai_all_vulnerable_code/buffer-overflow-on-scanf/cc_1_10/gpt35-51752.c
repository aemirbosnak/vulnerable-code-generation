//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct ListNode ListNode;

struct ListNode {
    Contact contact;
    ListNode* next;
};

ListNode* create_node(Contact contact) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node -> contact = contact;
    node -> next = NULL;
    return node;
}

void print_contact(Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Email: %s\n", contact.email);
    printf("Phone: %s\n", contact.phone);
}

void print_list(ListNode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List contents:\n");
    int counter = 1;
    while (head != NULL) {
        printf("%d)\n", counter);
        print_contact(head->contact);
        head = head -> next;
        counter++;
    }
}

void insert_node(ListNode** head_ref, Contact contact) {
    ListNode* new_node = create_node(contact);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    ListNode* current_node = *head_ref;
    while (current_node -> next != NULL) {
        current_node = current_node -> next;
    }
    current_node -> next = new_node;
}

int delete_node(ListNode** head_ref, char* email){ 
    ListNode* temp = *head_ref, *prev; 
  
    if (temp != NULL && strcmp(temp->contact.email, email) == 0) 
    { 
        *head_ref = temp->next;   
        free(temp);               
        return 1; 
    } 
  
    while (temp != NULL && strcmp(temp->contact.email, email) != 0) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    if (temp == NULL) return 0; 
  
    prev->next = temp->next; 
  
    free(temp); 
  
    return 1;
} 

int main() {
    ListNode* head = NULL;
    char choice;
    do {
        printf("\nEnter choice:\n");
        printf("a) Add contact\n");
        printf("b) Print contacts\n");
        printf("c) Delete contact\n");
        printf("d) Exit program\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
            {
                Contact new_contact;
                printf("Enter name: ");
                scanf("%s", new_contact.name);
                printf("Enter email: ");
                scanf("%s", new_contact.email);
                printf("Enter phone: ");
                scanf("%s", new_contact.phone);
                insert_node(&head, new_contact);
                printf("New contact added to list.\n");
                break;
            }
            case 'b':
            {
                print_list(head);
                break;
            }
            case 'c':
            {
                char email[MAX_EMAIL_LENGTH];
                printf("Enter email of contact to delete: ");
                scanf("%s", email);
                int success = delete_node(&head, email);
                if (success) {
                    printf("Contact deleted.\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 'd':
            {
                printf("Exiting program, good bye!\n");
                break;
            }
            default:
            {
                printf("Invalid choice, please try again.\n");
                break;
            }
        }
    } while (choice != 'd');
    return 0;
}