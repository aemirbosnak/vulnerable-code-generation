//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int id;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return 0;
    }
}

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(Person arr[], int left, int right) {
    int i = left, j = right;
    Person pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (compare(&arr[i], &pivot) < 0) {
            i++;
        }
        while (compare(&arr[j], &pivot) > 0) {
            j--;
        }
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int binarySearch(Person arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        int result = compare(&arr[mid], &target);
        if (result == 0) {
            return mid;
        } else if (result < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    Person arr[MAX_SIZE];
    int size = 0;

    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(fp, "%s %d %d", arr[size].name, &arr[size].age, &arr[size].id)!= EOF) {
        size++;
    }

    fclose(fp);

    quickSort(arr, 0, size - 1);

    int targetAge = 25;
    int index = binarySearch(arr, size, targetAge);

    if (index == -1) {
        printf("Age not found\n");
    } else {
        printf("Person with age %d found at index %d\n", targetAge, index);
        printf("Name: %s\n", arr[index].name);
        printf("Age: %d\n", arr[index].age);
        printf("ID: %d\n", arr[index].id);
    }

    return 0;
}