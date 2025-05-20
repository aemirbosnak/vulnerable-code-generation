//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 100
#define MAX_LENGTH 256

typedef struct {
    char premise[MAX_LENGTH];
    char evidence[MAX_LENGTH];
    char conclusion[MAX_LENGTH];
} ConspiracyTheory;

const char *premises[] = {
    "The moon landing was faked because",
    "Aliens are controlling the government through",
    "The COVID-19 virus was created as a",
    "Climate change is a hoax invented for",
    "The Earth is flat to hide",
    "Big Tech is spying on us using",
    "The pyramids were built by",
    "Time travel exists, and",
    "The vaccine contains microchips to",
    "The Illuminati is running the world by"
};

const char *evidences[] = {
    "highly classified film footage.",
    "secret messages in popular movies.",
    "the involvement of top scientists in conspiracy.",
    "secret weather control devices.",
    "advanced mathematics that they don't want you to know.",
    "mind control technology hidden in social media.",
    "ancient aliens from the planet Zog.",
    "a time machine found in Area 51.",
    "the elite wanting to reduce the population.",
    "manipulating reality through our perceptions."
};

const char *conclusions[] = {
    "This proves that society is being manipulated.",
    "It's time to awaken the masses.",
    "We must uncover the truth.",
    "Only the enlightened will understand.",
    "We are on the brink of a new revelation.",
    "This is just the tip of the iceberg.",
    "Nothing is as it seems.",
    "The truth is out there.",
    "Stay vigilant against the lies.",
    "The awakening has begun."
};

void generateTheory(ConspiracyTheory *theory) {
    int premiseIndex = rand() % (sizeof(premises) / sizeof(premises[0]));
    int evidenceIndex = rand() % (sizeof(evidences) / sizeof(evidences[0]));
    int conclusionIndex = rand() % (sizeof(conclusions) / sizeof(conclusions[0]));

    strcpy(theory->premise, premises[premiseIndex]);
    strcpy(theory->evidence, evidences[evidenceIndex]);
    strcpy(theory->conclusion, conclusions[conclusionIndex]);
}

void printTheory(const ConspiracyTheory *theory) {
    printf("Premise: %s\n", theory->premise);
    printf("Evidence: %s\n", theory->evidence);
    printf("Conclusion: %s\n\n", theory->conclusion);
}

void printAllTheories(ConspiracyTheory theories[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Theory %d:\n", i + 1);
        printTheory(&theories[i]);
    }
}

int main() {
    srand(time(NULL));
    ConspiracyTheory theories[MAX_THEORIES];
    int theoryCount;

    printf("Enter the number of conspiracy theories to generate (1 - %d): ", MAX_THEORIES);
    scanf("%d", &theoryCount);

    if (theoryCount < 1 || theoryCount > MAX_THEORIES) {
        printf("Invalid number of theories. Exiting the program.\n");
        return 1;
    }

    for (int i = 0; i < theoryCount; i++) {
        generateTheory(&theories[i]);
    }

    printf("\nGenerated Conspiracy Theories:\n");
    printAllTheories(theories, theoryCount);

    return 0;
}