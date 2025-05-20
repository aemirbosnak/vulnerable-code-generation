//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int prob = 5;
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please answer the following questions to determine the probability of an alien invasion.\n");

    printf("\nWhat is your age?\n"); // Question 1
    int age; 
    scanf("%d", &age);

    printf("\nDo you believe in extraterrestrial life? (y/n)\n"); // Question 2
    char answer1;
    scanf(" %c", &answer1);
    if (answer1 == 'y'){
        prob += 10;
    }

    printf("\nHave you ever seen a UFO? (y/n)\n"); // Question 3
    char answer2;
    scanf(" %c", &answer2);
    if (answer2 == 'y'){
        prob += 15;
    }

    printf("\nHow many science fiction movies have you seen in the past month?\n"); // Question 4
    int movies;
    scanf("%d", &movies);
    prob += movies;

    printf("\nDo you think aliens would be friendly or hostile to humans? (f/h)\n"); // Question 5
    char answer3;
    scanf(" %c", &answer3);
    if (answer3 == 'h'){
        prob += 20;
    }

    srand(time(0)); // Seed for random number generator
    int bonus = rand() % 20; // Generate a random bonus between 0-19
    prob += bonus;

    printf("\nCalculating probability...\n");
    printf("Your probability of an alien invasion is %d%%.\n", prob);

    if (prob < 30){
        printf("We're safe from the aliens for now!\n");
    } else if (prob < 60){
        printf("There's a small chance of an alien invasion.\n");
    } else if (prob < 80){
        printf("An alien invasion is a real possibility!\n");
    } else {
        printf("We're doomed! The aliens are definitely coming!\n");
    }

    return 0;
}