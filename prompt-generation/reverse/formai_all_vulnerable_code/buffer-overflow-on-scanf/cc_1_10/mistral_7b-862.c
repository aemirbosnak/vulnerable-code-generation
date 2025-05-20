//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CASES 5
#define MAX_CLUES 10

struct case_t {
    char name[50];
    int year;
    char* clues[MAX_CLUES];
};

struct case_t cases[MAX_CASES] = {
    {"A Study in Scarlet", 1887, {"Rumored affair", "Red handprint", "Mysterious letter"}},
    {"The Sign of Four", 1890, {"Footprints in the snow", "Empty tobacco pouch", "Ciphered note"}},
    {"The Hound of the Baskervilles", 1892, {"Footprints in the mud", "Curious dog behavior", "Ghostly howls"}},
    {"The Adventure of the Speckled Band", 1892, {"Poisoned gas", "Screaming in the night", "Mysterious phone call"}},
    {"The Final Problem", 1894, {"Strange footprints", "Desperate letter", "Encounter with Moriarty"}}
};

void travel_back_in_time(int year) {
    int i;

    for (i = 0; i < MAX_CASES; i++) {
        if (cases[i].year == year) {
            printf("Case: %s\n", cases[i].name);
            int j;

            for (j = 0; j < MAX_CLUES; j++) {
                if (cases[i].clues[j] != NULL) {
                    printf("- Clue: %s\n", cases[i].clues[j]);
                }
            }

            break;
        }
    }
}

int main() {
    int year;

    printf("Sherlock Holmes Time Travel Simulator\n");
    printf("Enter the year of the case you want to examine: ");
    scanf("%d", &year);

    travel_back_in_time(year);

    return 0;
}