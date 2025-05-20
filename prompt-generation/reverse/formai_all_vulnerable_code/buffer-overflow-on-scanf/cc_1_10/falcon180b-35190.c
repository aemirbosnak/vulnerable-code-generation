//Falcon-180B DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed!");
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

    people = (Person *) my_malloc(num_people * sizeof(Person));

    if (people!= NULL) {
        for (int i = 0; i < num_people; i++) {
            printf("Enter the name of person %d: ", i + 1);
            scanf("%s", people[i].name);

            printf("Enter the age of person %d: ", i + 1);
            scanf("%d", &people[i].age);
        }

        printf("\nName\tAge\n");
        for (int i = 0; i < num_people; i++) {
            printf("%s\t%d\n", people[i].name, people[i].age);
        }

        my_free(people);
    }

    return 0;
}