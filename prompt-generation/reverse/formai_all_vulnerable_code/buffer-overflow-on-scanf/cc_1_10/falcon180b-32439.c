//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void init(Person *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i].name = NULL;
        arr[i].age = 0;
    }
}

void insert(Person *arr, int size, int index, char *name, int age) {
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }

    if (size == MAX_SIZE) {
        printf("Array is full.\n");
        return;
    }

    if (arr[index].name!= NULL) {
        printf("Name already exists.\n");
        return;
    }

    arr[index].name = strdup(name);
    arr[index].age = age;
}

void delete(Person *arr, int size, int index) {
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }

    if (arr[index].name == NULL) {
        printf("Name not found.\n");
        return;
    }

    free(arr[index].name);
    arr[index].name = NULL;
    arr[index].age = 0;
}

void search(Person *arr, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (arr[i].name!= NULL && strcmp(arr[i].name, name) == 0) {
            printf("Name: %s, Age: %d\n", arr[i].name, arr[i].age);
            return;
        }
    }

    printf("Name not found.\n");
}

void sort(Person *arr, int size, int (*compare)(const void *, const void *)) {
    qsort(arr, size, sizeof(Person), compare);
}

int compare_age(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    return person_a->age - person_b->age;
}

int main() {
    Person *arr;
    int size = 0;

    init(arr, size);

    while (1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Sort\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                char name[100];
                int age;

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter age: ");
                scanf("%d", &age);

                insert(arr, size, size, name, age);
                size++;
                break;
            }

        case 2:
            {
                char name[100];

                printf("Enter name: ");
                scanf("%s", name);

                delete(arr, size, size - 1);
                size--;
                break;
            }

        case 3:
            {
                char name[100];

                printf("Enter name: ");
                scanf("%s", name);

                search(arr, size, name);
                break;
            }

        case 4:
            {
                printf("Sorting by age...\n");
                sort(arr, size, compare_age);
                break;
            }

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}