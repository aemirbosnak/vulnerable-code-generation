//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char occupation[MAX_LENGTH];
} Person;

void printPerson(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Occupation: %s\n", p.occupation);
}

void printPeople(Person people[], int numPeople) {
    printf("Printing all people:\n");
    for(int i = 0; i < numPeople; i++) {
        printPerson(people[i]);
        printf("\n");
    }
}

int main() {
    // Simulation of a database
    Person people[] = {
        {"John Doe", 24, "Software Engineer"},
        {"Jane Smith", 31, "Data Analyst"},
        {"Mike Johnson", 47, "CEO"},
        {"Amanda Lee", 19, "Student"},
        {"Chris Brown", 38, "Accountant"},
        {"Rachel Green", 28, "Marketing Manager"}
    };
    int numPeople = 6;

    char input[MAX_LENGTH];
    printf("Enter a query (age, occupation): ");
    scanf("%s", input);

    if(strcmp(input, "age") == 0) {
        int ageQuery;
        printf("Enter the age to query: ");
        scanf("%d", &ageQuery);

        printf("People with age %d:\n", ageQuery);
        for(int i = 0; i < numPeople; i++) {
            if(people[i].age == ageQuery) {
                printPerson(people[i]);
                printf("\n");
            }
        }
    } else if(strcmp(input, "occupation") == 0) {
        char occupationQuery[MAX_LENGTH];
        printf("Enter the occupation to query: ");
        scanf("%s", occupationQuery);

        printf("People with occupation %s:\n", occupationQuery);
        for(int i = 0; i < numPeople; i++) {
            if(strcmp(people[i].occupation, occupationQuery) == 0) {
                printPerson(people[i]);
                printf("\n");
            }
        }
    } else {
        printf("Invalid query.\n");
    }

    return 0;
}