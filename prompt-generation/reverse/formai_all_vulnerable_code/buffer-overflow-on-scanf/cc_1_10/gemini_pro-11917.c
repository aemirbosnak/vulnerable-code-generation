//GEMINI-pro DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A hilarious data structure to store our jokes
typedef struct Joke {
    char *question;
    char *answer;
} Joke;

// An array of knee-slapping jokes
Joke jokes[] = {
    {"What do you call a fish with no eyes?" , "Fsh"},
    {"What do you call a bee that can't make up its mind?" , "A maybe"},
    {"What do you call a boomerang that doesn't come back?" , "A stick"},
    {"Why did the scarecrow win an award?" , "Because he was outstanding in his field!"},
    {"What do you call a lazy kangaroo?" , "A pouch potato"},
    {"What do you call a cow with no legs?" , "Ground beef"},
    {"Why did the golfer wear two pairs of pants?" , "In case he got a hole-in-one"},
    {"What do you call a fish with no eyes?" , "Fsh"},
    {"What do you call a bee that can't make up its mind?" , "A maybe"},
    {"What do you call a boomerang that doesn't come back?" , "A stick"},
    {"Why did the scarecrow win an award?" , "Because he was outstanding in his field!"},
    {"What do you call a lazy kangaroo?" , "A pouch potato"},
    {"What do you call a cow with no legs?" , "Ground beef"},
    {"Why did the golfer wear two pairs of pants?" , "In case he got a hole-in-one"},
    {"What do you call a fish with no eyes?" , "Fsh"},
    {"What do you call a bee that can't make up its mind?" , "A maybe"},
    {"What do you call a boomerang that doesn't come back?" , "A stick"},
    {"Why did the scarecrow win an award?" , "Because he was outstanding in his field!"},
    {"What do you call a lazy kangaroo?" , "A pouch potato"},
    {"What do you call a cow with no legs?" , "Ground beef"},
    {"Why did the golfer wear two pairs of pants?" , "In case he got a hole-in-one"},
};

// A function to randomly select and print a joke
void tell_joke() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random index into the array of jokes
    int index = rand() % (sizeof(jokes) / sizeof(Joke));

    // Print the joke
    printf("Question: %s\n", jokes[index].question);
    printf("Answer: %s\n\n", jokes[index].answer);
}

int main() {
    // Welcome the user to the joke machine
    printf("Welcome to the Joke Machine! Get ready to laugh out loud!\n");

    // Keep telling jokes until the user wants to quit
    while (1) {
        // Ask the user if they want to hear another joke
        char input[10];
        printf("Do you want to hear another joke? (y/n): ");
        scanf("%s", input);

        // Check if the user wants to quit
        if (strcmp(input, "n") == 0) {
            printf("Okay, see you next time!\n");
            break;
        }

        // Tell a joke
        tell_joke();
    }

    return 0;
}