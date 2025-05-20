//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

Person *create_person(char *name, char *address, char *phone_number, char *email) {
    Person *person = (Person *)malloc(sizeof(Person));
    strncpy(person->name, name, MAX_NAME_LENGTH);
    strncpy(person->address, address, MAX_ADDRESS_LENGTH);
    strncpy(person->phone_number, phone_number, MAX_PHONE_NUMBER_LENGTH);
    strncpy(person->email, email, MAX_EMAIL_LENGTH);
    return person;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
    printf("Phone number: %s\n", person->phone_number);
    printf("Email: %s\n", person->email);
}

int main() {
    Person *person1 = create_person("John Doe", "123 Main St.", "555-1234", "johndoe@email.com");
    Person *person2 = create_person("Jane Smith", "456 Maple Ave.", "555-5678", "janesmith@email.com");
    Person *person3 = create_person("Bob Johnson", "789 Oak St.", "555-9012", "bobjohnson@email.com");

    printf("Person 1:\n");
    print_person(person1);

    printf("\nPerson 2:\n");
    print_person(person2);

    printf("\nPerson 3:\n");
    print_person(person3);

    free(person1);
    free(person2);
    free(person3);

    return 0;
}