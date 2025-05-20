//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a cat
typedef struct {
    char name[20];
    int age;
    char breed[20];
} Cat;

// Function to create a new cat
void createCat(Cat* cat) {
    printf("Enter the name of the cat: ");
    scanf("%s", cat->name);
    printf("Enter the age of the cat: ");
    scanf("%d", &cat->age);
    printf("Enter the breed of the cat: ");
    scanf("%s", cat->breed);
}

// Function to display cat information
void displayCat(Cat cat) {
    printf("Name: %s\nAge: %d\nBreed: %s\n", cat.name, cat.age, cat.breed);
}

// Function to compare two cats based on their age
int compareCats(Cat cat1, Cat cat2) {
    if (cat1.age > cat2.age) {
        return 1;
    } else if (cat1.age < cat2.age) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    // Create an array of cats
    Cat cats[3];

    // Create three cats
    createCat(&cats[0]);
    createCat(&cats[1]);
    createCat(&cats[2]);

    // Sort the cats by age
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (compareCats(cats[i], cats[j]) > 0) {
                Cat temp = cats[i];
                cats[i] = cats[j];
                cats[j] = temp;
            }
        }
    }

    // Display the sorted cats
    printf("Sorted by age:\n");
    for (int i = 0; i < 3; i++) {
        displayCat(cats[i]);
    }

    return 0;
}