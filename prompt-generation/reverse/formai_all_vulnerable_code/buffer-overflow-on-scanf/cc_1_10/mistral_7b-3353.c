//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Alien Language Struct
typedef struct {
    char symbol;
    char *english;
} AlienSymbol;

// Create Alien Language Table
AlienSymbol alienLanguageTable[] = {
    {'!', "Greetings, Earthling!"},
    {'@', "What is it you desire?"},
    {'#', "I understand, human."},
    {'$', "Your turn to speak now."},
    {'%', "Yes, that is correct."},
    {'&', "No, try again later."},
    {'*', "Why do humans ask such strange questions?"},
    {'(', "Let us discuss this further."},
    {')', "I see your point, interesting."},
    {'-', "Fascinating, tell me more."},
    {'+', "Why do you find that so amusing?"},
    {'=', "Let us share a meal together."},
    {'> ', "Your turn to cook."},
    {'< ', "I will prepare the meal."},
    {'|', "Let us take a break and relax."},
    {'\\', "Let us explore this new world."},
    {'/', "Your turn to lead the way."},
    {'^', "I will follow closely behind."},
    {'~', "Our adventure continues tomorrow."}
};

// Function to Translate Alien Language
void translateAlienLanguage(char input[]) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        for (int j = 0; j < 26; j++) {
            if (input[i] == alienLanguageTable[j].symbol) {
                printf("%s", alienLanguageTable[j].english);
                return;
            }
        }
    }
    printf("Unknown symbol: %c", input[i]);
}

int main() {
    char input[100];
    printf("Welcome, Earthling! I am your new Alien friend. Type a message in Alien and I will translate it for you:\n");
    scanf("%s", input);
    translateAlienLanguage(input);
    return 0;
}