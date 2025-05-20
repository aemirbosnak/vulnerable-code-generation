//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

typedef struct Person {
    char name[50];
    Date birthdate;
    int age;
    char occupation[50];
} Person;

int main() {
    Person p[MAX_SIZE];

    // Create and initialize persons
    for (int i = 0; i < MAX_SIZE; i++) {
        p[i].name[0] = '\0';
        p[i].birthdate.day = 0;
        p[i].birthdate.month = 0;
        p[i].birthdate.year = 0;
        p[i].age = 0;
        p[i].occupation[0] = '\0';
    }

    // Get person information
    printf("Enter the name of the person: ");
    scanf("%s", p[0].name);

    printf("Enter the birthdate of the person (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &p[0].birthdate.day, &p[0].birthdate.month, &p[0].birthdate.year);

    // Calculate the person's age
    p[0].age = 2023 - p[0].birthdate.year - 1;

    // Get the person's occupation
    printf("Enter the person's occupation: ");
    scanf("%s", p[0].occupation);

    // Display the person's information
    printf("Name: %s\n", p[0].name);
    printf("Birthdate: %d/%d/%d\n", p[0].birthdate.day, p[0].birthdate.month, p[0].birthdate.year);
    printf("Age: %d\n", p[0].age);
    printf("Occupation: %s\n", p[0].occupation);

    return 0;
}