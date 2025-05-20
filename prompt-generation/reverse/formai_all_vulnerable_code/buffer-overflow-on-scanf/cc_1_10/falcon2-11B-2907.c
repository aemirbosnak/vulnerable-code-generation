//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
} Person;

void insert(Person *people, int numPeople, Person *newPerson) {
    if (numPeople == 0) {
        strcpy(newPerson->name, "First Person");
        newPerson->age = 0;
        people[0] = *newPerson;
        return;
    }
    
    int index = -1;
    for (int i = 0; i < numPeople; i++) {
        if (strcmp(people[i].name, newPerson->name) < 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        index = numPeople;
        strcpy(people[index].name, newPerson->name);
        people[index].age = newPerson->age;
        people[index].age++;
    }
}

void display(Person *people, int numPeople) {
    for (int i = 0; i < numPeople; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
}

int main() {
    Person people[10];
    int numPeople = 0;
    
    while (1) {
        printf("Enter a name: ");
        char name[100];
        fgets(name, sizeof(name), stdin);
        if (strcmp(name, "exit") == 0) {
            break;
        }
        
        Person newPerson;
        strcpy(newPerson.name, name);
        int age;
        printf("Enter age: ");
        scanf("%d", &age);
        newPerson.age = age;
        
        insert(people, numPeople, &newPerson);
        numPeople++;
    }
    
    display(people, numPeople);
    
    return 0;
}