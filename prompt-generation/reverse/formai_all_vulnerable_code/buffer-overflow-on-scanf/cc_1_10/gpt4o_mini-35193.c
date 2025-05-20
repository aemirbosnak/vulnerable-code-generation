//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_LENGTH 256

typedef struct {
    char *title;
    char *description;
} ConspiracyTheory;

ConspiracyTheory theories[MAX_THEORIES] = {
    {"The Moon Landing Was Staged", 
     "In a secret agreement, the United States government staged the moon landing to distract the population from the Vietnam War."},
     
    {"The Assassination of JFK", 
     "John F. Kennedy was killed by a coalition of CIA agents and mobsters to prevent him from dismantling their organized crime operations."},

    {"Alien Bases on Earth", 
     "There are hidden bases around the world where world leaders meet with extraterrestrial beings to plot the future of humanity."},

    {"The Flat Earth", 
     "The Earth is flat, and this information is hidden by a vast network of scientists and politicians to control the populace."},

    {"Mind Control through Wi-Fi", 
     "Wi-Fi signals are being used to manipulate thoughts and behavior, creating a docile society that obeys government directives."},

    {"The 5G Network Conspiracy", 
     "5G technology is a cover for a mind-control program and a way to deploy surveillance techniques on the global population."},

    {"The Titanic Hoax", 
     "The sinking of the Titanic was faked to eliminate an elite group of bankers who opposed the establishment of the Federal Reserve."},

    {"The Bermuda Triangle", 
     "The Bermuda Triangle is a portal to another dimension, where missing ships and planes are trapped in an alternate reality."},

    {"Vaccines and Population Control", 
     "Vaccines are a method employed by elite factions to reduce global population under the guise of protecting public health."},

    {"The Reptilian Elite", 
     "World leaders are actually shape-shifting reptiles from another planet, conspiring to keep humanity in a state of ignorance."}
};

void print_theory(ConspiracyTheory theory) {
    printf("Title: %s\n", theory.title);
    printf("Description: %s\n\n", theory.description);
}

void random_conspiracy_theory() {
    srand(time(NULL));
    int random_index = rand() % MAX_THEORIES;
    print_theory(theories[random_index]);
}

void list_theories() {
    printf("Available Conspiracy Theories:\n");
    for (int i = 0; i < MAX_THEORIES; i++) {
        printf("%d. %s\n", i + 1, theories[i].title);
    }
    printf("\n");
}

int main() {
    int choice;
    
    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("Choose an option:\n");
    printf("1 - Get a Random Conspiracy Theory\n");
    printf("2 - List All Conspiracy Theories\n");
    printf("3 - Exit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                random_conspiracy_theory();
                break;
            case 2:
                list_theories();
                break;
            case 3:
                printf("Thank you for using the Conspiracy Theory Generator!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}