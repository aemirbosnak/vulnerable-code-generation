//Falcon-180B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Data structure for storing a person's name and age
typedef struct {
    char name[50];
    int age;
} Person;

// Function for comparing two people by name
int compare_name(const void* a, const void* b) {
    const Person* personA = (const Person*)a;
    const Person* personB = (const Person*)b;
    return strcmp(personA->name, personB->name);
}

// Function for comparing two people by age
int compare_age(const void* a, const void* b) {
    const Person* personA = (const Person*)a;
    const Person* personB = (const Person*)b;
    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return 0;
    }
}

// Function for printing a person's name and age
void print_person(const void* person) {
    const Person* p = (const Person*)person;
    printf("%s (%d years old)\n", p->name, p->age);
}

int main() {
    // Create an array of people
    Person people[MAX_SIZE];
    int num_people = 0;

    // Read in the people from a file
    FILE* file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* name = strtok(line, " ");
        int age = atoi(strtok(NULL, " "));
        strcpy(people[num_people].name, name);
        people[num_people].age = age;
        num_people++;
        if (num_people == MAX_SIZE) {
            printf("Error: maximum number of people reached.\n");
            return 1;
        }
    }
    fclose(file);

    // Sort the people by name
    qsort(people, num_people, sizeof(Person), compare_name);

    // Print the sorted people
    printf("Sorted by name:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    // Sort the people by age
    qsort(people, num_people, sizeof(Person), compare_age);

    // Print the sorted people
    printf("\nSorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    return 0;
}