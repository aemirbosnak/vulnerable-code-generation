//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

void swap(Person *p1, Person *p2) {
    Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int compare_name(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return strcmp(p1->name, p2->name);
}

int compare_age(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;
    return p1->age - p2->age;
}

void print_array(Person *people, int n) {
    printf("\n===============================\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %d\n", people[i].name, people[i].age);
    }
}

int main() {
    printf("Welcome to the Sorting Game! Your task is to sort a list of people by either age or name. Are you ready?\n");

    int n = 0;
    printf("How many people are in the list?\n");
    scanf("%d", &n);

    Person *people = (Person *)malloc(n * sizeof(Person));
    for (int i = 0; i < n; i++) {
        printf("\nEnter the name of person #%d: ", i + 1);
        scanf("%s", people[i].name);
        printf("Enter the age of person #%d: ", i + 1);
        scanf("%d", &people[i].age);
    }

    printf("\nFantastic! Here is the unsorted list of people:\n");
    print_array(people, n);

    printf("\nNow, it's time to choose! Enter '1' to sort by name or '2' to sort by age.\n");
    int choice = 0;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nSorting by name... ");
            qsort(people, n, sizeof(Person), compare_name);
            printf("Done!\n");
            break;
        case 2:
            printf("\nSorting by age... ");
            qsort(people, n, sizeof(Person), compare_age);
            printf("Done!\n");
            break;
        default:
            printf("\nInvalid choice. You lose!\n");
            return 1;
    }

    printf("\nHere is the sorted list of people:\n");
    print_array(people, n);

    free(people);

    printf("\nCongratulations! You win!\n");

    return 0;
}