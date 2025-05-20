//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int id;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return strcmp(personA->name, personB->name);
}

void search(Person arr[], int size, char *name) {
    qsort(arr, size, sizeof(Person), compare);
    int i = 0;
    while (i < size) {
        if (strcmp(arr[i].name, name) == 0) {
            printf("Name: %s\n", arr[i].name);
            printf("ID: %d\n", arr[i].id);
            break;
        }
        i++;
    }
}

int main() {
    Person arr[MAX_SIZE];
    int size = 0;

    while (size < MAX_SIZE) {
        printf("Enter name: ");
        char name[100];
        scanf("%s", name);
        printf("Enter ID: ");
        int id;
        scanf("%d", &id);

        Person person = {.name = strdup(name),.id = id};
        arr[size++] = person;
    }

    char searchName[100];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    search(arr, size, searchName);

    for (int i = 0; i < size; i++) {
        free(arr[i].name);
    }

    return 0;
}