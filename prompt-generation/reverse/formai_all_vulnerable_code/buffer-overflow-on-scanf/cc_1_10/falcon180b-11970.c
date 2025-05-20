//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
} Person;

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;

    if (p1->age < p2->age)
        return -1;
    else if (p1->age > p2->age)
        return 1;
    else
        return 0;
}

void binarySearch(Person *array, int size, int targetAge) {
    qsort(array, size, sizeof(Person), compare);

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (array[mid].age == targetAge) {
            printf("Found person with age %d: %s\n", targetAge, array[mid].name);
            return;
        } else if (array[mid].age < targetAge) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("No person found with age %d\n", targetAge);
}

int main() {
    Person people[] = {{"Alice", 25, 1.65}, {"Bob", 30, 1.80}, {"Charlie", 20, 1.75}, {"David", 35, 1.85}};
    int size = sizeof(people) / sizeof(Person);

    int targetAge;
    printf("Enter target age: ");
    scanf("%d", &targetAge);

    binarySearch(people, size, targetAge);

    return 0;
}