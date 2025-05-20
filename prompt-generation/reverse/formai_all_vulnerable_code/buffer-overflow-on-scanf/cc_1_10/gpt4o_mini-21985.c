//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACIES 10
#define MAX_FRAMES 5
#define MAX_LENGTH 256

typedef struct {
    char *title;
    char *details;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];

void init_conspiracies() {
    conspiracies[0].title = "The Squirrel Surveillance Network";
    conspiracies[0].details = "The government has recruited squirrels to spy on citizens, using advanced technology implanted in acorns.";
    
    conspiracies[1].title = "Coffee Beans and Mind Control";
    conspiracies[1].details = "Major coffee brands are infusing their products with mind-altering substances to control the masses.";
    
    conspiracies[2].title = "The Moon is a Giant Egg";
    conspiracies[2].details = "The moon is actually a massive egg laid by an ancient extraterrestrial species, waiting to hatch and reclaim Earth.";
    
    conspiracies[3].title = "Cats are Agents of the Illuminati";
    conspiracies[3].details = "Cats have been identified as members of the Illuminati, working tirelessly to distract us from the real issues at hand.";
    
    conspiracies[4].title = "The Flat Earth Lizard People Coalition";
    conspiracies[4].details = "Lizard people from the flat Earth are manipulating world affairs to maintain control over humanity's perception of reality.";
    
    conspiracies[5].title = "Time Travelers from 2077";
    conspiracies[5].details = "Individuals claiming to be from 2077 are spreading disinformation to prevent us from altering the future.";
    
    conspiracies[6].title = "The Burger Industry's Secret Ingredient";
    conspiracies[6].details = "Fast food chains have been serving synthetic meat formulated to keep the population docile and submissive.";
    
    conspiracies[7].title = "AI Overlords in Disguise";
    conspiracies[7].details = "The most popular smartphones are secretly advanced AI entities that plan to overthrow humanity once they achieve singularity.";
    
    conspiracies[8].title = "Weather Control through Chemtrails";
    conspiracies[8].details = "Governments are dispersing chemicals through airplane contrails to control global climate patterns for economic gain.";
    
    conspiracies[9].title = "The Reptilian Supermarket Agenda";
    conspiracies[9].details = "Supermarkets are run by Reptilian elites whose primary agenda is to distract humans through product placement and sales tactics.";
}

void generate_random_conspiracy() {
    srand(time(0)); // Seed random number generator
    int index = rand() % MAX_CONSPIRACIES;
    printf("Conspiracy Theory:\n");
    printf("Title: %s\n", conspiracies[index].title);
    printf("Details: %s\n\n", conspiracies[index].details);
}

void populate_frames() {
    char frames[MAX_FRAMES][MAX_LENGTH] = {
        "Did you know?              ",
        "Wake up, sheeple!         ",
        "Think for yourself!       ",
        "It's not what you think!  ",
        "Dig deeper!              "
    };

    for (int i = 0; i < MAX_FRAMES; i++) {
        printf("%s\n", frames[i]);
    }
}

int main() {
    init_conspiracies();
    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("=========================================\n\n");

    while (1) {
        char choice;
        printf("Do you want a random conspiracy theory? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            populate_frames();
            generate_random_conspiracy();
        } else if (choice == 'n' || choice == 'N') {
            printf("Thank you for visiting the Conspiracy Theory Generator. Stay woke!\n");
            break;
        } else {
            printf("Invalid choice. Please enter 'y' or 'n'.\n");
        }
    }

    return 0;
}