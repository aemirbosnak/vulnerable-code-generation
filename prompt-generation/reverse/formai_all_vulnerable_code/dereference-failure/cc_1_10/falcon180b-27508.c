//Falcon-180B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void *my_malloc(size_t size);
void my_free(void *ptr);
void my_realloc(void *ptr, size_t size);

int main() {
    Person *p1 = (Person *) my_malloc(sizeof(Person));
    Person *p2 = (Person *) my_malloc(sizeof(Person));

    p1->name = "Alice";
    p1->age = 25;

    p2->name = "Bob";
    p2->age = 30;

    printf("Name of first person: %s\n", p1->name);
    printf("Age of first person: %d\n", p1->age);

    printf("Name of second person: %s\n", p2->name);
    printf("Age of second person: %d\n", p2->age);

    my_free(p1);
    my_free(p2);

    return 0;
}

void *my_malloc(size_t size) {
    static void *heap = NULL;
    static size_t heap_size = 0;

    if (heap == NULL) {
        heap = malloc(MAX_SIZE);
        heap_size = MAX_SIZE;
    }

    if (heap_size - sizeof(void *) < size) {
        printf("Out of memory!\n");
        exit(1);
    }

    void *result = heap;
    heap += size + sizeof(void *);
    heap_size -= size + sizeof(void *);

    return result;
}

void my_free(void *ptr) {
    // Do nothing in this simple example
}

void my_realloc(void *ptr, size_t size) {
    // Do nothing in this simple example
}