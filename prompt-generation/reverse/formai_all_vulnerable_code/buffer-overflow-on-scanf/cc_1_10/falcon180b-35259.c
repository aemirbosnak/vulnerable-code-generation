//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CONSPIRACIES 100

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory conspiracies[NUM_CONSPIRACIES] = {
    {"Moon Landing Hoax", "The idea that the Apollo Moon landings were faked."},
    {"Flat Earth", "The belief that the Earth is flat, rather than a sphere."},
    {"9/11 Inside Job", "The theory that the US government was behind the 9/11 attacks."},
    {"Chemtrails", "The idea that the trails left by airplanes are actually chemicals being sprayed into the atmosphere."},
    {"Area 51", "The belief that the US government is hiding extraterrestrial life at a secret base in Nevada."},
    {"Lizard People", "The theory that shape-shifting reptilian aliens control the world's governments."},
    {"Illuminati", "The belief that a secret society controls world events and governments."},
    {"New World Order", "The idea that a powerful group is working to establish a global government."},
    {"JFK Assassination", "The theory that Lee Harvey Oswald did not act alone in the assassination of President John F. Kennedy."},
    {"Roswell UFO Incident", "The belief that a UFO crashed in Roswell, New Mexico in 1947 and the US government covered it up."}
};

int main() {
    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("What kind of conspiracy are you in the mood for?\n");
    printf("1. Classic Conspiracies\n");
    printf("2. Modern Conspiracies\n");
    printf("3. Technology Conspiracies\n");
    printf("4. Political Conspiracies\n");
    printf("5. Alien Conspiracies\n");
    printf("6. Historical Conspiracies\n");
    printf("7. Romantic Conspiracies\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You've chosen Classic Conspiracies!\n");
            break;
        case 2:
            printf("You've chosen Modern Conspiracies!\n");
            break;
        case 3:
            printf("You've chosen Technology Conspiracies!\n");
            break;
        case 4:
            printf("You've chosen Political Conspiracies!\n");
            break;
        case 5:
            printf("You've chosen Alien Conspiracies!\n");
            break;
        case 6:
            printf("You've chosen Historical Conspiracies!\n");
            break;
        case 7:
            printf("You've chosen Romantic Conspiracies!\n");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    int conspiracyIndex;
    do {
        conspiracyIndex = rand() % NUM_CONSPIRACIES;
    } while (conspiracies[conspiracyIndex].name == NULL);

    printf("Your random conspiracy theory is: %s\n", conspiracies[conspiracyIndex].name);
    printf("Description: %s\n", conspiracies[conspiracyIndex].description);

    return 0;
}