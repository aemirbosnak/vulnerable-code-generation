//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory *generate_theory(void) {
    ConspiracyTheory *theory = malloc(sizeof(ConspiracyTheory));

    srand(time(NULL));
    int index = rand() % 10;

    switch(index) {
        case 0:
            theory->name = "Flat Earth Society";
            theory->description = "The belief that the Earth is flat and all evidence to the contrary is a conspiracy.";
            break;
        case 1:
            theory->name = "Moon Landing Hoax";
            theory->description = "The belief that the Apollo moon landings were faked and staged by NASA.";
            break;
        case 2:
            theory->name = "9/11 Inside Job";
            theory->description = "The belief that the 9/11 attacks were orchestrated by the US government.";
            break;
        case 3:
            theory->name = "Chemtrails";
            theory->description = "The belief that the trails left by aircraft are actually chemicals or biological agents deliberately sprayed for sinister purposes.";
            break;
        case 4:
            theory->name = "Illuminati";
            theory->description = "The belief in a secret society that controls world events and governments.";
            break;
        case 5:
            theory->name = "Area 51";
            theory->description = "The belief that Area 51 is a top-secret government facility where alien technology is studied.";
            break;
        case 6:
            theory->name = "Reptilian Elite";
            theory->description = "The belief that shape-shifting reptilian humanoids control world politics and the media.";
            break;
        case 7:
            theory->name = "New World Order";
            theory->description = "The belief in a secretive power elite with a globalist agenda conspiring to eventually rule the world through an authoritarian world government.";
            break;
        case 8:
            theory->name = "Bigfoot";
            theory->description = "The belief that Bigfoot, also known as Sasquatch, is a real creature that inhabits the forests of North America.";
            break;
        case 9:
            theory->name = "Loch Ness Monster";
            theory->description = "The belief that a prehistoric creature, often described as a plesiosaur, lives in Loch Ness, Scotland.";
            break;
    }

    return theory;
}

void print_theory(ConspiracyTheory *theory) {
    printf("Name: %s\n", theory->name);
    printf("Description: %s\n", theory->description);
}

int main(void) {
    ConspiracyTheory *theory = generate_theory();
    print_theory(theory);

    free(theory);
    return 0;
}