//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

int main() {
    char *str = my_malloc(MAX_SIZE);
    strcpy(str, "Hello, world!");
    printf("String: %s\n", str);

    int *arr = my_malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    Person *person = my_malloc(sizeof(Person));
    person->name = my_malloc(MAX_SIZE);
    strcpy(person->name, "John Doe");
    person->age = 30;
    printf("Name: %s, Age: %d\n", person->name, person->age);

    my_free(str);
    my_free(arr);
    my_free(person->name);
    my_free(person);

    return 0;
}