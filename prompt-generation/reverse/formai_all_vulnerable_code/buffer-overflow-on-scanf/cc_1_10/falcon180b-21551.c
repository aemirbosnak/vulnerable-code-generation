//Falcon-180B DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
} Person;

void writeToFile(Person* people, int numPeople, FILE* file) {
    for (int i = 0; i < numPeople; i++) {
        fprintf(file, "Name: %s\nAge: %d\n", people[i].name, people[i].age);
    }
}

void readFromFile(Person* people, int numPeople, FILE* file) {
    for (int i = 0; i < numPeople; i++) {
        fscanf(file, "Name: %s\nAge: %d", people[i].name, &people[i].age);
    }
}

int main() {
    Person people[10];
    int numPeople = 5;

    FILE* file = fopen("people.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    for (int i = 0; i < numPeople; i++) {
        printf("Enter name for person %d:\n", i+1);
        scanf("%s", people[i].name);
        printf("Enter age for person %d:\n", i+1);
        scanf("%d", &people[i].age);
    }

    writeToFile(people, numPeople, file);
    fclose(file);

    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    readFromFile(people, numPeople, file);
    fclose(file);

    printf("People in the file:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("Name: %s\nAge: %d\n", people[i].name, people[i].age);
    }

    return 0;
}