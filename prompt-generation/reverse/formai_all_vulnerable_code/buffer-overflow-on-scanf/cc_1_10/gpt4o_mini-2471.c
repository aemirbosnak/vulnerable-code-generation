//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 10
#define MAX_CHAR 256

typedef struct {
    char *subject;
    char *claim;
    char *evidence;
} ConspiracyTheory;

ConspiracyTheory theories[MAX_THEORIES];

void initialize_theories() {
    theories[0] = (ConspiracyTheory){"Cats", "are secret agents", "They receive transmissions from the government."};
    theories[1] = (ConspiracyTheory){"Birds", "are actually surveillance drones", "They are designed by an unknown corporation."};
    theories[2] = (ConspiracyTheory){"Pineapple", "is a gateway to alternate dimensions", "Cultures have worshipped it for centuries."};
    theories[3] = (ConspiracyTheory){"Socks", "contain microchips", "They control your thoughts and actions."};
    theories[4] = (ConspiracyTheory){"The Moon", "is a hologram", "To distract us from the truth below."};
    theories[5] = (ConspiracyTheory){"Coffee", "is a government mind-control drug", "Destined to make you compliant."};
    theories[6] = (ConspiracyTheory){"Clouds", "are made of cotton candy", "That’s why they disappear when you touch them."};
    theories[7] = (ConspiracyTheory){"Your neighbor", "is a robot", "Built to gather intel on human behavior."};
    theories[8] = (ConspiracyTheory){"Aliens", "are living among us as baristas", "They fuel their motives through caffeine."};
    theories[9] = (ConspiracyTheory){"Weather", "is controlled by a secret society", "To instigate panic and confusion."};
}

void generate_random_theory() {
    srand(time(NULL));
    int index = rand() % MAX_THEORIES;

    printf("Conspiracy Theory:\n");
    printf("Subject: %s\n", theories[index].subject);
    printf("Claim: %s\n", theories[index].claim);
    printf("Evidence: %s\n\n", theories[index].evidence);
}

void display_intro() {
    printf("Welcome to the Conspiracy Theory Generator.\n");
    printf("Explore the hidden truths of our universe, if you dare...\n");
}

void display_choices() {
    printf("Would you like to generate another theory? (y/n): ");
}

int main() {
    char choice;
    
    initialize_theories();
    display_intro();

    do {
        generate_random_theory();
        display_choices();
        scanf(" %c", &choice);
        choice = tolower(choice);
    } while (choice == 'y');

    printf("Thank you for exploring the depths of intrigue!\n");
    return 0;
}