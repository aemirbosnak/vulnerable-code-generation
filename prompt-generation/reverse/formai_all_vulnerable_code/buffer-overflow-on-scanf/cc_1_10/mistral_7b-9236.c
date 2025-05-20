//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Survivor {
    char name[MAX_LEN];
    int age;
    struct Survivor* next;
} Survivor;

Survivor* head = NULL;

void add_survivor(char* name, int age) {
    Survivor* new_survivor = (Survivor*) malloc(sizeof(Survivor));
    strcpy(new_survivor->name, name);
    new_survivor->age = age;
    new_survivor->next = head;
    head = new_survivor;
}

void print_survivor_list() {
    Survivor* current = head;
    while (current != NULL) {
        printf("Name: %s, Age: %d\n", current->name, current->age);
        current = current->next;
    }
}

int main() {
    char name[MAX_LEN];
    int age, choice;

    while (1) {
        printf("\nPost-Apocalyptic Survivor List\n");
        printf("1. Add survivor\n");
        printf("2. Print survivor list\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter survivor name: ");
                scanf("%s", name);
                printf("Enter survivor age: ");
                scanf("%d", &age);
                add_survivor(name, age);
                break;
            case 2:
                print_survivor_list();
                break;
            case 3:
                printf("Exiting...\n");
                Survivor* current = head;
                while (current != NULL) {
                    Survivor* temp = current;
                    current = current->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}