//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Structure to hold person information
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} person_t;

// Function to get user input and create a person struct
person_t get_person_info() {
    printf("Enter your name: ");
    char name[MAX_NAME_LEN];
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    person_t p = { .name = name, .age = age };
    return p;
}

// Function to print a person's information
void print_person(person_t p) {
    printf("Name: %s\nAge: %d\n", p.name, p.age);
}

int main() {
    person_t p1 = get_person_info(); // Get first person's info
    print_person(p1); // Print first person's info

    person_t p2 = get_person_info(); // Get second person's info
    print_person(p2); // Print second person's info

    // Add some randomness to the program
    srand(time(NULL));
    int random_age = rand() % MAX_AGE;
    p2.age = random_age; // Change second person's age randomly

    print_person(p2); // Print second person's updated info

    return 0;
}