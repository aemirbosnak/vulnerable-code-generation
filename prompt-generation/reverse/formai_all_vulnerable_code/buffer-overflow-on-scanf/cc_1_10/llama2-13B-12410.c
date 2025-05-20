//LLAMA2-13B DATASET v1.0 Category: Audio processing ; Style: happy
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

int main() {
    int happy = 1; // initialize happiness level to 1
    char name[50]; // array to store user's name
    int age; // variable to store user's age
    double joy; // variable to store joy level

    // welcome message
    printf("Hello! Welcome to the Happy Audio Processing Program!\n");

    // get user's name and age
    printf("What's your name? ");
    fgets(name, 50, stdin);
    printf("How old are you? ");
    scanf("%d", &age);

    // calculate joy level based on age
    joy = age * PI / 100;

    // happy audio processing
    if (happy == 1) {
        // play happy sound effects
        printf("Woo-hoo! Let's party! \n");
        system("playsound happy.wav");
    } else {
        // play sad sound effects
        printf("Aww... :'( \n");
        system("playsound sad.wav");
    }

    // update happiness level based on user's input
    printf("How do you feel? (type 1 for happy, 2 for sad)\n");
    scanf("%d", &happy);

    // loop through happy audio processing
    while (happy == 1) {
        // play happy sound effects
        printf("Yay! Let's keep partying! \n");
        system("playsound happy.wav");

        // ask user to rate their happiness level again
        printf("How do you feel? (type 1 for happy, 2 for sad)\n");
        scanf("%d", &happy);
    }

    // end program
    printf("Thanks for hanging out! Bye for now! \n");
    return 0;
}