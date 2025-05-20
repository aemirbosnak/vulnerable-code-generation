//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 10
#define MAX_CONSPIRACIES 100

char conspiracies[MAX_CONSPIRACIES][MAX_CONSPIRACY_LENGTH];
int numConspiracies;

void generateConspiracy() {
    char conspiracy[MAX_CONSPIRACY_LENGTH];
    int i;
    char *words[] = {"illuminati", "chemtrails", "9/11", "moon landing", "flat earth", "lizard people", "area 51", "haarp", "mk ultra", "roswell"};

    srand(time(NULL));
    for (i = 0; i < MAX_CONSPIRACY_WORDS; i++) {
        strcat(conspiracy, words[rand() % 10]);
        strcat(conspiracy, " ");
    }

    strcat(conspiracy, "is a hoax perpetrated by the government to control our minds.");

    if (numConspiracies >= MAX_CONSPIRACIES) {
        printf("Max number of conspiracies reached. Exiting...\n");
        exit(0);
    }

    strcpy(conspiracies[numConspiracies], conspiracy);
    numConspiracies++;
}

int main() {
    int choice;
    char input[MAX_CONSPIRACY_LENGTH];

    srand(time(NULL));
    numConspiracies = 0;

    while (1) {
        printf("Enter a phrase or type 'generate' to create a new conspiracy theory: ");
        scanf("%s", input);

        if (strcmp(input, "generate") == 0) {
            generateConspiracy();
        } else {
            printf("Conspiracy #%d: %s\n", numConspiracies - 1, input);
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    return 0;
}