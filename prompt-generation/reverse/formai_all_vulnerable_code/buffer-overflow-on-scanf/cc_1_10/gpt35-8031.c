//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* conspiracy_theories[] = {
    "The moon landing was fake and filmed in a studio.",
    "Area 51 is hiding evidence of aliens among us.",
    "The government is controlling the weather with HAARP technology.",
    "9/11 was an inside job orchestrated by the government.",
    "The Illuminati controls all major world events and governments.",
    "Vaccines are a government ploy to control population growth.",
    "The world is run by a secret cabal of billionaires.",
    "The earth is flat and NASA is covering it up.",
    "Chemtrails are being used to control the minds of the general public.",
    "The government is hiding the cure for cancer for profit.",
    "Social media platforms are listening to our conversations for targeted advertising.",
    "The Mandela Effect is evidence of parallel universes.",
    "Bigfoot is real and being kept hidden by the government.",
    "UFOs sightings and abductions are being covered up by the government.",
    "The Illuminati controls the music industry and inserts subliminal messages in songs.",
    "The world is going through a population control program.",
};

int main() {
    srand(time(NULL)); // Set up random seed based on time

    // Generate a random conspiracy theory from the list
    int index = rand() % (sizeof(conspiracy_theories) / sizeof(char *));
    char *conspiracy = conspiracy_theories[index];

    // Introduce the conspiracy theory
    printf("Have you heard about the latest conspiracy theory floating around?\n");
    printf("%s\n\n", conspiracy);

    // Ask user if they believe the conspiracy theory
    printf("Do you believe this conspiracy theory?\n");
    printf("(1) Yes (2) No (3) I'm not sure\n");

    // Get user input and respond accordingly
    int response;
    scanf("%d", &response);

    switch (response) {
        case 1:
            printf("Interesting, you're part of the minority who believe in this theory.\n");
            break;
        case 2:
            printf("Ah, a skeptic. You're part of the majority on this one.\n");
            break;
        case 3:
            printf("I understand it can be difficult to know what to believe.\n");
            break;
        default:
            printf("I'm sorry, I didn't understand your response.\n");
            break;
    }

    return 0;
}