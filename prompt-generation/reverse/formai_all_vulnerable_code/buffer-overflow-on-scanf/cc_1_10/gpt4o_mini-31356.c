//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_ELEMENTS 5
#define MAX_LENGTH 100

char *elements[MAX_ELEMENTS] = {
    "aliens", 
    "government surveillance",
    "mind control",
    "secret societies",
    "time travel"
};

char *subjects[MAX_THEORIES] = {
    "the moon landing",
    "the Bermuda Triangle",
    "the assassination of JFK",
    "the COVID-19 pandemic",
    "climate change",
    "the 5G network",
    "Bigfoot sightings",
    "the flat earth theory",
    "the disappearance of MH370",
    "the Roswell incident"
};

char *causes[MAX_THEORIES] = {
    "to cover up their involvement in intergalactic trade.", 
    "to distract citizens from their real agenda.", 
    "to control the population mentally.", 
    "to maintain power over the masses.", 
    "to channel resources into hidden projects.", 
    "to prevent humanity from discovering ancient technologies.", 
    "to create panic and manipulate stock markets.", 
    "to preserve secrets of time travel experiments.", 
    "to hide evidence of extraterrestrial life.", 
    "to enforce a new world order."
};

char *locations[MAX_THEORIES] = {
    "a hidden base in Antarctica.", 
    "the depths of the ocean near the Mariana Trench.", 
    "beneath the streets of major cities.", 
    "inside Area 51.", 
    "under Mount Shasta.", 
    "in the heart of the Amazon rainforest.", 
    "somewhere in the North Pole.", 
    "in ancient pyramids across the world.", 
    "hidden in plain sight on the internet.", 
    "within the vast expanse of outer space."
};

char *actions[MAX_THEORIES] = {
    "exchanging information with alien civilizations.", 
    "monitoring our thoughts through advanced satellites.", 
    "altering the past by changing timelines.", 
    "disguising experiments as natural disasters.", 
    "deploying technology to govern minds.", 
    "hiding evidence of human-alien collaboration.", 
    "developing a technology to erase memories.", 
    "implementing secret laws that limit freedom.", 
    "manipulating weather patterns for political gain.", 
    "creating crises to heighten their control."
};

void generate_conspiracy_theory() {
    int subject_index = rand() % MAX_THEORIES;
    int element_index = rand() % MAX_ELEMENTS;
    int cause_index = rand() % MAX_THEORIES;
    int location_index = rand() % MAX_THEORIES;
    int action_index = rand() % MAX_THEORIES;

    printf("Conspiracy Theory:\n");
    printf("The %s is actually a cover-up involving %s. ", subjects[subject_index], elements[element_index]);
    printf("The government is orchestrating this %s %s ", causes[cause_index], locations[location_index]);
    printf("to prevent us from discovering that they are %s.\n\n", actions[action_index]);
}

int main() {
    srand(time(NULL));
    int number_of_theories;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Enter the number of conspiracy theories to generate (up to %d): ", MAX_THEORIES);
    scanf("%d", &number_of_theories);

    if (number_of_theories > MAX_THEORIES) {
        number_of_theories = MAX_THEORIES;
    }

    for (int i = 0; i < number_of_theories; i++) {
        generate_conspiracy_theory();
    }

    return 0;
}