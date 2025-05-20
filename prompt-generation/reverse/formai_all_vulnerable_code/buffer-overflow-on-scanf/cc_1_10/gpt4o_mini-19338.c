//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TIME_BUBBLE_COUNT 5
#define ADVENTURE_COUNT 3

typedef struct {
    char *name;
    int onwardyear;
    char *landmark;
} TimeBubble;

typedef struct {
    char *scenario;
    char *insight;
} Adventure;

void initializeTimeBubbles(TimeBubble *bubbles) {
    bubbles[0] = (TimeBubble){"The Garden of Time", 3023, "The Eternal Tree"};
    bubbles[1] = (TimeBubble){"The Sea of Dreams", 2210, "The Whispering Waves"};
    bubbles[2] = (TimeBubble){"Mountains of Absurdity", 1480, "The Floating Peaks"};
    bubbles[3] = (TimeBubble){"City of Forgotten Souls", 4010, "The Glass Towers"};
    bubbles[4] = (TimeBubble){"The Lab of Broken Mirrors", 1789, "Cogs of the Past"};
}

void initializeAdventures(Adventure *adventures) {
    adventures[0] = (Adventure){"Befriending a clockwork bird", "Time isn't what it seems."};
    adventures[1] = (Adventure){"Dancing with shadows", "Reality is but a fleeting illusion."};
    adventures[2] = (Adventure){"Conversing with echoes", "The past whispers secrets to the future."};
}

void displayTimeBubbles(TimeBubble *bubbles) {
    printf("Available Time Bubbles:\n");
    for (int i = 0; i < TIME_BUBBLE_COUNT; i++) {
        printf("Bubble %d: %s (Year: %d, Landmark: %s)\n", i + 1, bubbles[i].name, bubbles[i].onwardyear, bubbles[i].landmark);
    }
}

void displayAdventures(Adventure *adventures) {
    printf("\nAdventures Awaiting:\n");
    for (int i = 0; i < ADVENTURE_COUNT; i++) {
        printf("Scenario %d: %s\nInsight: %s\n\n", i + 1, adventures[i].scenario, adventures[i].insight);
    }
}

void timeTravel(int choice, TimeBubble *bubbles) {
    printf("You are now traveling to '%s' in the year %d...\n", bubbles[choice - 1].name, bubbles[choice - 1].onwardyear);
    sleep(2);
    printf("You have arrived at the '%s'.\n", bubbles[choice - 1].landmark);
}

void surrealExperience() {
    printf("\nAmidst the swirling colors and unexpected musings,\n");
    printf("You encounter a being made of liquid shadows, swaying to a forgotten tune.\n");
    srand(time(NULL));
    int random = rand() % 3;

    switch (random) {
        case 0:
            printf("It offers you a riddle:\n'What is the shape of a thought in flight?'\n");
            break;
        case 1:
            printf("It hands you a time-worn book,\nfilled with tales untold and dreams unbound.\n");
            break;
        case 2:
            printf("It asks you to dance, weaving in and out, drawing you into a spiral of time.\n");
            break;
    }
}

int main() {
    TimeBubble bubbles[TIME_BUBBLE_COUNT];
    Adventure adventures[ADVENTURE_COUNT];

    initializeTimeBubbles(bubbles);
    initializeAdventures(adventures);
    
    int choice;

    while (1) {
        displayTimeBubbles(bubbles);
        printf("Select a Time Bubble to travel (1-%d) or press 0 to exit: ", TIME_BUBBLE_COUNT);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("You decide to stay among the whispers of time.\n");
            break;
        } else if (choice < 1 || choice > TIME_BUBBLE_COUNT) {
            printf("A swirl of confusion encircles you! Choose wisely.\n");
            continue;
        }

        timeTravel(choice, bubbles);
        displayAdventures(adventures);
        
        printf("Would you like to have a surreal experience? (1 for yes, 0 for no): ");
        int experience_choice;
        scanf("%d", &experience_choice);
        
        if (experience_choice == 1) {
            surrealExperience();
        }

        printf("Would you like to travel through another Time Bubble? (1 for yes, 0 for no): ");
        int travel_again;
        scanf("%d", &travel_again);
        if (travel_again == 0) {
            printf("You return to your own time, enriched but never quite the same.\n");
            break;
        }
    }

    return 0;
}