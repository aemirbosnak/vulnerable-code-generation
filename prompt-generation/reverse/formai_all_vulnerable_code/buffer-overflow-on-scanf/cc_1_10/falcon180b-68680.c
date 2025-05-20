//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

// Define a structure to hold the data
typedef struct {
    char name[MAX_SIZE];
    int age;
    char address[MAX_SIZE];
} Person;

// Function to compare two structures
int compare(const void *a, const void *b) {
    Person *person1 = (Person *)a;
    Person *person2 = (Person *)b;

    if (strcmp(person1->name, person2->name) == 0) {
        return 0;
    } else if (strcmp(person1->name, person2->name) < 0) {
        return -1;
    } else {
        return 1;
    }
}

// Function to search for a person in the array
void search(Person *array, int size, char *name) {
    Person *result = NULL;

    qsort(array, size, sizeof(Person), compare);

    for (int i = 0; i < size; i++) {
        if (strcmp(array[i].name, name) == 0) {
            result = &array[i];
            break;
        }
    }

    if (result!= NULL) {
        printf("Found person: %s %d years old living at %s\n", result->name, result->age, result->address);
    } else {
        printf("Person not found.\n");
    }
}

int main() {
    Person people[] = {
        { "Alice", 25, "123 Main St." },
        { "Bob", 30, "456 Elm St." },
        { "Charlie", 35, "789 Oak St." },
        { "David", 40, "101 Maple St." },
        { "Eve", 45, "555 Pine St." }
    };

    int size = sizeof(people) / sizeof(Person);

    char name[MAX_SIZE];

    printf("Enter a name to search for: ");
    scanf("%s", name);

    search(people, size, name);

    return 0;
}