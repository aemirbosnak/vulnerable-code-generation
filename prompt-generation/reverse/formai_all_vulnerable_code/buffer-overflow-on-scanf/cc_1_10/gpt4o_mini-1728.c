//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SENTENCES 10
#define MAX_FACTS 50
#define MAX_THEORIES 20
#define MAX_LENGTH 256

char *sentences[MAX_SENTENCES] = {
    "The moon landing was staged to distract from governmental corruption.",
    "Aliens are secretly living among us, disguised as world leaders.",
    "Vaccines are a means of population control, hidden in plain sight.",
    "Time travel has been discovered, but only the elite can harness its power.",
    "The internet was created as a way for the government to keep tabs on us.",
    "Birds are drones, surveilling us under the guise of nature.",
    "Global warming is a hoax perpetuated by scientists seeking funding.",
    "The pyramids were built by alien technology, kept secret by historians.",
    "Every major world event is orchestrated by the Illuminati.",
    "Your smartphone is a direct link to a surveillance network run by AI."
};

char *facts[MAX_FACTS] = {
    "75% of all humans have a doppelgänger somewhere in the world.",
    "Cats are studying humans to eventually take over the planet.",
    "The Great Wall of China is actually a giant alien landing strip.",
    "All conspiracy theories are intertwined, like a giant web.",
    "Lizards can change their color and blend into society for a reason.",
    "Every major historical figure was replaced by a clone at some point.",
    "Coca-Cola contains a secret ingredient that enhances human intuition.",
    "Gravity is just a theory; what if we are being held down by something more?",
    "The Bermuda Triangle is a portal to other dimensions.",
    "Historical events are recorded differently in parallel universes."
};

char *theories[MAX_THEORIES] = {
    "What if our thoughts are not our own, but implanted by an external source?",
    "Could it be that our dreams are actually glimpses into alternate realities?",
    "Is it possible that every time we choose, a new universe splits off?",
    "What if sleep is merely a state where our consciousness escapes?",
    "What if we are living in a matrix, controlled by an unknown intelligence?",
    "Are animals sentient beings trying to communicate with us through behavior?",
    "Could ancient civilizations have reached technological heights beyond our current understanding?",
    "What if our history is a cycle that repeats until we learn the lesson?",
    "Is time an illusion, and we are simply moving through a holographic projection?",
    "What if our emotions are being manipulated by unseen forces?"
};

void generate_conspiracy_theory() {
    srand(time(NULL));
    int s_index = rand() % MAX_SENTENCES;
    int f_index = rand() % MAX_FACTS;
    int t_index = rand() % MAX_THEORIES;

    printf("Conspiracy Theory:\n");
    printf("%s\n", sentences[s_index]);
    printf("Supporting Fact: %s\n", facts[f_index]);
    printf("Mind-Bending Theory: %s\n\n", theories[t_index]);
}

int main() {
    int n;

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("Enter the number of conspiracy theories you'd like to generate (up to %d): ", 5);
    scanf("%d", &n);

    if (n > 5) {
        printf("Please choose a number 5 or less.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        generate_conspiracy_theory();
    }

    printf("Remember to keep questioning the reality around you!\n");
    return 0;
}