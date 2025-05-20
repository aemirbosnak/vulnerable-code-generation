//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    return strcmp(personA->name, personB->name);
}

int main() {
    FILE *file;
    char filename[50];
    char input[100];
    Person *people[MAX_SIZE];
    int numPeople = 0;

    printf("Enter the name of the file to search: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    while (fscanf(file, "%s %d\n", input, &numPeople)!= EOF) {
        people[numPeople - 1] = (Person *)malloc(sizeof(Person));
        people[numPeople - 1]->name = strdup(input);
        people[numPeople - 1]->age = numPeople;
    }

    fclose(file);

    qsort(people, numPeople, sizeof(Person *), compare);

    printf("Sorted list:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s %d\n", people[i]->name, people[i]->age);
    }

    return 0;
}