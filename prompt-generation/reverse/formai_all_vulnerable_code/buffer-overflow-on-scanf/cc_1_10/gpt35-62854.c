//FormAI DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Define a structure to hold the contact information of a person
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Define a structure for the linked list node
typedef struct Node {
    Contact contact; // data of the node
    struct Node *next; // pointer to the next node
} Node;

// Define function to create a new node
Node* createNode(Contact contact) {
    Node *new_node = (Node*)malloc(sizeof(Node)); // allocate memory for the new node
    new_node->contact = contact; // initialize the contact field
    new_node->next = NULL; // initialize the next pointer field
}

// Define function to insert a new node to the list
void insertNode(Node **head_ref, Contact contact) {
    Node *new_node = createNode(contact); // create a new node
    new_node->next = (*head_ref); // set the next pointer of new node to the current head of the list
    (*head_ref) = new_node; // set the head of the list to the new node
}

// Define function to search for a node in the list
Node* searchNode(Node *head, char *search_name) {
    Node *current = head; // start at the head of the list
    while (current != NULL) { // traverse the list until the end
        if (strcmp(current->contact.name, search_name) == 0) { // found a matching node
            return current; // return a pointer to the node
        }
        current = current->next; // move on to the next node
    }
    // if no matching node was found, return NULL
    return NULL;
}

// Define function to delete a node from the list
void deleteNode(Node **head_ref, char *delete_name) {
    Node *current = (*head_ref); // start at the head of the list
    Node *prev = NULL; // to keep track of the previous node

    // case where the head of the list needs to be deleted
    if (current != NULL && strcmp(current->contact.name, delete_name) == 0) {
        (*head_ref) = current->next; // change the head of the list to the next node
        free(current); // deallocate the memory of the deleted node
        return;
    }

    // traverse the list until the end or a matching node is found
    while (current != NULL && strcmp(current->contact.name, delete_name) != 0) {
        prev = current; // move the previous pointer to the current node
        current = current->next; // move the current pointer to the next node
    }

    if (current == NULL) { // no matching node was found, do nothing
        return;
    }

    // unlink the current node from the list
    prev->next = current->next;

    // deallocate the memory of the deleted node
    free(current);
}

// Define function to print all nodes in the list
void printList(Node *head) {
    Node *current = head; // start at the head of the list
    int count = 0; // to keep track of the number of nodes printed
    while (current != NULL) { // traverse the list until the end
        printf("Contact #%d: %s <%s>\n", ++count, current->contact.name, current->contact.email);
        current = current->next; // move on to the next node
    }
}

int main() {
    Node *head = NULL; // initialize the head of the list to NULL
    char choice;
    Contact contact;
    Node *search_result;

    do {
        printf("\n=========================================\n");
        printf("Mailing list manager\n");
        printf("=========================================\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Display all contacts\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                fflush(stdin);
                scanf("%[^\n]", contact.name);
                printf("Enter email: ");
                fflush(stdin);
                scanf("%s", contact.email);
                insertNode(&head, contact); // add the contact to the list
                printf("Contact added.\n");
                break;
            case '2':
                printf("Enter name to search: ");
                fflush(stdin);
                scanf("%[^\n]", contact.name);
                search_result = searchNode(head, contact.name); // search for the contact in the list
                if (search_result != NULL) {
                    printf("Contact found: %s <%s>\n", search_result->contact.name, search_result->contact.email);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case '3':
                printf("Enter name to delete: ");
                fflush(stdin);
                scanf("%[^\n]", contact.name);
                deleteNode(&head, contact.name); // delete the contact from the list
                printf("Contact deleted.\n");
                break;
            case '4':
                printList(head); // display all contacts in the list
                break;
            case '5':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '5');

    return 0;
}