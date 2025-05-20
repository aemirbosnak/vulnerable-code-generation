//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_TRIGGERS 10
#define NUM_ACTORS 10
#define NUM_OBJECTS 10
#define NUM_LOCATIONS 10
#define NUM_THEORIES 10

const char *triggers[NUM_TRIGGERS] = {
    "a global pandemic",
    "the moon landing",
    "the rise of social media",
    "a recent celebrity scandal",
    "climate change debates",
    "quantum computing breakthroughs",
    "the stock market crash",
    "a new vaccine",
    "the disappearance of a politician",
    "the discovery of extraterrestrial life"
};

const char *actors[NUM_ACTORS] = {
    "scientists",
    "government officials",
    "celebrities",
    "business tycoons",
    "spies",
    "journalists",
    "activists",
    "tech moguls",
    "AI entities",
    "mysterious figures"
};

const char *objects[NUM_OBJECTS] = {
    "unidentified flying objects",
    "secret documents",
    "hidden technology",
    "ancient artifacts",
    "advanced AI systems",
    "encrypted communications",
    "experimental drugs",
    "cloning machines",
    "unreleased films",
    "lost civilizations"
};

const char *locations[NUM_LOCATIONS] = {
    "Area 51",
    "a remote bunker",
    "Silicon Valley",
    "the Bermuda Triangle",
    "a deserted island",
    "an underground lab",
    "the Vatican",
    "Hollywood",
    "a classified military base",
    "the dark web"
};

const char *theories[NUM_THEORIES] = {
    "This is all a ploy to control the masses.",
    "They want to distract us from the real issues.",
    "It’s a way to funnel money into secret projects.",
    "They’re manipulating us through our screens.",
    "This is connected to hidden alien agendas.",
    "It's a test of public compliance.",
    "The truth is buried under layers of deception.",
    "They are experimenting on us for their own benefit.",
    "This will lead to totalitarianism.",
    "Only a select few know the real story."
};

void generate_conspiracy() {
    srand(time(NULL));

    const char *trigger = triggers[rand() % NUM_TRIGGERS];
    const char *actor = actors[rand() % NUM_ACTORS];
    const char *object = objects[rand() % NUM_OBJECTS];
    const char *location = locations[rand() % NUM_LOCATIONS];
    const char *theory = theories[rand() % NUM_THEORIES];

    printf("Conspiracy Theory:\n");
    printf("Trigger: %s\n", trigger);
    printf("Involves: %s\n", actor);
    printf("Concerning: %s\n", object);
    printf("Location: %s\n", location);
    printf("Conclusion: %s\n", theory);
    printf("\n");
}

int main() {
    int num_theories;
    printf("Enter the number of conspiracy theories you want to generate: ");
    scanf("%d", &num_theories);

    for (int i = 0; i < num_theories; i++) {
        generate_conspiracy();
    }

    return 0;
}