//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACIES 10
#define MAX_EVIDENCES 5
#define MAX_LOCATIONS 5
#define MAX_CHAR 200

const char *conspiracy_theories[MAX_CONSPIRACIES] = {
    "The moon landing was staged by NASA with the help of Hollywood.",
    "Aliens are secretly controlling world governments.",
    "The earth is flat and the government is hiding the truth.",
    "Time travelers are manipulating historical events.",
    "The COVID-19 virus is a bioweapon created by a secret organization.",
    "The Titanic sinking was an insurance scam.",
    "The existence of Bigfoot is being covered up to hide the truth about humanity's origins.",
    "Reptilian aliens live among us and shape global politics.",
    "Freemasons control the world from the shadows.",
    "Climate change is a hoax created by scientists for funding."
};

const char *evidences[MAX_EVIDENCES] = {
    "ancient texts that supposedly predict this event.",
    "a mysterious symbol found in the background of famous photographs.",
    "confidential documents leaked by a whistleblower.",
    "an eyewitness account from a credible source.",
    "cryptic messages embedded in popular media."
};

const char *locations[MAX_LOCATIONS] = {
    "Area 51 in Nevada.",
    "the Bermuda Triangle.",
    "the pyramids of Giza.",
    "Roswell, New Mexico.",
    "a secret facility under the Denver airport."
};

void generate_conspiracy_theory(char *theory) {
    int conspiracy_index = rand() % MAX_CONSPIRACIES;
    int evidence_index = rand() % MAX_EVIDENCES;
    int location_index = rand() % MAX_LOCATIONS;

    snprintf(theory, MAX_CHAR, 
        "Conspiracy Theory: %s\nEvidence: %s\nLocation: %s\n",
        conspiracy_theories[conspiracy_index],
        evidences[evidence_index],
        locations[location_index]);
}

void generate_multiple_theories(int num_theories) {
    if(num_theories <= 0 || num_theories > 100) {
        printf("Please enter a number between 1 and 100.\n");
        return;
    }
    
    char theory[MAX_CHAR];
    for(int i = 0; i < num_theories; i++) {
        generate_conspiracy_theory(theory);
        printf("%s", theory);
    }
}

int main() {
    srand(time(NULL));
    int num_theories;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("How many conspiracy theories would you like to generate (1-100)? ");
    scanf("%d", &num_theories);

    generate_multiple_theories(num_theories);
    
    printf("Remember, these theories are purely fictional! Keep questioning everything!\n");
    return 0;
}