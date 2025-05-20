//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char name[MAX_LENGTH];
    char address[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
} Contact;

typedef struct {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    int age;
    Contact contact;
} Person;

void printPerson(Person *person) {
    printf("First Name: %s\n", person->firstName);
    printf("Last Name: %s\n", person->lastName);
    printf("Age: %d\n", person->age);
    printf("Contact:\n");
    printf("Name: %s\n", person->contact.name);
    printf("Address: %s\n", person->contact.address);
    printf("Phone: %s\n", person->contact.phone);
    printf("Email: %s\n", person->contact.email);
}

Person* createPerson(FILE *file) {
    Person *person = (Person*) malloc(sizeof(Person));

    fscanf(file, "First Name: %[^\n]\n", person->firstName);
    fscanf(file, "Last Name: %[^\n]\n", person->lastName);
    fscanf(file, "Age: %d\n", &person->age);

    fscanf(file, "Contact:\n");
    fscanf(file, "Name: %[^\n]\n", person->contact.name);
    fscanf(file, "Address: %[^\n]\n", person->contact.address);
    fscanf(file, "Phone: %[^\n]\n", person->contact.phone);
    fscanf(file, "Email: %[^\n]\n", person->contact.email);

    return person;
}

void freePerson(Person *person) {
    free(person);
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Person *person = createPerson(file);
    printPerson(person);

    freePerson(person);
    fclose(file);

    return 0;
}