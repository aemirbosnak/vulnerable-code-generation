//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 200
#define MAX_LENGTH 20

char* words[] = {
    "government",
    "illuminati",
    "chemtrails",
    "lizard people",
    "moon landing",
    "flat earth",
    "9/11",
    "JFK assassination",
    "Roswell",
    "Bigfoot",
    "Nessie",
    "UFOs",
    "Area 51",
    "MK Ultra",
    "New World Order",
    "Bilderberg Group",
    "Trilateral Commission",
    "Council on Foreign Relations",
    "Freemasons",
    "Skull and Bones",
    "Bohemian Grove",
    "Crisis actors",
    "Deep state",
    "False flag",
    "FEMA camps",
    "HAARP",
    "Mind control",
    "NWO",
    "Operation Northwoods",
    "Sandy Hook",
    "Tavistock Institute",
    "Zionist",
    "Agenda 21",
    "Ancient astronauts",
    "Atlantis",
    "Crop circles",
    "Cthulhu",
    "Elvis sightings",
    "Ghosts",
    "Haunted houses",
    "Innsmouth",
    "Jersey Devil",
    "Kraken",
    "Loch Ness Monster",
    "Mothman",
    "Nephilim",
    "Oklahoma City bombing",
    "Philadelphia Experiment",
    "QAnon",
    "Reptilians",
    "Skinwalker Ranch",
    "Tunguska event",
    "Underground cities",
    "Vampires",
    "Werewolves",
    "X-Files",
    "Yeti",
    "Zombies"
};

int main() {
    srand(time(NULL));
    char* theory[MAX_WORDS];
    int i, j, k, l;
    for (i = 0; i < MAX_WORDS; i++) {
        theory[i] = words[rand() % MAX_WORDS];
    }

    // Shuffle the words
    for (i = 0; i < MAX_WORDS; i++) {
        j = rand() % MAX_WORDS;
        char* temp = theory[i];
        theory[i] = theory[j];
        theory[j] = temp;
    }

    // Generate a random length for the theory
    k = rand() % MAX_LENGTH + 1;

    // Build the conspiracy theory
    printf("The truth is out there...\n");
    for (i = 0; i < k; i++) {
        l = rand() % MAX_WORDS;
        printf("%s ", theory[l]);
        if (i < k - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}