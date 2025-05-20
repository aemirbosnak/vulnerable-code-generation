//FormAI DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char address[50];
    char phone[15];
} Person;

void addPerson(Person *person, FILE *fp) {
    printf("Enter name: ");
    scanf("%s", person->name);
    printf("Enter age: ");
    scanf("%d", &person->age);
    printf("Enter address: ");
    scanf("%s", person->address);
    printf("Enter phone number: ");
    scanf("%s", person->phone);
    fwrite(person, sizeof(Person), 1, fp);
}

void displayPerson(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Address: %s\n", person.address);
    printf("Phone number: %s\n", person.phone);
    printf("=====================================\n");
}

void displayAllPersons(FILE *fp) {
    Person person;
    while(fread(&person, sizeof(Person), 1, fp)) {
        displayPerson(person);
    }
}

int main() {
    FILE *fp;
    fp = fopen("persons.dat", "ab+");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(0);
    }

    int choice;
    Person person;

    printf("Welcome to Retro Database Indexing System!\n");

    while(1) {
        printf("\n1. Add a person\n");
        printf("2. Display all persons\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPerson(&person, fp);
                break;
            case 2:
                displayAllPersons(fp);
                break;
            case 3:
                printf("Thank you for using Retro Database Indexing System!\n");
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}