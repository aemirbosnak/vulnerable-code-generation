//FormAI DATASET v1.0 Category: Random ; Style: imaginative
// Welcome to the "Randomness in Space" program!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Let's set up our random seed
    srand(time(0));
    
    // We'll now ask the user to enter their age, so we can use it in our randomness
    printf("Welcome to Randomness in Space! Please enter your age: ");
    int age;
    scanf("%d", &age);
    
    // Now, let's generate some random numbers based on the user's age
    int random_one = rand() % age;
    int random_two = rand() % (age / 2);
    int random_three = rand() % (age * 2);
    
    // Let's print out the results of our random number generation
    printf("Your age is %d, so here are some random numbers based on that:\n", age);
    printf("Random 1: %d\n", random_one);
    printf("Random 2: %d\n", random_two);
    printf("Random 3: %d\n", random_three);
    
    // We're also going to generate a random space-themed word based on the user's age
    char* space_word;
    switch(age) {
        case 0 ... 10:
            space_word = "rocket";
            break;
        case 11 ... 20:
            space_word = "supernova";
            break;
        case 21 ... 30:
            space_word = "black hole";
            break;
        case 31 ... 40:
            space_word = "nebula";
            break;
        case 41 ... 50:
            space_word = "quasar";
            break;
        default:
            space_word = "galaxy";
            break;
    }
    printf("Your space-themed word is: %s\n", space_word);
    
    // Finally, let's generate a random space fact for the user
    int random_fact = rand() % 5;
    switch(random_fact) {
        case 0:
            printf("Did you know that Jupiter's Great Red Spot is a storm larger than the entire Earth, and it has been raging for hundreds of years?\n");
            break;
        case 1:
            printf("The nearest star to Earth, other than the Sun, is Proxima Centauri, which is about 4.24 light years away and is part of the Alpha Centauri triple star system.\n");
            break;
        case 2:
            printf("NASA's Voyager 1 spacecraft, launched in 1977, is the farthest man-made object from Earth and has traveled over 13 billion miles.\n");
            break;
        case 3:
            printf("There are more stars in the universe than there are grains of sand on all the beaches on Earth.\n");
            break;
        case 4:
            printf("In 2004, scientists discovered a giant diamond in space that is estimated to be about 10 billion trillion trillion carats!\n");
            break;
    }
    
    // Thanks for participating in Randomness in Space!
    return 0;
}