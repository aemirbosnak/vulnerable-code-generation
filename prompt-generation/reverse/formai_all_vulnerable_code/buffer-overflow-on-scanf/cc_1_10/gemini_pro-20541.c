//GEMINI-pro DATASET v1.0 Category: Educational ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some brave macros
#define BRAVE_NEW_WORLD 1
#define IGNORANCE_IS_STRENGTH 2
#define WAR_IS_PEACE 3
#define FREEDOM_IS_SLAVERY 4

// Declare some brave functions
void doublethink(char *s);
void newspeak(char *s);
void unperson(char *s);

int main() {
    // Initialize the brave world
    int world = BRAVE_NEW_WORLD;

    // Declare some brave variables
    char name[256];
    char party[256];
    char slogan[256];

    // Get the brave input
    printf("What is your name? ");
    scanf("%s", name);
    printf("What is your party? ");
    scanf("%s", party);
    printf("What is your slogan? ");
    scanf("%s", slogan);

    // Doublethink the brave input
    doublethink(name);
    doublethink(party);
    doublethink(slogan);

    // Newspeak the brave input
    newspeak(name);
    newspeak(party);
    newspeak(slogan);

    // Unperson the brave input
    unperson(name);
    unperson(party);
    unperson(slogan);

    // Print the brave output
    printf("Your name is %s.\n", name);
    printf("Your party is %s.\n", party);
    printf("Your slogan is %s.\n", slogan);

    // Exit the brave world
    return 0;
}

// Doublethink the brave input
void doublethink(char *s) {
    int i;

    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'i') {
            s[i] = 'u';
        } else if (s[i] == 'u') {
            s[i] = 'i';
        }
    }
}

// Newspeak the brave input
void newspeak(char *s) {
    int i;

    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'a') {
            s[i] = 'e';
        } else if (s[i] == 'e') {
            s[i] = 'i';
        } else if (s[i] == 'i') {
            s[i] = 'o';
        } else if (s[i] == 'o') {
            s[i] = 'u';
        } else if (s[i] == 'u') {
            s[i] = 'a';
        }
    }
}

// Unperson the brave input
void unperson(char *s) {
    int i;

    for (i = 0; i < strlen(s); i++) {
        s[i] = '\0';
    }
}