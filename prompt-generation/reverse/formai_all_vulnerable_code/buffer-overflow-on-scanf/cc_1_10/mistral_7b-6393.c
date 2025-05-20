//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FORTUNES 10

// Fortune cookies are magical objects, each one holding a unique message
const char *fortunes[MAX_FORTUNES] = {
    "You are destined for greatness!",
    "Prepare for a journey of self-discovery",
    "Good luck will find you when you least expect it",
    "Your creativity will bring you joy and success",
    "Patience and perseverance will pay off",
    "Your dreams will come true if you believe",
    "You have the power to change your own fate",
    "Embrace change and new opportunities",
    "The universe is conspiring in your favor",
    "Trust your instincts and follow your heart"
};

// A mysterious and ancient fortune telling algorithm
int tellFortune(int yearOfBirth) {
    int fortuneIndex = 0;
    srand(time(NULL) + yearOfBirth); // Seed the random number generator with the user's birth year
    fortuneIndex = rand() % MAX_FORTUNES; // Generate a random index within the range of available fortunes
    return fortuneIndex;
}

int main(void) {
    int yearOfBirth;
    int fortuneIndex;

    // Ask the user for their birth year and validate the input
    printf("Welcome, mortal, to the mystical realm of the fortune teller!\n");
    printf("Please enter the year of your birth: ");
    scanf("%d", &yearOfBirth);

    if (yearOfBirth <= 0) {
        printf("Invalid birth year. Please try again.\n");
        return 1;
    }

    // Call the fortune telling algorithm and display the result
    fortuneIndex = tellFortune(yearOfBirth);
    printf("The ancient oracle reveals your fortune:\n");
    printf("%s\n", fortunes[fortuneIndex]);

    return 0;
}