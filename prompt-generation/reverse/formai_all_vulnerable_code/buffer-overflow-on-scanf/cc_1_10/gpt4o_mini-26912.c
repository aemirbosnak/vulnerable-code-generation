//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUMBERS 10

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
    float height;
} Person;

void allocate_memory_for_person(Person **person, int number_of_people) {
    *person = (Person*)malloc(number_of_people * sizeof(Person));
    if (*person == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void input_person_data(Person *person, int index) {
    printf("Enter details of person %d:\n", index + 1);
    
    printf("Name: ");
    fgets(person[index].name, MAX_STRING_LENGTH, stdin);
    person[index].name[strcspn(person[index].name, "\n")] = 0; // Remove newline

    printf("Age: ");
    scanf("%d", &person[index].age);
    
    printf("Height (in meters): ");
    scanf("%f", &person[index].height);
    getchar(); // consume the newline character after float input
}

void display_person_data(Person *person, int number_of_people) {
    printf("\n--- Person Details ---\n");
    for (int i = 0; i < number_of_people; i++) {
        printf("Person %d: Name: %s, Age: %d, Height: %.2f\n",
            i + 1, person[i].name, person[i].age, person[i].height);
    }
}

void free_memory(Person *person) {
    free(person);
}

int main() {
    int number_of_people;

    printf("Enter the number of people: ");
    scanf("%d", &number_of_people);
    getchar(); // consume the newline character after integer input

    if (number_of_people <= 0 || number_of_people > MAX_NUMBERS) {
        fprintf(stderr, "Invalid number of people! Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        return EXIT_FAILURE;
    }

    Person *people = NULL;
    allocate_memory_for_person(&people, number_of_people);

    for (int i = 0; i < number_of_people; i++) {
        input_person_data(people, i);
    }

    display_person_data(people, number_of_people);
    
    free_memory(people);
    return EXIT_SUCCESS;
}