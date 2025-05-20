//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int score;
} Person;

void generateRandomName(char *name, int length) {
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        name[i] = c;
    }
    name[length] = '\0';
}

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    if (personA->age > personB->age) {
        return 1;
    } else if (personA->age < personB->age) {
        return -1;
    } else {
        if (personA->score > personB->score) {
            return 1;
        } else if (personA->score < personB->score) {
            return -1;
        } else {
            return 0;
        }
    }
}

int main() {
    Person *people = (Person *)malloc(MAX_SIZE * sizeof(Person));
    int numPeople = 0;

    printf("Enter the number of people: ");
    scanf("%d", &numPeople);

    for (int i = 0; i < numPeople; i++) {
        char name[10];
        generateRandomName(name, 10);
        people[i].name = strdup(name);
        people[i].age = rand() % 100;
        people[i].score = rand() % 100;
    }

    qsort(people, numPeople, sizeof(Person), compare);

    printf("Sorted by age and score:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s (%d years old, score: %d)\n", people[i].name, people[i].age, people[i].score);
    }

    free(people);
    return 0;
}