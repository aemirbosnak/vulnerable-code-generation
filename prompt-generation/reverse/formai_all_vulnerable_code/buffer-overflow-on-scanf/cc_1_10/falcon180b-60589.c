//Falcon-180B DATASET v1.0 Category: Sorting ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    Person *personA = (Person*)a;
    Person *personB = (Person*)b;

    if(personA->age < personB->age) {
        return -1;
    } else if(personA->age > personB->age) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Person people[MAX_SIZE];
    int numPeople = 0;

    printf("Enter the number of people: ");
    scanf("%d", &numPeople);

    for(int i = 0; i < numPeople; i++) {
        printf("Enter name of person #%d: ", i+1);
        scanf("%s", people[i].name);

        printf("Enter age of person #%d: ", i+1);
        scanf("%d", &people[i].age);
    }

    qsort(people, numPeople, sizeof(Person), compare);

    printf("\nSorted by age:\n");
    for(int i = 0; i < numPeople; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    return 0;
}