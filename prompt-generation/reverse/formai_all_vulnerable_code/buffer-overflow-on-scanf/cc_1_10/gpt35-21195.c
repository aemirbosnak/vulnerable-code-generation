//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store mailing list node information
typedef struct MailingListNode {
    char name[50];
    char email[50];
    struct MailingListNode *next;
} MailingListNode;

// Define a struct to store mailing list information
typedef struct {
    MailingListNode *head;
    int size;
} MailingList;

// Function to add a new person to the mailing list
void addPerson(MailingList *list, char *name, char *email) {
    // Create a new mailing list node
    MailingListNode *newNode = (MailingListNode*)malloc(sizeof(MailingListNode));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = NULL;
    
    // Insert the new node at the head of the list
    if(list->head == NULL) {
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
    
    list->size++;
}

// Function to remove a person from the mailing list
void removePerson(MailingList *list, char *email) {
    // Check if the list is empty
    if(list->head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }
    
    // Check if the person to be removed is at the head of the list
    if(strcmp(list->head->email, email) == 0) {
        MailingListNode *temp = list->head;
        list->head = list->head->next;
        free(temp);
        
        list->size--;
        return;
    }
    
    // Search for the person to be removed
    MailingListNode *currNode = list->head;
    while(currNode->next != NULL && strcmp(currNode->next->email, email) != 0) {
        currNode = currNode->next;
    }
    
    // Remove the person from the list
    if(currNode->next != NULL) {
        MailingListNode *temp = currNode->next;
        currNode->next = currNode->next->next;
        free(temp);
        
        list->size--;
    } else {
        printf("The person with email address %s was not found.\n", email);
    }
}

// Function to print the current mailing list
void printList(MailingList *list) {
    printf("Current Mailing List:\n");
    MailingListNode *currNode = list->head;
    while(currNode != NULL) {
        printf("%s, %s\n", currNode->name, currNode->email);
        currNode = currNode->next;
    }
    printf("Total of %d people on the list.\n", list->size);
}

int main() {
    printf("Welcome to the Mailing List Manager!\n");
    printf("Please enter the names and email addresses of the people you want to add to the mailing list.\n");
    
    // Create the mailing list
    MailingList list;
    list.head = NULL;
    list.size = 0;
    
    // Ask the user for input and add the people to the list
    char name[50], email[50], choice[10];
    do {
        printf("Name: ");
        scanf("%s", name);
        printf("Email: ");
        scanf("%s", email);
        addPerson(&list, name, email);
        
        printf("Add another person? (y/n) ");
        scanf("%s", choice);
    } while(strcmp(choice, "y") == 0);
    
    printList(&list);
    
    // Allow the user to remove people from the list
    do {
        printf("Enter the email address of the person you want to remove from the list (or enter 'q' to quit): ");
        scanf("%s", email);
        
        if(strcmp(email, "q") == 0) {
            break;
        }
        
        removePerson(&list, email);
        printList(&list);
    } while(1);
    
    printf("Thank you for using the Mailing List Manager!\n");
    
    return 0;
}