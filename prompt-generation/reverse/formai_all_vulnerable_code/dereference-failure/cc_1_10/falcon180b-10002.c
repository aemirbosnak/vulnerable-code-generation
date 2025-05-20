//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

Person *search(Person *arr, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            return &arr[i];
        }
    }
    return NULL;
}

int main() {
    Person arr[MAX_SIZE];
    int size = 0;
    char input[100];

    while (1) {
        printf("\nEnter a name (leave blank to stop): ");
        scanf("%s", input);
        if (strcmp(input, "") == 0) {
            break;
        }
        strcpy(arr[size].name, input);
        printf("Enter age: ");
        scanf("%d", &arr[size].age);
        size++;
    }

    char name[100];
    while (1) {
        printf("\nEnter a name to search: ");
        scanf("%s", name);
        Person *result = search(arr, size, name);
        if (result!= NULL) {
            printf("\nName: %s\nAge: %d\n", result->name, result->age);
        } else {
            printf("\nName not found.\n");
        }
        printf("\nSearch again? (y/n): ");
        char choice[2];
        scanf("%s", choice);
        if (strcmp(choice, "n") == 0) {
            break;
        }
    }

    return 0;
}