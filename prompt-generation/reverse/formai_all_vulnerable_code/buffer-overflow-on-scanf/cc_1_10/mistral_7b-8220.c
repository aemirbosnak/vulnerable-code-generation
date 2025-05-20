//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

char *descriptions[] = {
    "You find yourself in a dimly lit chamber, the air heavy with the scent of decay.",
    "The ground beneath your feet is cold and damp. A faint glowing emanates from the east.",
    "The walls are adorned with strange symbols, glowing in the darkness. You feel a chill run down your spine.",
    "You hear a faint dripping sound, echoing off the walls. Something moves in the darkness.",
    "Suddenly, a figure emerges from the shadows. It's an ancient guardian, his eyes burning with a fierce intensity.",
    "The guardian speaks, his voice echoing off the walls. 'You have disturbed my rest, mortal. Prepare to face my wrath!'"
};

char *choices[] = {
    "Examine the glowing emanation.",
    "Inspect the strange symbols on the walls.",
    "Follow the sound of dripping water.",
    "Confront the ancient guardian."
};

int main() {
    int choice, description_index = 0;
    char input[MAX_LEN];

    printf("Welcome, adventurer, to the crypt of the ancient guardian. %s\n", descriptions[description_index]);

    while (1) {
        printf("What do you want to do? %s\n", choices[description_index % 5]);
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            description_index++;
            if (description_index > 5) description_index = 0;
            printf("%s\n", descriptions[description_index]);
        } else if (strcmp(input, "2") == 0) {
            description_index++;
            if (description_index > 5) description_index = 0;
            printf("%s\n", descriptions[description_index]);
        } else if (strcmp(input, "3") == 0) {
            description_index++;
            if (description_index > 5) description_index = 0;
            printf("%s\n", descriptions[description_index]);
        } else if (strcmp(input, "4") == 0) {
            printf("You face the ancient guardian, his eyes burning with a fierce intensity. 'You have disturbed my rest, mortal. Prepare to face my wrath!'\n");
            // Add the guardian battle sequence here
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}