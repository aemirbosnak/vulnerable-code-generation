//Falcon-180B DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Person *people = NULL;
    size_t capacity = 0;
    size_t count = 0;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char *address = strtok(NULL, ",");

        if (count >= capacity) {
            capacity += 10;
            people = realloc(people, capacity * sizeof(Person));
        }

        people[count].name = strdup(name);
        people[count].age = age;
        people[count].address = strdup(address);
        count++;
    }

    fclose(file);

    for (size_t i = 0; i < count; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Address: %s\n", people[i].address);
        printf("\n");
    }

    for (size_t i = 0; i < count; i++) {
        free(people[i].name);
        free(people[i].address);
    }
    free(people);

    return 0;
}