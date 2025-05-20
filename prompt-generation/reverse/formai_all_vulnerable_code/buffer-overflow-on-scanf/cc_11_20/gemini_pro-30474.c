//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct AlienInvasion {
    int probability;
    char *name;
};

struct AlienInvasion alienInvasions[] = {
    { 10, "The Martians" },
    { 15, "The Venusians" },
    { 20, "The Plutonians" },
    { 25, "The Neptunians" },
    { 30, "The Jovians" }
};

int main() {
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will calculate the probability of an alien invasion based on a number of factors.\n");
    printf("Please answer the following questions:\n");

    int age;
    printf("What is your age?\n");
    scanf("%d", &age);

    char gender;
    printf("What is your gender? (M/F)\n");
    scanf(" %c", &gender);

    char education;
    printf("What is your highest level of education? (H/C/B/A)\n");
    scanf(" %c", &education);

    int income;
    printf("What is your annual income?\n");
    scanf("%d", &income);

    char location;
    printf("Where do you live? (U/R/S)\n");
    scanf(" %c", &location);

    int probability = 0;

    if (age > 30) {
        probability += 10;
    }

    if (gender == 'M') {
        probability += 5;
    }

    switch (education) {
        case 'H':
            probability += 15;
            break;
        case 'C':
            probability += 10;
            break;
        case 'B':
            probability += 5;
            break;
        case 'A':
            probability += 0;
            break;
    }

    if (income > 100000) {
        probability += 10;
    }

    switch (location) {
        case 'U':
            probability += 15;
            break;
        case 'R':
            probability += 10;
            break;
        case 'S':
            probability += 5;
            break;
    }

    int random = rand() % 100;

    if (random < probability) {
        printf("You are at risk of an alien invasion!\n");
    } else {
        printf("You are safe from alien invasions!\n");
    }

    return 0;
}