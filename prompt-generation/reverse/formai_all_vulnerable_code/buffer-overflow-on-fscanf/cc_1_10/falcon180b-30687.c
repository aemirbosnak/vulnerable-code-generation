//Falcon-180B DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int age;
} Person;

void swap(Person *a, Person *b) {
    Person temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    if (p1->age < p2->age) {
        return -1;
    } else if (p1->age == p2->age) {
        return 0;
    } else {
        return 1;
    }
}

void print_array(Person arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %d\n", arr[i].name, arr[i].age);
    }
}

int main() {
    FILE *fp;
    Person arr[MAX_SIZE];
    int n = 0;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d", arr[n].name, &arr[n].age)!= EOF) {
        n++;
        if (n == MAX_SIZE) {
            printf("Error: Array is full\n");
            exit(1);
        }
    }

    fclose(fp);

    qsort(arr, n, sizeof(Person), compare);

    printf("Sorted by age:\n");
    print_array(arr, n);

    return 0;
}