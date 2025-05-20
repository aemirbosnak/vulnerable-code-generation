//Falcon-180B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void *my_malloc(size_t size) {
    printf("Allocating %d bytes\n", size);
    return malloc(size);
}

void *my_realloc(void *ptr, size_t size) {
    printf("Reallocating %d bytes\n", size);
    return realloc(ptr, size);
}

void my_free(void *ptr) {
    printf("Freeing %p\n", ptr);
    free(ptr);
}

int main() {
    Person *people = NULL;
    int num_people = 0;
    char input[MAX_SIZE];

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    printf("Enter number of people: ");
    scanf("%d", &num_people);

    people = my_malloc(num_people * sizeof(Person));

    for (int i = 0; i < num_people; i++) {
        printf("Enter name for person %d: ", i+1);
        scanf("%s", input);
        people[i].name = my_malloc(strlen(input) + 1);
        strcpy(people[i].name, input);

        printf("Enter age for person %d: ", i+1);
        scanf("%d", &people[i].age);
    }

    for (int i = 0; i < num_people; i++) {
        printf("Name of person %d: %s\n", i+1, people[i].name);
        printf("Age of person %d: %d\n", i+1, people[i].age);
    }

    for (int i = 0; i < num_people; i++) {
        my_free(people[i].name);
    }

    my_free(people);

    return 0;
}