//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_PERSONS 10

typedef struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Person* next;
} Person;

int main() {
    Person* head = NULL;
    Person* current = NULL;
    int choice, i;

    while(1) {
        printf("\n1. Add Person\n2. Display Persons\n3. Delete Person\n4. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if((current = (Person*) malloc(sizeof(Person))) == NULL) {
                    printf("Memory allocation failed!\n");
                    break;
                }
                printf("Enter Name: ");
                scanf("%s", current->name);
                printf("Enter Age: ");
                scanf("%d", &current->age);
                current->next = head;
                head = current;
                break;

            case 2:
                if(head == NULL) {
                    printf("No Persons present!\n");
                    break;
                }

                current = head;
                printf("\nPersons present:\n");
                while(current != NULL) {
                    printf("\nName: %s\nAge: %d", current->name, current->age);
                    current = current->next;
                }
                break;

            case 3:
                if(head == NULL) {
                    printf("No Persons present!\n");
                    break;
                }

                i = 1;
                current = head;
                while(current->next != NULL && i < current->age) {
                    current = current->next;
                    i++;
                }

                if(current->next == NULL) {
                    printf("Person of given age not found!\n");
                    break;
                }

                Person* temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;

            case 4:
                while(head != NULL) {
                    Person* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}