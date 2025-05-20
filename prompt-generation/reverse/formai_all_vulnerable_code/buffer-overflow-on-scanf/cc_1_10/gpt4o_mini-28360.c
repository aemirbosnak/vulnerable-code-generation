//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 100
#define MAX_ELEMENTS 10
#define MAX_LENGTH 256

const char *subjects[] = {
    "aliens", "the government", "big corporations", "the media", "the Illuminati", 
    "secret societies", "time travelers", "AI", "big pharma", "climate scientists"
};

const char *actions[] = {
    "are controlling", "are hiding", "are manipulating", "want to enslave", 
    "are in cahoots with", "created", "monitor", "brainwash", "distract", "farm"
};

const char *topics[] = {
    "the weather", "the internet", "social media", "our thoughts", 
    "economic growth", "healthcare", "extraterrestrial communication", 
    "voting systems", "ancient civilizations", "our dreams"
};

const char *conclusions[] = {
    "to keep us from knowing the truth.", "to ensure their dominance.", 
    "to control our minds.", "because they're afraid of the truth.", 
    "as part of a larger plan.", "to maintain their power.", 
    "because they want to oversee humanity.", "to distract us from their failures."
};

int random_index(int max) {
    return rand() % max;
}

void generate_theory(char *theory) {
    int subject_index = random_index(sizeof(subjects) / sizeof(subjects[0]));
    int action_index = random_index(sizeof(actions) / sizeof(actions[0]));
    int topic_index = random_index(sizeof(topics) / sizeof(topics[0]));
    int conclusion_index = random_index(sizeof(conclusions) / sizeof(conclusions[0]));

    snprintf(theory, MAX_LENGTH, "%s %s %s %s", 
             subjects[subject_index], 
             actions[action_index], 
             topics[topic_index], 
             conclusions[conclusion_index]);
}

void generate_multiple_theories(int count) {
    char theory[MAX_LENGTH];
    for (int i = 0; i < count; i++) {
        generate_theory(theory);
        printf("Conspiracy Theory %d: %s\n", i + 1, theory);
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int theory_count;

    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &theory_count);
    
    if (theory_count <= 0 || theory_count > MAX_THEORIES) {
        printf("Please enter a number between 1 and %d.\n", MAX_THEORIES);
        return 1;
    }

    generate_multiple_theories(theory_count);
    
    return 0;
}