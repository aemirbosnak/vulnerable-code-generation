//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_THEORIES 6
#define MAX_THEORY_LEN 100

char* theories[] = {
    "The government is hiding the cure for cancer to control population growth.",
    "Technology companies are spying on us through our smart devices.",
    "Moon landing was a hoax and it was all filmed in a Hollywood studio.",
    "Aliens have already made contact with Earth, but it's being kept a secret.",
    "The Illuminati is controlling world events behind the scenes.",
    "The Earth is flat and the government is lying to us about its shape."
};

int main() {
    srand(time(NULL));
    char response;
    do {
        // generate a random conspiracy theory
        int rand_index = rand() % NUM_OF_THEORIES;
        char theory[MAX_THEORY_LEN];
        strcpy(theory, theories[rand_index]);
        
        // replace certain keywords with random phrases
        char* possible_phrases[] = {
            "according to my sources",
            "from what I've heard",
            "it is rumored that",
            "the truth is out there",
            "don't believe everything you hear, but",
            "some people say that",
            "take it with a grain of salt, but",
            "trust me on this one",
            "I know it sounds crazy, but"
        };
        int num_of_phrases = sizeof(possible_phrases) / sizeof(possible_phrases[0]);
        char* keyword = "government";
        char* phrase = possible_phrases[rand() % num_of_phrases];
        char* pos = strstr(theory, keyword);
        if (pos != NULL) {
            int len1 = pos - theory; // length of the string before keyword occurs
            int len2 = strlen(keyword); // length of the keyword
            int len3 = strlen(pos + len2); // length of the string after keyword occurs
            char new_theory[MAX_THEORY_LEN];
            strncpy(new_theory, theory, len1);
            new_theory[len1] = '\0';
            strcat(new_theory, phrase);
            strcat(new_theory, " the ");
            strcat(new_theory, keyword);
            strcat(new_theory, pos + len2);
            strcpy(theory, new_theory);
        }
        
        // print the theory
        printf("%s\n", theory);
        
        // ask if the user wants to hear another theory
        printf("Do you want to hear another conspiracy theory? (y/n) ");
        scanf(" %c", &response);
        printf("\n");
    } while (response == 'y' || response == 'Y');
    return 0;
}