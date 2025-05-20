//FormAI DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the Animal struct
typedef struct {
    char name[20];
    int age;
    char favorite_food[20];
} Animal;

int main() {
    // Create an array to hold the animals
    Animal animals[10];

    // Populate the array with some sample animals
    for (int i = 0; i < 5; i++) {
        Animal animal = {0};
        printf("Enter the name of animal %d: ", i+1);
        scanf("%s", animal.name);
        printf("Enter the age of %s: ", animal.name);
        scanf("%d", &animal.age);
        printf("Enter %s's favorite food: ", animal.name);
        scanf("%s", animal.favorite_food);
        animals[i] = animal;
    }

    // Print out the contents of the array
    printf("\nHere are the animals in the database:\n");
    for (int i = 0; i < 5; i++) {
        Animal animal = animals[i];
        printf("%s is %d years old and likes to eat %s\n", animal.name, animal.age, animal.favorite_food);
    }

    // Add a new animal to the database
    printf("\nLet's add a new animal to the database!\n");
    Animal new_animal = {0};
    printf("Enter the name of the new animal: ");
    scanf("%s", new_animal.name);
    printf("Enter the age of %s: ", new_animal.name);
    scanf("%d", &new_animal.age);
    printf("Enter %s's favorite food: ", new_animal.name);
    scanf("%s", new_animal.favorite_food);
    animals[5] = new_animal;

    // Print out the updated contents of the array
    printf("\nHere are the animals in the database after adding %s:\n", new_animal.name);
    for (int i = 0; i < 6; i++) {
        Animal animal = animals[i];
        printf("%s is %d years old and likes to eat %s\n", animal.name, animal.age, animal.favorite_food);
    }

    return 0;
}