//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Global variables
int numPeople = 0;
struct person {
    char name[MAX_NAME_LEN];
    int age;
} people[10];

void surprise() {
    printf("Surprise! You have won a trip to the moon!\n");
}

int main() {
    // Initialize global variables
    for (int i = 0; i < 10; i++) {
        people[i].name[0] = '\0';
        people[i].age = 0;
    }

    // Ask for name and age
    printf("Enter your name: ");
    fgets(people[0].name, MAX_NAME_LEN, stdin);
    printf("Enter your age: ");
    scanf("%d", &people[0].age);

    // Surprise!
    surprise();

    // Print the list of people
    for (int i = 0; i < 10; i++) {
        printf("Person %d: %s, %d years old\n", i + 1, people[i].name, people[i].age);
    }

    // Add more people
    printf("Do you want to add more people? (y/n): ");
    char answer = getchar();
    if (answer == 'y') {
        for (int i = 0; i < 10; i++) {
            printf("Enter name: ");
            fgets(people[i + 10].name, MAX_NAME_LEN, stdin);
            printf("Enter age: ");
            scanf("%d", &people[i + 10].age);
        }
    }

    // Print the list of people again
    for (int i = 0; i < 20; i++) {
        printf("Person %d: %s, %d years old\n", i + 1, people[i].name, people[i].age);
    }

    return 0;
}