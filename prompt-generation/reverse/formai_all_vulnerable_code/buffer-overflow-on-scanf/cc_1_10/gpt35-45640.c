//FormAI DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Person;

void printPerson(Person p) {
    printf("%s (%d) - %s\n", p.name, p.age, p.occupation);
}

int main() {
    // Let's create a database of persons
    int numPersons = 5;
    Person people[5] = {
        {"Alice Smith", 25, "Software Engineer"}, 
        {"Bob Johnson", 32, "Data Analyst"}, 
        {"Charlie Brown", 19, "Student"},
        {"David Lee", 47, "CEO"},
        {"Emma Watson", 28, "Actress"}
    };
    
    // Now let's query the database
    printf("People over 30:\n");
    for (int i=0; i<numPersons; i++) {
        if (people[i].age > 30) {
            printPerson(people[i]);
        }
    }
    
    printf("Students:\n");
    for (int i=0; i<numPersons; i++) {
        if (strcmp(people[i].occupation, "Student") == 0) {
            printPerson(people[i]);
        }
    }
    
    printf("Name search:\n");
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    for (int i=0; i<numPersons; i++) {
        if (strcmp(people[i].name, searchName) == 0) {
            printPerson(people[i]);
            break;
        }
    }
    
    printf("Occupation search:\n");
    char searchOccupation[50];
    printf("Enter occupation to search: ");
    scanf("%s", searchOccupation);
    for (int i=0; i<numPersons; i++) {
        if (strcmp(people[i].occupation, searchOccupation) == 0) {
            printPerson(people[i]);
        }
    }
    
    return 0;
}