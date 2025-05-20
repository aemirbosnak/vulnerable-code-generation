//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_CONSPIRACIES 100

char *conspiracies[] = {
    "The moon landing was faked.",
    "Aliens are among us.",
    "The government is hiding the cure for cancer.",
    "9/11 was an inside job.",
    "The Illuminati controls the world.",
    "Paul McCartney is dead.",
    "Elvis Presley is alive.",
    "The CIA killed JFK.",
    "The Earth is flat.",
    "The government is spraying mind control chemicals in our water supply.",
    "The Bilderberg Group is a secret cabal that runs the world.",
    "The New World Order is coming.",
    "The Illuminati is planning to implant microchips in our bodies.",
    "The government is suppressing the truth about climate change.",
    "The United States is secretly run by a group of Satanists.",
    "The world is going to end in 2012.",
    "The government is using HAARP to control the weather.",
    "The government is using drones to spy on us.",
    "The government is planning to create a one-world government.",
    "The government is using mind control to turn us into slaves.",
    "The government is using subliminal messages to control our minds.",
    "The government is planning to use a nuclear weapon to start World War III.",
    "The government is planning to use a bioweapon to kill off the population.",
    "The government is planning to use a directed energy weapon to destroy the world.",
    "The government is planning to use a weather modification weapon to control the weather.",
    "The government is planning to use a geological weapon to cause earthquakes and tsunamis.",
    "The government is planning to use a space weapon to destroy satellites and other spacecraft.",
    "The government is planning to use a cyber weapon to attack the Internet and other computer systems.",
    "The government is planning to use a financial weapon to crash the economy and cause widespread chaos.",
    "The government is planning to use a social weapon to divide the population and cause social unrest.",
    "The government is planning to use a psychological weapon to manipulate our emotions and thoughts.",
    "The government is planning to use a biological weapon to create a new disease that will kill millions of people.",
    "The government is planning to use a chemical weapon to毒害our food and water supply.",
    "The government is planning to use a nuclear weapon to destroy a major city.",
    "The government is planning to use a biological weapon to create a new pandemic.",
    "The government is planning to use a chemical weapon to poison the air we breathe.",
    "The government is planning to use a nuclear weapon to destroy the world."
};

int main() {
    srand(time(NULL));

    int num_conspiracies = rand() % MAX_CONSPIRACIES + 1;

    for (int i = 0; i < num_conspiracies; i++) {
        printf("%s\n", conspiracies[rand() % MAX_CONSPIRACIES]);
    }

    return 0;
}