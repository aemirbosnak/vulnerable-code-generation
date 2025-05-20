//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

void *my_malloc(size_t size) {
    printf("Allocating %d bytes\n", size);
    return malloc(size);
}

void *my_calloc(size_t count, size_t size) {
    printf("Allocating %d elements of %d bytes each\n", count, size);
    return calloc(count, size);
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
    void *(*malloc_func)(size_t) = &my_malloc;
    void *(*calloc_func)(size_t, size_t) = &my_calloc;
    void *(*realloc_func)(void *, size_t) = &my_realloc;
    void (*free_func)(void *) = &my_free;

    printf("Using custom memory functions\n");

    Person *person = (Person *) malloc_func(sizeof(Person));
    person->name = (char *) calloc_func(1, MAX_SIZE);
    strcpy(person->name, "John Doe");
    person->age = 30;
    person->address = (char *) calloc_func(1, MAX_SIZE);
    strcpy(person->address, "123 Main St");

    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Address: %s\n", person->address);

    free_func(person->name);
    free_func(person->address);
    free_func(person);

    return 0;
}