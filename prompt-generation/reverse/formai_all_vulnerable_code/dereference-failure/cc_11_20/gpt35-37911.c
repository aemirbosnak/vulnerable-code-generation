//FormAI DATASET v1.0 Category: Data mining ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
    float income;
} Person;

int main() {
    int n = 5;      // number of people
    Person *people = malloc(sizeof(Person) * n);

    // generate some random data
    for (int i = 0; i < n; i++) {
        people[i].id = i + 1;
        sprintf(people[i].name, "Person %d", i+1);
        people[i].age = 18 + rand() % 50;
        people[i].gender = rand() % 2 == 0 ? 'M' : 'F';
        people[i].income = 1000 + (rand() % 500) * 10.0;
    }

    // print all people
    printf("All people:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%c\t%.2f\n",
               people[i].id, people[i].name, people[i].age,
               people[i].gender, people[i].income);
    }

    // find all people under the age of 30
    printf("\nPeople under 30:\n");
    for (int i = 0; i < n; i++) {
        if (people[i].age < 30) {
            printf("%d\t%s\t%d\t%c\t%.2f\n",
                   people[i].id, people[i].name, people[i].age,
                   people[i].gender, people[i].income);
        }
    }

    // find all people whose income is greater than $7000
    printf("\nPeople with income > $7000:\n");
    for (int i = 0; i < n; i++) {
        if (people[i].income > 7000.0) {
            printf("%d\t%s\t%d\t%c\t%.2f\n",
                   people[i].id, people[i].name, people[i].age,
                   people[i].gender, people[i].income);
        }
    }

    // sort people by age
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (people[i].age > people[j].age) {
                Person tmp = people[i];
                people[i] = people[j];
                people[j] = tmp;
            }
        }
    }

    // print people sorted by age
    printf("\nPeople sorted by age:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%c\t%.2f\n",
               people[i].id, people[i].name, people[i].age,
               people[i].gender, people[i].income);
    }

    // clean up
    free(people);

    return 0;
}