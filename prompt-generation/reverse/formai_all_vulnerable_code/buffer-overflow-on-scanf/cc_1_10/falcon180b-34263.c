//Falcon-180B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Out of memory! ");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

int main() {
    char input[100];
    Person *person = NULL;

    do {
        printf("Enter name (or type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        person = (Person *)my_malloc(sizeof(Person));
        strcpy(person->name, input);
        printf("Enter age: ");
        scanf("%d", &person->age);
        printf("Enter height: ");
        scanf("%f", &person->height);

        printf("Name: %s\n", person->name);
        printf("Age: %d\n", person->age);
        printf("Height: %f\n", person->height);

    } while (1);

    return 0;
}