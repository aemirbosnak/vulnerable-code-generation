//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[50];
    int age;
    char email[50];
    struct person *next;
} Person;

Person *head = NULL;

void add_person() {
    Person *new_person = (Person*)malloc(sizeof(Person));
    printf("Enter name: ");
    scanf("%s", new_person->name);
    printf("Enter age: ");
    scanf("%d", &new_person->age);
    printf("Enter email: ");
    scanf("%s", new_person->email);
    new_person->next = head;
    head = new_person;
}

void print_list() {
    Person *current = head;
    if(current == NULL) {
        printf("Mailing list is empty.\n");
    } else {
        while(current != NULL) {
            printf("Name: %s\nAge: %d\nEmail: %s\n", current->name, current->age, current->email);
            current = current->next;
        }
    }
}

void delete_person() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    Person *current = head;
    Person *previous = NULL;
    while(current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if(current == NULL) {
        printf("Person not found.\n");
    } else {
        if(previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        printf("%s has been deleted from the mailing list.\n", name);
        free(current);
    }   
}

int main() {
    int choice;
    do {
        printf("\nMailing List Manager\n");
        printf("-----------------------------\n");
        printf("1. Add person to list\n");
        printf("2. Delete person from list\n");
        printf("3. Print mailing list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_person();
                break;
            case 2:
                delete_person();
                break;
            case 3:
                print_list();
                break;
            case 4:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}