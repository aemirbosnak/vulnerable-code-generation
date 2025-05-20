//FormAI DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing the information of a person
struct Person {
    char name[50];
    int age;
    char gender;
};

// Structure for storing the information of a person node
struct Node {
    struct Person person;
    struct Node* next;
};

// Declare the head of the database
struct Node* head = NULL;

// Function to add a person to the database
void add_person() {
    struct Person new_person;
    printf("Enter name: ");
    scanf("%s", new_person.name);
    printf("Enter age: ");
    scanf("%d", &new_person.age);
    printf("Enter gender (m/f): ");
    scanf(" %c", &new_person.gender);
    printf("\n");

    // Create a new node and add it to the front of the list
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->person = new_person;
    new_node->next = head;
    head = new_node;
}

// Function to print all the people in the database
void print_database() {
    struct Node* current_node = head;
    while (current_node != NULL) {
        printf("%s, %d, %c\n", current_node->person.name, current_node->person.age, current_node->person.gender);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to delete a person from the database
void delete_person() {
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);

    struct Node* previous_node = NULL;
    struct Node* current_node = head;

    while (current_node != NULL) {
        if (strcmp(current_node->person.name, name) == 0) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            printf("Deleted person %s from the database.\n\n", name);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Person %s not found in the database.\n\n", name);
}

int main() {
    int option;
    do {
        printf("C Database Simulation\n");
        printf("---------------------\n");
        printf("1. Add person\n");
        printf("2. Print all people\n");
        printf("3. Delete person\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 1:
                add_person();
                break;
            case 2:
                print_database();
                break;
            case 3:
                delete_person();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n\n");
                break;
        }
    } while (option != 4);

    return 0;
}