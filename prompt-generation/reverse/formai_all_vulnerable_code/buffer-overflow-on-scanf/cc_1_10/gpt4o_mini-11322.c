//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_BUFFER 256

const char *subjects[] = {
    "aliens",
    "government officials",
    "large corporations",
    "lizard people",
    "psychic squirrels",
    "deep state agents",
    "time travelers",
    "Bigfoot",
    "the moon landing",
    "the Illuminati"
};

const char *actions[] = {
    "are manipulating",
    "control",
    "monitor",
    "secretly breed",
    "have infiltrated",
    "have created hoaxes around",
    "are using advanced technology on",
    "have mind-controlled",
    "are actually helping",
    "are sowing discord among"
};

const char *locations[] = {
    "in Area 51",
    "in underground bunkers",
    "at the highest levels of power",
    "in the ocean depths",
    "in the Arctic Circle",
    "behind the scenes of Hollywood",
    "in secret laboratories",
    "on the International Space Station",
    "in national parks",
    "in the stock market"
};

const char *consequences[] = {
    "to distract us from the truth.",
    "to maintain their power.",
    "to enslave the human race.",
    "to profit off our ignorance.",
    "to manipulate the weather.",
    "to alter our perception of reality.",
    "to cover up their secrets.",
    "to control the food supply.",
    "to prevent us from achieving enlightenment.",
    "to create mass hysteria."
};

void generate_conspiracy_theory(char *buffer) {
    int subj_index = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int action_index = rand() % (sizeof(actions) / sizeof(actions[0]));
    int loc_index = rand() % (sizeof(locations) / sizeof(locations[0]));
    int cons_index = rand() % (sizeof(consequences) / sizeof(consequences[0]));

    snprintf(buffer, MAX_BUFFER, "%s %s %s %s", subjects[subj_index], actions[action_index], locations[loc_index], consequences[cons_index]);
}

void print_theories(int count) {
    char theory[MAX_BUFFER];
    for (int i = 0; i < count; i++) {
        generate_conspiracy_theory(theory);
        printf("Conspiracy Theory %d: %s\n", i + 1, theory);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("How many theories would you like to generate? (Max: %d): ", MAX_THEORIES);
    
    int count;
    scanf("%d", &count);
    
    if (count <= 0 || count > MAX_THEORIES) {
        printf("Please enter a valid number between 1 and %d.\n", MAX_THEORIES);
        return 1;
    }

    printf("\nGenerating %d Conspiracy Theories:\n", count);
    print_theories(count);
    
    return 0;
}