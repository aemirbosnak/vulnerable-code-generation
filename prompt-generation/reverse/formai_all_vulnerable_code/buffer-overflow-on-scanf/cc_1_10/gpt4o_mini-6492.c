//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_LENGTH 256

typedef struct {
    char* subject;
    char* evidence;
    char* theory;
} ConspiracyTheory;

ConspiracyTheory theories[MAX_THEORIES];

void initialize_theories() {
    theories[0].subject = "The Moon Landing";
    theories[0].evidence = "faked by NASA using Hollywood sets";
    theories[0].theory = "The moon landing was staged to distract from the Vietnam War.";

    theories[1].subject = "Area 51";
    theories[1].evidence = "unclassified documents regarding alien technology";
    theories[1].theory = "Area 51 is a cover for reverse engineering extraterrestrial spacecraft.";

    theories[2].subject = "The Denver Airport";
    theories[2].evidence = "unusual artwork and secret underground tunnels";
    theories[2].theory = "The Denver Airport is a hub for the Illuminati's activities.";

    theories[3].subject = "JFK Assassination";
    theories[3].evidence = "multiple gunman sightings at the scene";
    theories[3].theory = "The assassination was orchestrated by multiple agencies to impose control.";

    theories[4].subject = "COVID-19 Origins";
    theories[4].evidence = "a suspicious lab leak in Wuhan";
    theories[4].theory = "COVID-19 was intentionally released to destabilize global economies.";

    theories[5].subject = "Flat Earth";
    theories[5].evidence = "photoshopped images from space agencies";
    theories[5].theory = "The world is flat to conceal the edge of the universe.";

    theories[6].subject = "Celebrity Clones";
    theories[6].evidence = "strange looks and behaviors of public figures";
    theories[6].theory = "Celebrities are replaced by clones to control public opinion.";

    theories[7].subject = "Chemtrails";
    theories[7].evidence = "persistent cloud patterns left by aircraft";
    theories[7].theory = "Chemtrails are used for weather manipulation and controlling populations.";

    theories[8].subject = "Bigfoot";
    theories[8].evidence = "various grainy photos and local folklore";
    theories[8].theory = "Bigfoot is a government experiment gone wrong in the Pacific Northwest.";

    theories[9].subject = "Time Travel";
    theories[9].evidence = "alleged sightings of time-traveling individuals";
    theories[9].theory = "Governments have achieved time travel and use it for historical manipulation.";
}

void print_theory(ConspiracyTheory theory) {
    printf("Subject: %s\n", theory.subject);
    printf("Evidence: %s\n", theory.evidence);
    printf("Theory: %s\n\n", theory.theory);
}

void random_theory() {
    srand(time(0));
    int index = rand() % MAX_THEORIES;
    print_theory(theories[index]);
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Get ready to unveil the secrets of the universe...\n\n");

    initialize_theories();

    int again = 1;
    while (again) {
        random_theory();
        printf("Would you like another conspiracy theory? (1: Yes / 0: No): ");
        scanf("%d", &again);
        printf("\n");
    }

    printf("Thank you for using the Random Conspiracy Theory Generator. Stay curious!\n");
    return 0;
}