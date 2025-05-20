//Falcon-180B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int size;
} Person;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

int main() {
    Person *people = NULL;
    int num_people = 0;

    printf("Enter the number of people: ");
    scanf("%d", &num_people);

    people = (Person *)my_malloc(num_people * sizeof(Person));

    for (int i = 0; i < num_people; i++) {
        printf("Enter the name of person %d: ", i+1);
        scanf("%s", people[i].name);
        printf("Enter the age of person %s: ", people[i].name);
        scanf("%d", &people[i].age);
        printf("Enter the size of person %s (in bytes): ", people[i].name);
        scanf("%d", &people[i].size);
    }

    printf("\nPeople:\n");
    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Size: %d bytes\n", people[i].size);
    }

    my_free(people);
    return 0;
}