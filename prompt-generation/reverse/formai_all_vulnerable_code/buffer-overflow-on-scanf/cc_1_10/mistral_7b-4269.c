//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
    char gender;
    float height;
} Person;

void print_person(Person *p) {
    printf("Name: %s, Age: %d, Gender: %c, Height: %.2f\n", p->name, p->age, p->gender, p->height);
}

int main() {
    Person *persons, temp;
    int i, n;

    printf("Enter number of persons: ");
    scanf("%d", &n);

    persons = (Person *) malloc(n * sizeof(Person));

    if (persons == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter details of each person:\n");
    for (i = 0; i < n; i++) {
        printf("Person %d:\n", i + 1);
        scanf("%s", persons[i].name);
        scanf("%d", &persons[i].age);
        scanf("%c", &persons[i].gender);
        scanf("%f", &persons[i].height);

        // Swap person i with the smallest person in the list
        for (int j = i; j > 0 && strcmp(persons[j].name, persons[j - 1].name) > 0; j--) {
            temp = persons[j];
            persons[j] = persons[j - 1];
            persons[j - 1] = temp;
        }
    }

    printf("\nDetails of persons in sorted order:\n");
    for (i = 0; i < n; i++) {
        print_person(&persons[i]);
    }

    free(persons);

    return 0;
}