//Falcon-180B DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to create a new survivor
void create_survivor(char name[MAX_SIZE], int age, int strength, int intelligence) {
    printf("A new survivor has been created:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Strength: %d\n", strength);
    printf("Intelligence: %d\n", intelligence);
}

// Function to delete a survivor
void delete_survivor(char name[MAX_SIZE]) {
    printf("The survivor %s has been deleted.\n", name);
}

// Function to display all survivors
void display_survivors() {
    printf("All survivors:\n");
}

int main() {
    char name[MAX_SIZE];
    int age, strength, intelligence;

    // Create a new survivor
    printf("Enter the name of the survivor:\n");
    scanf("%s", name);
    printf("Enter the age of the survivor:\n");
    scanf("%d", &age);
    printf("Enter the strength of the survivor:\n");
    scanf("%d", &strength);
    printf("Enter the intelligence of the survivor:\n");
    scanf("%d", &intelligence);
    create_survivor(name, age, strength, intelligence);

    // Display all survivors
    display_survivors();

    // Delete a survivor
    printf("Enter the name of the survivor to delete:\n");
    scanf("%s", name);
    delete_survivor(name);

    // Display all survivors again
    display_survivors();

    return 0;
}