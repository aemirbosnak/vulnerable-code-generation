//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACY 100
#define MAX_LENGTH 512

const char *subjects[] = {
    "aliens", "governments", "celebrities", "corporations", 
    "scientists", "artificial intelligence", "big tech", "media", 
    "pharmaceuticals", "financial institutions", "environmentalists", "hackers"
};

const char *actions[] = {
    "control", "manipulate", "monitor", "influence",
    "distract", "exploit", "suppress", "disguise",
    "alter", "disrupt", "brainwash", "educate"
};

const char *objects[] = {
    "the weather", "the stock market", "social media", "the economy",
    "time travel", "climate change", "public opinion", "healthcare",
    "the internet", "space exploration", "natural disasters", "energy sources"
};

const char *crazy_facts[] = {
    "the number 7 is a universal key.", "pineapples grow under the sea in the Bermuda Triangle.",
    "birds aren't real; they're surveillance drones.", "there's a secret society of time travelers.",
    "moon landings were staged by Hollywood.", "the Loch Ness Monster is actually a prototype submarine.",
    "there's a hidden dimension controlled by cats.", "the pyramids were built by extraterrestrials.",
    "the 5G network is a tool for mind control.", "dinosaurs never existed; they were created for a movie.",
    "the Earth is a simulation and we are all characters in a game.", 
    "the government is using a secret mind control drug through fast food."
};

void generate_conspiracy_theory(char *theory) {
    // Create a random conspiracy theory
    int subject_index = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int action_index = rand() % (sizeof(actions) / sizeof(actions[0]));
    int object_index = rand() % (sizeof(objects) / sizeof(objects[0]));
    int fact_index = rand() % (sizeof(crazy_facts) / sizeof(crazy_facts[0]));
    
    snprintf(theory, MAX_LENGTH, "It's believed that %s use technology to %s %s, and that %s",
        subjects[subject_index], actions[action_index], objects[object_index], crazy_facts[fact_index]);
}

void generate_multiple_theories(int count) {
    char theory[MAX_LENGTH];
    for (int i = 0; i < count; i++) {
        generate_conspiracy_theory(theory);
        printf("Conspiracy Theory %d: %s\n\n", i + 1, theory);
    }
}

int main() {
    srand(time(NULL)); // Initialize the random seed
    int theory_count;

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("Enter the number of conspiracy theories you want to generate: ");
    scanf("%d", &theory_count);

    if (theory_count > MAX_CONSPIRACY) {
        printf("Limiting to %d theories as a maximum.\n", MAX_CONSPIRACY);
        theory_count = MAX_CONSPIRACY;
    }

    generate_multiple_theories(theory_count);
    printf("Thank you for using the Conspiracy Theory Generator!\n");
    return 0;
}