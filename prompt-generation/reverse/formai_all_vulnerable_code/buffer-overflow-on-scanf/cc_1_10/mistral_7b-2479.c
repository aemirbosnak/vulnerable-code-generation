//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_AGE 120

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

void printPerson(Person p) {
    printf("Name: %s, Age: %d\n", p.name, p.age);
}

int main() {
    Person suspects[5];
    int sum_ages = 0, i, j, k;
    char suspect1[MAX_NAME_LEN], suspect2[MAX_NAME_LEN];

    for (i = 0; i < 5; i++) {
        printf("Enter name of suspect %d: ", i + 1);
        scanf("%s", suspects[i].name);
        printf("Enter age of suspect %d: ", i + 1);
        scanf("%d", &suspects[i].age);
        sum_ages += suspects[i].age;
    }

    printf("\nSuspects:\n");
    for (i = 0; i < 5; i++) {
        printPerson(suspects[i]);
    }

    printf("\nTotal age of suspects: %d\n", sum_ages);

    // Find two suspects with the highest ages
    j = i = 0;
    for (k = 1; k < 5; k++) {
        if (suspects[k].age > suspects[j].age) {
            j = k;
        }
    }

    i = 0;
    while (suspects[i].age != suspects[j].age) {
        if (suspects[i].age > suspects[i + 1].age) {
            strcpy(suspect2, suspects[i + 1].name);
            i++;
        } else {
            i++;
        }
    }

    strcpy(suspect1, suspects[j].name);

    printf("\nThe suspects with the highest ages are: %s (%d years old)\n", suspect1, suspects[j].age);
    printf("and %s (%d years old)\n", suspect2, suspects[i].age);

    return 0;
}