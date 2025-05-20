//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CONSPIRACIES 100

typedef struct {
    char* name;
    char* description;
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES] = {
    {"Flat Earth Society", "The Earth is flat and all evidence to the contrary is a conspiracy."},
    {"Moon Landing Hoax", "The Apollo moon landings were faked by the US government."},
    {"Area 51 Aliens", "The US government is hiding extraterrestrial life at Area 51."},
    {"9/11 Inside Job", "The US government orchestrated the 9/11 attacks."},
    {"Chemtrails", "The trails left by airplanes are actually chemicals being sprayed on the population."},
    {"Illuminati", "A secret society controls world events and governments."},
    {"Lizard People", "Shape-shifting reptilian aliens control world governments."},
    {"New World Order", "A secretive power elite with a globalist agenda is conspiring to rule the world."},
    {"Vaccine Conspiracy", "Vaccines are part of a plot to control or harm the population."},
    {"Climate Change Hoax", "The scientific consensus on climate change is a hoax perpetrated by governments and scientists."}
};

void generateRandomConspiracy() {
    srand(time(NULL));
    int index = rand() % MAX_CONSPIRACIES;
    printf("Random Conspiracy Theory: %s\n", conspiracies[index].name);
    printf("Description: %s\n", conspiracies[index].description);
}

int main() {
    int choice;

    do {
        printf("Welcome to the Random Conspiracy Theory Generator!\n");
        printf("Please choose an option:\n");
        printf("1. Generate a random conspiracy theory\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                generateRandomConspiracy();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 2);

    return 0;
}