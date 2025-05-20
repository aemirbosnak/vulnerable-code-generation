//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Alien Language Struct
typedef struct AlienLanguage {
    char *name;
    char *symbol;
    char *translation;
} AlienLanguage;

// Create Alien Language Table
AlienLanguage zorgon[] = {
    {"Zorgonian", "Z", "Hello, Earthling!"},
    {"Blorgonian", "B", "Take me to your leader!"},
    {"Xaxxonian", "X", "What is your planet's greatest threat?"},
    {NULL, NULL, NULL}
};

// Translate Alien Language
void translateAlienLanguage(char alienLanguage[]) {
    int i = 0;
    while (zorgon[i].name != NULL) {
        if (strcmp(zorgon[i].symbol, alienLanguage) == 0) {
            printf("%s\n", zorgon[i].translation);
            return;
        }
        i++;
    }
    printf("Unknown Alien Language!\n");
}

int main() {
    char alienLanguage[10];

    printf("Welcome, Human! I'm your C Alien Language Translator. Type the Alien Language Symbol and I'll translate it for you!\n");

    while (1) {
        printf("\nEnter Alien Language Symbol: ");
        scanf("%s", alienLanguage);

        translateAlienLanguage(alienLanguage);

        system("clear"); // Unix/Linux
        // system("cls"); // Windows
    }

    return 0;
}