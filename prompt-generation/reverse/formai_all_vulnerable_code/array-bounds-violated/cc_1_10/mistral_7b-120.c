//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
#define TRUE 1
#define FALSE 0

typedef struct {
    char name[20];
    int age;
} Person;

void bubbleSort(Person arr[], int n) {
    int i, j, tempAge;
    char tempName[20];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].age > arr[j + 1].age) {
                tempAge = arr[j].age;
                arr[j].age = arr[j + 1].age;
                arr[j + 1].age = tempAge;

                strcpy(tempName, arr[j].name);
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, tempName);
            }
        }
    }
}

int main() {
    Person people[MAX];
    int i, n;

    printf("\n***** RETRO SORTING PROGRAM *****\n");
    printf("\nEnter the number of people to be sorted: ");
    scanf("%d", &n);

    printf("\nEnter %d names and their corresponding ages:\n", n);
    for (i = 0; i < n; i++) {
        printf("\nName %d: ", i + 1);
        scanf("%s", people[i].name);
        people[i].name[strlen(people[i].name) - 1] = '\0'; // Remove trailing newline character
        printf("Age %d: ", i + 1);
        scanf("%d", &people[i].age);
    }

    bubbleSort(people, n);

    printf("\nSorted list in retro style:\n");
    for (i = 0; i < n; i++) {
        printf("\nName %d: %s", i + 1, people[i].name);
        printf("\nAge %d: %d", i + 1, people[i].age);
    }

    return 0;
}