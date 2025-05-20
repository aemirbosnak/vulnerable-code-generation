//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char name[20];
    int age;
    char address[50];
} Person;

void addPerson(Person *people, int count) {
    printf("Enter name: ");
    scanf("%s", people[count].name);
    printf("Enter age: ");
    scanf("%d", &people[count].age);
    printf("Enter address: ");
    scanf("%s", people[count].address);
}

void displayPeople(Person *people, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Address: %s\n", people[i].address);
        printf("\n");
    }
}

int main() {
    Person people[SIZE];
    int count = 0;

    while (count < SIZE) {
        printf("Enter 1 to add a person, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addPerson(people, count);
            count++;
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    displayPeople(people, count);

    return 0;
}