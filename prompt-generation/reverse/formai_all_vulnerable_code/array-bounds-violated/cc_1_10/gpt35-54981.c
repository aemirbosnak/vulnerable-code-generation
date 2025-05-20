//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_LINES 5
#define MAX_CHARS 100

char *fortunes[MAX_FORTUNES][MAX_LINES] = {
    {
        "Good things come\n",
        "to those who wait.\n",
        "And those who work\n",
        "while they wait.\n",
        NULL
    },
    {
        "Your future looks\n",
        "very bright indeed.\n",
        "But remember to plan\n",
        "for the unexpected.\n",
        NULL
    },
    {
        "A long journey\n",
        "awaits you.\n",
        "But fear not,\n",
        "for the destination\n",
        "is worth the voyage.\n",
        NULL
    },
    {
        "The answers you seek\n",
        "are closer than\n",
        "you think.\n",
        "Just open your eyes,\n",
        "heart, and mind.\n",
        NULL
    },
    {
        "Opportunity knocks\n",
        "only once,\n",
        "so seize it\n",
        "with both hands\n",
        "when it comes.\n",
        NULL
    },
    {
        "Your wealth will grow\n",
        "in proportion to\n",
        "your generosity.\n",
        "So give freely\n",
        "and watch it multiply.\n",
        NULL
    },
    {
        "You will face many challenges\n",
        "in the days to come.\n",
        "But do not despair,\n",
        "for you are stronger\n",
        "than you know.\n",
        NULL
    },
    {
        "The key to happiness\n",
        "is not in personal gain,\n",
        "but in the relationships\n",
        "you build with others.\n",
        NULL
    },
    {
        "Every ending is\n",
        "a new beginning.\n",
        "So embrace the change,\n",
        "for great things\n",
        "are in store for you.\n",
        NULL
    },
    {
        "Your talents and skills\n",
        "will take you far.\n",
        "But never forget\n",
        "the importance of\n",
        "hard work and humility.\n",
        NULL
    }
};

int main() {
    srand((unsigned int) time(NULL)); //seed random number generator
    
    printf("Please enter your name: ");
    char name[MAX_CHARS];
    fgets(name, MAX_CHARS, stdin);
    name[strlen(name)-1] = '\0'; //remove newline character
    
    printf("\nHello, %s. Welcome to the automated fortune teller!\n\n", name);
    
    printf("Press ENTER to receive your fortune...");
    getchar(); //wait for user input (ENTER key)
    printf("\n");
    
    printf("Your fortune for today is:\n\n");
    
    int fortune_idx = rand() % MAX_FORTUNES; //choose a random fortune
    int line_idx = 0;
    while (fortunes[fortune_idx][line_idx] != NULL) {
        printf("%s", fortunes[fortune_idx][line_idx]);
        line_idx++;
    }
    
    return 0;
}