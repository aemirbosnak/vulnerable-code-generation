//FormAI DATASET v1.0 Category: Mailing list manager ; Style: secure
// Mailing List Manager Example Program
// Written in C by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold each subscriber's information
typedef struct subscriber {
    char name[50];
    char email[100];
    struct subscriber* next;
} subscriber;

// Global variables to hold the beginning and end of the linked list
subscriber* head = NULL;
subscriber* tail = NULL;

// Function to add a subscriber to the linked list
void addSubscriber(char* name, char* email) {
    // Allocate memory for a new subscriber struct
    subscriber* newSubscriber = (subscriber*) malloc(sizeof(subscriber));
    
    // Copy the name and email into the struct
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);
    
    // Set the next pointer to NULL (since this is the new tail)
    newSubscriber->next = NULL;
    
    // If the list is empty, set the head and tail to the new subscriber
    if (head == NULL) {
        head = newSubscriber;
        tail = newSubscriber;
    } else {
        // Otherwise, link the new subscriber to the end of the list
        tail->next = newSubscriber;
        tail = newSubscriber;
    }
}

// Function to remove a subscriber from the linked list
void removeSubscriber(char* email) {
    // Check if the list is empty
    if (head == NULL) {
        printf("Mailing list is empty.\n");
        return;
    }
    
    // Check if the email matches the head of the list
    if (strcmp(head->email, email) == 0) {
        subscriber* temp = head;
        head = head->next;
        free(temp);
        printf("Subscriber removed: %s\n", email);
        return;
    }
    
    // Iterate through the list until we find the matching email
    subscriber* current = head;
    while (current->next != NULL && strcmp(current->next->email, email) != 0) {
        current = current->next;
    }
    
    // If we didn't find a matching email, print an error message
    if (current->next == NULL) {
        printf("Subscriber not found: %s\n", email);
        return;
    }
    
    // Otherwise, remove the subscriber from the list
    subscriber* temp = current->next;
    current->next = current->next->next;
    free(temp);
    printf("Subscriber removed: %s\n", email);
}

// Function to print all subscribers in the linked list
void printSubscribers() {
    // Check if the list is empty
    if (head == NULL) {
        printf("Mailing list is empty.\n");
        return;
    }
    
    // Iterate through the list and print each subscriber
    subscriber* current = head;
    while (current != NULL) {
        printf("Name: %s, Email: %s\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    // Initialize a buffer to hold user input
    char buffer[256];
    
    // Loop to read user input and perform corresponding actions
    while (1) {
        printf("Enter a command (add, remove, print, quit): ");
        fgets(buffer, 256, stdin);
        buffer[strlen(buffer) - 1] = '\0'; // Remove the newline character
        
        if (strcmp(buffer, "add") == 0) {
            // Prompt the user for name and email, then add the subscriber
            printf("Enter name: ");
            fgets(buffer, 256, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            char* name = malloc(strlen(buffer) + 1);
            strcpy(name, buffer);
            
            printf("Enter email: ");
            fgets(buffer, 256, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            char* email = malloc(strlen(buffer) + 1);
            strcpy(email, buffer);
            
            addSubscriber(name, email);
        } else if (strcmp(buffer, "remove") == 0) {
            // Prompt the user for the email to remove
            printf("Enter email to remove: ");
            fgets(buffer, 256, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            
            removeSubscriber(buffer);
        } else if (strcmp(buffer, "print") == 0) {
            // Print all subscribers in the list
            printSubscribers();
        } else if (strcmp(buffer, "quit") == 0) {
            // Free all memory and exit the program
            subscriber* current = head;
            subscriber* temp;
            while (current != NULL) {
                temp = current;
                current = current->next;
                free(temp);
            }
            printf("Exiting mailing list manager.\n");
            return 0;
        } else {
            // Invalid command - prompt the user again
            printf("Invalid command.\n");
        }
    }
}