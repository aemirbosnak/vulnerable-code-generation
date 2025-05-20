//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    char name[50];
    int age;
} Person;

void searchPerson(Person arr[], char nameToFind[], int *result) {
    int left = 0, right = SIZE - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (strcmp(arr[mid].name, nameToFind) == 0) {
            *result = mid;
            return;
        }

        if (strcmp(arr[mid].name, nameToFind) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    *result = -1;
}

int main() {
    Person people[SIZE];
    int i, result;
    char nameToFind[50];

    printf("Enter the number of people:\n");
    scanf("%d", &i);

    printf("Enter the details of each person:\n");
    for (int j = 0; j < i; j++) {
        scanf("%s %d", people[j].name, &people[j].age);
    }

    printf("Enter the name of the person to find:\n");
    scanf("%s", nameToFind);

    searchPerson(people, nameToFind, &result);

    if (result != -1) {
        printf("Person found at position %d.\n", result);
    } else {
        printf("Person not found.\n");
    }

    return 0;
}