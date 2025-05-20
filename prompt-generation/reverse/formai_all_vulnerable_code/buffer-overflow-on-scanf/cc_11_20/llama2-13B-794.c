//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    int age, i, j, k;
    char name[50];
    float height, weight;
    double average;

    // Ask the user for their name, age, height, and weight
    printf("Hello! What is your name? ");
    scanf("%s", name);
    printf("How old are you? ");
    scanf("%d", &age);
    printf("How tall are you? ");
    scanf("%f", &height);
    printf("How much do you weigh? ");
    scanf("%f", &weight);

    // Calculate the BMI (body mass index)
    average = (weight / (height * height));
    printf("Your BMI is %f\n", average);

    // Check if the user is underweight, normal weight, overweight, or obese
    if (average < 18.5) {
        printf("You are underweight!\n");
    } else if (average >= 18.5 && average < 25) {
        printf("You are normal weight.\n");
    } else if (average >= 25 && average < 30) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }

    // Ask the user for their favorite color and favorite animal
    printf("What is your favorite color? ");
    scanf("%s", name);
    printf("What is your favorite animal? ");
    scanf("%s", name);

    // Print a fun fact about the user's favorite animal
    if (strcmp(name, "cat") == 0) {
        printf("Did you know that cats have 32 muscles in each ear?\n");
    } else if (strcmp(name, "dog") == 0) {
        printf("Did you know that dogs have 18 muscles in each ear?\n");
    } else {
        printf("I don't have any fun facts about %s\n", name);
    }

    // Print a random joke
    j = (int)(rand() % 100) + 1;
    if (j == 1) {
        printf("Why was the math book sad? Because it had too many problems.\n");
    } else if (j == 2) {
        printf("Why did the computer go to the party? Because it heard there was a great byte band playing.\n");
    } else {
        printf("I don't have any jokes for you today. Maybe next time will be more fortunate!\n");
    }

    // Print a quote from the wise sage, Albert Einstein
    printf("As Albert Einstein once said, 'The only thing that interferes with my learning is my education.'\n");

    // Print a silly sentence using only words that start with the letter "s"
    printf("The sneaky snake slithered silently through the shadows seeking a succulent snack.\n");

    // Print a poem about the user's name
    for (i = 0; i < strlen(name); i++) {
        printf("%c is a lovely letter, don't you agree?\n", name[i]);
    }

    return 0;
}