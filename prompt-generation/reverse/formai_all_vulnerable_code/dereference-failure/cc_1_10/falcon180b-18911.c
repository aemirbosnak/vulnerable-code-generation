//Falcon-180B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr!= NULL) {
        free(ptr);
    }
}

int main() {
    Person *p1 = (Person *)my_malloc(sizeof(Person));
    p1->name = (char *)my_malloc(10);
    strcpy(p1->name, "John");
    p1->age = 25;

    Person *p2 = (Person *)my_malloc(sizeof(Person));
    p2->name = (char *)my_malloc(10);
    strcpy(p2->name, "Jane");
    p2->age = 30;

    Person *p3 = (Person *)my_malloc(sizeof(Person));
    p3->name = (char *)my_malloc(10);
    strcpy(p3->name, "Bob");
    p3->age = 20;

    printf("Name of first person: %s\n", p1->name);
    printf("Age of first person: %d\n", p1->age);

    printf("Name of second person: %s\n", p2->name);
    printf("Age of second person: %d\n", p2->age);

    printf("Name of third person: %s\n", p3->name);
    printf("Age of third person: %d\n", p3->age);

    my_free(p1->name);
    my_free(p1);

    my_free(p2->name);
    my_free(p2);

    my_free(p3->name);
    my_free(p3);

    return 0;
}