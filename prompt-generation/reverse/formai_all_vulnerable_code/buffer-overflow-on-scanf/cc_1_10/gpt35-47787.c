//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

// function to display a message with a delay
void displayMessageWithDelay(char *message, int delay) {
    for (int i = 0; message[i] != '\0'; i++) {
        printf("%c", message[i]);
        fflush(stdout);  // flush the output stream
        usleep(delay * 1000);  // sleep for a given amount of time
    }
}

int main() {
    // set up the game
    printf("*** Welcome to the Procedural Space Adventure! ***\n\n");
    printf("You are the captain of a spaceship on a mission to explore the galaxy.\n");
    printf("Your crew is comprised of robots that you can control using a computer interface.\n\n");
    printf("The mission is simple: to explore as much of the galaxy as possible and discover new planets.\n");
    printf("Along the way, you will encounter mysterious alien life forms, hostile environments, and other challenges.\n\n");
    printf("Are you ready to begin? (type 'yes' to start)\n");

    // get the user's response
    char response[10];
    scanf("%s", response);
    if (strcmp(response, "yes") != 0) {
        printf("I'm sorry, I didn't understand that. Let's try again later.\n");
        return 0;
    }

    // start the game
    printf("\nGreat! Your spaceship is ready for launch.\n");
    printf("You initiate the launch sequence and blast off into space, leaving Earth behind.\n\n");

    // generate a random planet name and display it
    char planetName[30];
    sprintf(planetName, "Planet %d", generateRandomNumber(1, 100));
    printf("Your first destination is %s.\n", planetName);

    // travel to the planet and encounter an alien life form
    printf("\nAs you approach %s, you detect signs of life on the planet.\n", planetName);
    printf("You land your spaceship on the planet's surface and deploy your robot crew to explore.\n\n");

    // generate a random alien encounter
    int encounter = generateRandomNumber(1, 3);
    if (encounter == 1) {
        // friendly encounter
        printf("Your robots encounter an alien life form that is friendly and curious.\n");
        printf("They communicate with the alien using a universal translation device.\n");
        printf("The alien shares some knowledge about the planet and offers to trade some valuable resources.\n");
    } else if (encounter == 2) {
        // hostile encounter
        printf("Your robots encounter an alien life form that is hostile and aggressive.\n");
        printf("They attempt to attack your robots, but your crew is able to defend themselves.\n");
        printf("You decide to leave the planet before any further conflict.\n");
    } else {
        // mysterious encounter
        printf("Your robots encounter an unknown object that emits a strange energy field.\n");
        printf("They are unable to analyze or identify the object, and you decide to leave the planet for further investigation.\n");
    }

    // continue the adventure
    printf("\nAfter a successful mission on %s, you receive a transmission from headquarters with your next assignment.\n", planetName);
    printf("You input the coordinates into the navigation system and set a course for the next planet.\n");
    printf("As you travel deeper into space, you realize that there is much more to discover and explore.\n");
    printf("Your adventure continues...\n");

    return 0;
}