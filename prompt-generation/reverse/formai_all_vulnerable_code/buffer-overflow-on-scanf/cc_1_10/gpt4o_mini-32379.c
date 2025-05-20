//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 100
#define MAX_LENGTH 256

const char *subjects[] = {
    "aliens", "the government", "big corporations", "the moon landing", 
    "global warming", "vaccines", "celebrities", "the media", 
    "the flat earth", "time travel", "artificial intelligence", 
    "lizard people", "secret societies", "numerology", "cryptids"
};

const char *actions[] = {
    "are controlling", "have infiltrated", "are hiding", 
    "are using", "manipulate", "have created", 
    "are monitoring", "are funding", "suppress", 
    "are testing", "are working with", "have enslaved"
};

const char *objects[] = {
    "our thoughts", "technology", "humanity", "natural disasters", 
    "the economy", "weather patterns", "education", 
    "the internet", "population growth", "communication", 
    "research", "energy sources"
};

const char *locations[] = {
    "Area 51", "the Bermuda Triangle", "the North Pole", 
    "the deep ocean", "outer space", "Hollywood", 
    "the Vatican", "the White House", "Silicon Valley", 
    "the underground bunkers", "the Amazon rainforest", "the secret tunnels"
};

void generate_conspiracy_theory(char *theory) {
    int subj_index = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int action_index = rand() % (sizeof(actions) / sizeof(actions[0]));
    int obj_index = rand() % (sizeof(objects) / sizeof(objects[0]));
    int loc_index = rand() % (sizeof(locations) / sizeof(locations[0]));

    snprintf(theory, MAX_LENGTH, "It is believed that %s %s %s in %s.", 
             subjects[subj_index], actions[action_index], 
             objects[obj_index], locations[loc_index]);
}

void generate_multiple_theories(int n) {
    char theory[MAX_LENGTH];
    for (int i = 0; i < n; i++) {
        generate_conspiracy_theory(theory);
        printf("Conspiracy Theory %d: %s\n", i + 1, theory);
    }
}

void print_welcome_message() {
    printf("==========================================\n");
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("==========================================\n");
    printf("Prepare to delve into the unknown...\n\n");
}

void print_goodbye_message() {
    printf("\n==========================================\n");
    printf("Thank you for using the Conspiracy Theory Generator!\n");
    printf("Stay inquisitive, but beware of the truth!\n");
    printf("==========================================\n");
}

int main() {
    srand(time(NULL));
    int number_of_theories;

    print_welcome_message();

    printf("Enter the number of conspiracy theories to generate: ");
    scanf("%d", &number_of_theories);

    if (number_of_theories < 1 || number_of_theories > MAX_THEORIES) {
        printf("Please enter a number between 1 and %d.\n", MAX_THEORIES);
        return 1;
    }

    generate_multiple_theories(number_of_theories);
    print_goodbye_message();

    return 0;
}