//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ATTRIBUTES 10

typedef struct {
    char name[100];
    int age;
    int gender;
    int height;
    int weight;
    int income;
} Person;

void print_person(Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Gender: %d\n", p->gender);
    printf("Height: %d\n", p->height);
    printf("Weight: %d\n", p->weight);
    printf("Income: %d\n", p->income);
}

void print_people(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }
}

int main() {
    Person people[MAX_ITEMS];
    int num_people = 0;

    // Read in data from file
    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Parse line and store in person structure
        Person p;
        sscanf(line, "%s %d %d %d %d %d",
               p.name, &p.age, &p.gender, &p.height, &p.weight, &p.income);

        // Store person in array
        people[num_people++] = p;
    }
    fclose(file);

    // Print out all people
    print_people(people, num_people);

    return 0;
}