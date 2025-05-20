//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void print_array(Person arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", arr[i].name, arr[i].age);
    }
}

int main() {
    Person arr[MAX_SIZE];
    int n = 0;

    while (n < MAX_SIZE) {
        printf("Enter name and age (or type 'done'): ");
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        char *name = strtok(input, " ");
        int age = atoi(strtok(NULL, " "));

        if (n >= MAX_SIZE) {
            printf("Array is full.\n");
        } else {
            arr[n].name = (char *)malloc(strlen(name) + 1);
            strcpy(arr[n].name, name);
            arr[n].age = age;
            n++;
        }
    }

    qsort(arr, n, sizeof(Person), compare);
    print_array(arr, n);

    return 0;
}