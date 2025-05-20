//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Linked list node to store a person's information
typedef struct Person {
    char name[50];
    char email[50];
    struct Person *next;
} Person;

//Function to add a person to the mailing list
void addPerson(Person **list, char name[], char email[]) {
    //Allocate space for new person node
    Person *newPerson = (Person*) malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    strcpy(newPerson->email, email);
    newPerson->next = NULL;
    
    //If list is empty, make new person the head node
    if (*list == NULL) {
        *list = newPerson;
    }
    //Otherwise, add new person to end of list
    else {
        Person *current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPerson;
    }
}

//Function to remove a person from the mailing list
void removePerson(Person **list, char email[]) {
    //If email matches head node, remove head node
    if (strcmp((*list)->email, email) == 0) {
        Person *temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    //Otherwise, remove person from list
    else {
        Person *current = *list;
        while (current->next != NULL) {
            if (strcmp(current->next->email, email) == 0) {
                Person *temp = current->next;
                current->next = current->next->next;
                free(temp);
                return;
            }
            current = current->next;
        }
        printf("Person with email %s not found.\n", email);
    }
}

//Function to print all people in the mailing list
void printList(Person *list) {
    if (list == NULL) {
        printf("Mailing list is empty.\n");
    }
    else {
        printf("Mailing List:\n");
        while (list != NULL) {
            printf("%s <%s>\n", list->name, list->email);
            list = list->next;
        }
    }
}

int main() {
    //Initialize empty mailing list
    Person *list = NULL;
    char name[50];
    char email[50];
    int choice;
    
    //Main program loop
    do {
        printf("\n1. Add person to mailing list\n");
        printf("2. Remove person from mailing list\n");
        printf("3. Print mailing list\n");
        printf("4. Exit program\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addPerson(&list, name, email);
                printf("Person added to mailing list.\n");
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                removePerson(&list, email);
                break;
            case 3:
                printList(list);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 4.\n");
                break;
        }
        
    } while (choice != 4);
    
    //Free memory for all nodes in the mailing list
    Person *current = list;
    while (current != NULL) {
        Person *temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}