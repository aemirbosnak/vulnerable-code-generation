//Falcon-180B DATASET v1.0 Category: Memory management ; Style: curious
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
    if (!ptr) {
        printf("Error: Out of memory\n");
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
    char input[MAX_SIZE];

    printf("Enter the number of people: ");
    scanf("%d", &num_people);

    people = my_malloc(num_people * sizeof(Person));

    for (int i = 0; i < num_people; i++) {
        printf("Enter person %d's name: ", i+1);
        scanf("%s", input);
        people[i].name = my_malloc(strlen(input)+1);
        strcpy(people[i].name, input);

        printf("Enter person %d's age: ", i+1);
        scanf("%d", &people[i].age);
    }

    for (int i = 0; i < num_people; i++) {
        printf("Person %d's name is %s and age is %d\n", i+1, people[i].name, people[i].age);
    }

    for (int i = 0; i < num_people; i++) {
        my_free(people[i].name);
    }
    my_free(people);

    return 0;
}