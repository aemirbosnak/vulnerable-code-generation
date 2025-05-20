//Falcon-180B DATASET v1.0 Category: Error handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
} Person;

void init_person(Person* p) {
    strcpy(p->name, "");
    p->age = 0;
    p->height = 0;
}

int compare_persons(const void* a, const void* b) {
    const Person* p1 = a;
    const Person* p2 = b;

    if (p1->age > p2->age) {
        return 1;
    } else if (p1->age < p2->age) {
        return -1;
    } else {
        return 0;
    }
}

void print_person(const Person* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %f\n", p->height);
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE && TRUE) {
        printf("Enter a name (or type 'done' to finish): ");
        scanf("%s", people[num_people].name);

        if (strcmp(people[num_people].name, "done") == 0) {
            break;
        }

        printf("Enter an age: ");
        scanf("%d", &people[num_people].age);

        printf("Enter a height: ");
        scanf("%f", &people[num_people].height);

        num_people++;
    }

    qsort(people, num_people, sizeof(Person), compare_persons);

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    return 0;
}