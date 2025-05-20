//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 1

int main() {
    // Define variables to store user input
    char name[MAX_LENGTH];
    int age;
    float height;

    // Get the user's name and age
    printf("What is your name? ");
    fgets(name, MAX_LENGTH, stdin);
    sscanf(name, "%d", &age);

    // Check if the user entered a valid name and age
    if (age < MIN_LENGTH || age > 100) {
        printf("Invalid age! Please enter a value between %d and %d.", MIN_LENGTH, 100);
        return 1;
    }

    // Get the user's height
    printf("How tall are you? ");
    scanf("%f", &height);

    // Check if the user entered a valid height
    if (height < 1.0f || height > 3.0f) {
        printf("Invalid height! Please enter a value between 1.0 and 3.0.");
        return 2;
    }

    // Calculate and print the user's weight
    float weight = (age * 10) + (height * 100);
    printf("You weigh %f pounds.\n", weight);

    // Generate a random error message
    int error_code = rand() % 3;
    switch (error_code) {
        case 0:
            printf("But wait, there's a catch! You have been randomly selected for a surprise inspection.");
            break;
        case 1:
            printf("Oops, it looks like you accidentally entered your age in dog years.");
            break;
        case 2:
            printf("Whoa, your height is off the charts! You must be a giant or a dwarf.");
            break;
    }

    return error_code;
}