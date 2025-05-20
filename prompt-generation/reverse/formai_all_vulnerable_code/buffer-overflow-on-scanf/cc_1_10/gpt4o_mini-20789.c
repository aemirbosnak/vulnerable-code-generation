//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 100
#define MAX_LENGTH 256

char *theories[MAX_THEORIES];
char *elements[] = {
    "aliens", "government", "big corporations", "secret societies", 
    "global warming", "the moon landing", "climate change", "5G technology", 
    "pharmaceutical companies", "time travelers", "Freemasons", 
    "artificial intelligence", "digital currency", "secret technology", 
    "Hollywood", "the illuminati", "royal families", "ancient civilizations", 
    "universal consciousness", "vaccine conspiracies", "ancient astronauts"
};

char *events[] = {
    "control the world's minds", "hide the truth", "influence global policies", 
    "take over the world economy", "manipulate the stock market", 
    "alter historical events", "create fake news", "develop mind control technologies", 
    "disrupt the fabric of reality", "extract resources from the moon",
    "experiment on humans", "create a new world order",
    "invent diseases for profit", "unleash chaos in the society",
    "redirect global powers", "rewrite human history", "suppress new technologies",
    "establish a one-world government", "use technology to surveil the masses"
};

char *locations[] = {
    "Area 51", "the Bermuda Triangle", "the Vatican", "the Illuminati headquarters", 
    "Los Alamos", "the Arctic base", "the Denver Airport", 
    "the Temple of the Ancients", "Wall Street", "Silicon Valley",
    "the Great Wall of China", "Mount Shasta", "the mysterious forest in Romania",
    "the Pyramids of Giza", "the Sphinx", "the Bermuda Triangle",
    "the Moon", "Antarctica", "the ancient city of Atlantis",
    "the occult underground tunnel systems"
};

void generate_conspiracy_theory(char *output) {
    int element_index = rand() % (sizeof(elements) / sizeof(elements[0]));
    int event_index = rand() % (sizeof(events) / sizeof(events[0]));
    int location_index = rand() % (sizeof(locations) / sizeof(locations[0]));

    snprintf(output, MAX_LENGTH, "The %s are trying to %s at %s!", elements[element_index],
             events[event_index], locations[location_index]);
}

void generate_multiple_theories(int count) {
    for (int i = 0; i < count; i++) {
        theories[i] = malloc(MAX_LENGTH);
        if (theories[i] == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        generate_conspiracy_theory(theories[i]);
    }
}

void print_theories(int count) {
    for (int i = 0; i < count; i++) {
        printf("Conspiracy Theory %d: %s\n", i + 1, theories[i]);
    }
}

void free_memory(int count) {
    for (int i = 0; i < count; i++) {
        free(theories[i]);
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    int count;

    printf("Enter the number of conspiracy theories to generate (max %d): ", MAX_THEORIES);
    scanf("%d", &count);
    
    if (count < 1 || count > MAX_THEORIES) {
        fprintf(stderr, "Invalid number of theories.\n");
        return EXIT_FAILURE;
    }

    generate_multiple_theories(count);
    print_theories(count);
    free_memory(count);
    
    return EXIT_SUCCESS;
}