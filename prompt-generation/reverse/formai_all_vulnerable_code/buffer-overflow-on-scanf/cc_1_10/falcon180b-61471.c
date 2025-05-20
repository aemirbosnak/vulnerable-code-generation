//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;

    if (p1->age < p2->age) {
        return -1;
    } else if (p1->age > p2->age) {
        return 1;
    } else {
        return 0;
    }
}

void paranoid_search(Person arr[], int size, int target_age) {
    qsort(arr, size, sizeof(Person), compare);

    for (int i = 0; i < size; i++) {
        if (arr[i].age == target_age) {
            printf("Found person with age %d: %s\n", target_age, arr[i].name);
        }
    }
}

int main() {
    Person arr[MAX_SIZE];
    int size = 0;

    while (size < MAX_SIZE) {
        printf("Enter name and age of person (or -1 to stop): ");
        scanf("%s %d", arr[size].name, &arr[size].age);

        if (arr[size].age == -1) {
            break;
        }

        size++;
    }

    int target_age;
    printf("Enter target age to search: ");
    scanf("%d", &target_age);

    paranoid_search(arr, size, target_age);

    return 0;
}