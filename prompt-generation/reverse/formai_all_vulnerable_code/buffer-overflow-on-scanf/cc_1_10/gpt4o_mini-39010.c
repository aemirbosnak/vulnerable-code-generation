//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 256
#define MAX_THEORIES 10

typedef struct {
    char *prefix;
    char *subject;
    char *explanation;
    char *conclusion;
} ConspiracyTheory;

void initialize_theories(ConspiracyTheory theories[]) {
    theories[0] = (ConspiracyTheory){"The moon landing", "was staged by NASA to", "distract us from the Watergate scandal", "and cover up their secret time-travel project."};
    theories[1] = (ConspiracyTheory){"Birds", "are actually drones created by", "the government to monitor us", "and we are all just rats in their experiment."};
    theories[2] = (ConspiracyTheory){"The pyramids", "were built by aliens to", "create a Wi-Fi network for their spaceships", "and were designed in collaboration with ancient Egyptians."};
    theories[3] = (ConspiracyTheory){"Reptilian shapeshifters", "control world leaders to", "manipulate global events", "and pave the way for their takeover of Earth."};
    theories[4] = (ConspiracyTheory){"Avocados", "are a mind-control device created by", "the avocado industry", "to keep us buying overpriced toast."};
    theories[5] = (ConspiracyTheory){"Time travel", "is real and has been proven by", "top scientists leading a secret society", "who wish to keep it hidden from the public."};
    theories[6] = (ConspiracyTheory){"The Bermuda Triangle", "is actually a portal to", "another dimension", "used by aliens to abduct ships and planes."};
    theories[7] = (ConspiracyTheory){"Vaccines", "are actually designed to", "control the human population", "and prevent evolutions of our species."};
    theories[8] = (ConspiracyTheory){"The internet", "was created by", "illuminati members", "to harvest our data for their covert operations."};
    theories[9] = (ConspiracyTheory){"Pineapple pizza", "is an ancient recipe", "designed by cults to promote", "an underground society aiming for global domination."};
}

const char* get_random_theory(ConspiracyTheory theories[], int theory_count) {
    int index = rand() % theory_count;
    size_t buffer_size = MAX_LENGTH;
    
    char *result = (char *)malloc(buffer_size);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    snprintf(result, buffer_size, "%s %s %s %s", 
             theories[index].prefix, 
             theories[index].subject, 
             theories[index].explanation, 
             theories[index].conclusion);
    
    return result;
}

void free_theory_string(const char *theory_string) {
    free((void *)theory_string);
}

int main() {
    srand(time(NULL));  // Initialize random seed
    ConspiracyTheory theories[MAX_THEORIES];
    initialize_theories(theories);
    
    printf("Welcome to the Conspiracy Theory Generator! Press Enter to generate a new theory...\n");
    
    while (1) {
        getchar();  // Wait for user to press Enter
        const char *theory = get_random_theory(theories, MAX_THEORIES);
        printf("Generated Conspiracy Theory: %s\n", theory);
        free_theory_string(theory);
        
        char choice;
        printf("Would you like to generate another theory? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    
    printf("Thank you for using the Conspiracy Theory Generator!\n");
    return 0;
}