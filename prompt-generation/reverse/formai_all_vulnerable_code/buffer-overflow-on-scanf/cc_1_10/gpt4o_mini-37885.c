//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACIES 20
#define MAX_THEORIES 8
#define MAX_LENGTH 256

typedef struct {
    char *topic;
    char *theories[MAX_THEORIES];
} Conspiracy;

void initialize_conspiracies(Conspiracy *conspiracies) {
    conspiracies[0].topic = "Aliens";
    conspiracies[0].theories[0] = "are actually government agents monitoring us.";
    conspiracies[0].theories[1] = "built the pyramids as a signal of their return.";
    conspiracies[0].theories[2] = "are living among us disguised as politicians.";
    conspiracies[0].theories[3] = "control the world banking system through time travel.";
    
    conspiracies[1].topic = "Bigfoot";
    conspiracies[1].theories[0] = "is a result of genetic experimentation by a secret lab.";
    conspiracies[1].theories[1] = "is an alien trying to adapt to human society.";
    conspiracies[1].theories[2] = "has been sighted in all major cities as part of a map to hidden treasure.";
    
    conspiracies[2].topic = "Moon Landing";
    conspiracies[2].theories[0] = "was staged to distract from a world war.";
    conspiracies[2].theories[1] = "was a joint effort between NASA and a secret society.";
    conspiracies[2].theories[2] = "hides a colony of lizard people awaiting Earth's takeover.";
    
    conspiracies[3].topic = "Chemtrails";
    conspiracies[3].theories[0] = "are designed to control our minds via chemical infusion.";
    conspiracies[3].theories[1] = "spread a virus that only affects certain DNA types.";
    conspiracies[3].theories[2] = "are a cover-up for weather manipulation technology.";
    
    conspiracies[4].topic = "Flat Earth";
    conspiracies[4].theories[0] = "is a cover for a vast government conspiracy.";
    conspiracies[4].theories[1] = "is supported by certain scientists who want to keep us ignorant.";
    conspiracies[4].theories[2] = "is actually a dome structure maintained by elite aliens.";
    
    conspiracies[5].topic = "Reptilian Elite";
    conspiracies[5].theories[0] = "are controlling world governments through mind control.";
    conspiracies[5].theories[1] = "interbreed with humans to remain in power.";
    conspiracies[5].theories[2] = "have an underground base beneath the Antarctic ice.";
    
    conspiracies[6].topic = "Artificial Intelligence";
    conspiracies[6].theories[0] = "is a plot to eliminate humanity without direct confrontation.";
    conspiracies[6].theories[1] = "is secretly being controlled by undercover robots.";
    conspiracies[6].theories[2] = "is the next stage of evolution, one that humanity will stop at nothing to prevent.";
    
    conspiracies[7].topic = "Vaccines";
    conspiracies[7].theories[0] = "are a way to implant tracking devices in our bodies.";
    conspiracies[7].theories[1] = "cause more disease than they prevent as part of a population control scheme.";
    conspiracies[7].theories[2] = "contain substances that reprogram human DNA to create a super race.";
}

void generate_random_conspiracy(Conspiracy *conspiracies, int num_conspiracies) {
    srand(time(0));
    int random_index = rand() % num_conspiracies;
    int theory_index = rand() % MAX_THEORIES;

    printf("Conspiracy Theory!\n");
    printf("Topic: %s\n", conspiracies[random_index].topic);
    printf("Theory: %s\n", conspiracies[random_index].theories[theory_index]);
}

int main() {
    Conspiracy conspiracies[MAX_CONSPIRACIES];
    initialize_conspiracies(conspiracies);
    
    int choices;
    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("How many random conspiracy theories would you like to generate? ");
    scanf("%d", &choices);
    
    for (int i = 0; i < choices; i++) {
        generate_random_conspiracy(conspiracies, MAX_CONSPIRACIES);
        printf("\n");
    }

    printf("Remember, don't believe everything you hear... unless it's from our generator!\n");
    
    return 0;
}