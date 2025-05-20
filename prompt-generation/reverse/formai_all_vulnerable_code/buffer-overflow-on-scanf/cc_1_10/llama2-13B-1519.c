//LLAMA2-13B DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

int main() {
    srand(time(NULL));

    // Generate a random name for the player
    char name[MAX_NAME_LEN];
    for (int i = 0; i < MAX_NAME_LEN; i++) {
        name[i] = 'a' + (rand() % 26);
    }

    // Prompt the player to enter their age
    printf("Hello, my name is %s, and I am %d years old.\n", name, rand() % MAX_AGE);

    // Get the player's age
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);

    // Check if the player's age is valid
    if (age > 0 && age <= MAX_AGE) {
        // Print a message based on the player's age
        switch (age) {
            case 1:
                printf("You are a baby! You can't do anything yet.");
                break;
            case 2:
                printf("You are a toddler! You can only say 'mama' and 'papa'.");
                break;
            case 3:
                printf("You are a little kid! You can play with toys and run around.");
                break;
            case 4:
                printf("You are a big kid! You can go to school and learn things.");
                break;
            case 5:
                printf("You are a grown-up! You can do whatever you want.");
                break;
            default:
                printf("That's not a valid age. You must be between 1 and 5.");
                break;
        }
    } else {
        printf("Invalid age. Please try again.");
    }

    return 0;
}