//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_LENGTH 150

const char *subjects[] = {
    "aliens", "governments", "celebrities", 
    "big corporations", "ancient civilizations", 
    "technology", "the moon", "weather", 
    "secret societies", "media"
};

const char *actions[] = {
    "are controlling", "want to hide", "are testing", 
    "have infiltrated", "are using", "are collaborating with",
    "are manipulating", "have created", "will reveal",
    "are plotting against"
};

const char *objects[] = {
    "the human race", "the stock market", "our minds", 
    "the environment", "the internet", "time itself",
    "history", "the truth", "our emotions", "our children"
};

const char *methods[] = {
    "via technology", "through media manipulation", 
    "by rewriting history", "using mind control", 
    "with psychological experiments", "through economic disruption",
    "by altering climate data", "with false flag operations",
    "using distraction tactics", "through genetic engineering"
};

char *generate_conspiracy_theory() {
    static char theory[MAX_LENGTH];
    int sub = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int act = rand() % (sizeof(actions) / sizeof(actions[0]));
    int obj = rand() % (sizeof(objects) / sizeof(objects[0]));
    int meth = rand() % (sizeof(methods) / sizeof(methods[0]));
    
    snprintf(theory, sizeof(theory), "It is believed that %s %s %s %s.",
             subjects[sub], actions[act], objects[obj], methods[meth]);
    
    return theory;
}

void generate_theories(int count) {
    printf("\nGenerated Conspiracy Theories:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, generate_conspiracy_theory());
    }
}

void print_intro() {
    printf("-------------------------------------------------\n");
    printf("     Welcome to the Conspiracy Theory Generator    \n");
    printf("-------------------------------------------------\n");
    printf("Feel free to generate some mind-boggling theories!\n");
    printf("-------------------------------------------------\n");
}

int main() {
    srand(time(0)); // Seed the random number generator
    print_intro();
    
    int count;
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &count);

    if (count < 1 || count > MAX_THEORIES) {
        printf("Please enter a number between 1 and %d.\n", MAX_THEORIES);
        return 1;
    }

    generate_theories(count);
    printf("-------------------------------------------------\n");
    printf("      Thank you for using the generator!        \n");
    printf("-------------------------------------------------\n");
    
    return 0;
}