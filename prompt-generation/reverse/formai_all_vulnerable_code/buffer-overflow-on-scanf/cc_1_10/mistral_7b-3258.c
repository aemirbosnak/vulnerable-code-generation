//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define NUM_LOCATIONS 4

typedef struct {
    char name[MAX_LENGTH];
    char description[MAX_LENGTH];
    char exits[4][MAX_LENGTH];
    int has_golden_apple;
} location;

location locations[NUM_LOCATIONS] = {
    {"The Village",
     "You are in the village. There is a forest to the north, a blacksmith to the east, and an oracle to the south.",
     {"north", "east", "south"},
     0},

    {"The Forest",
     "You are in the forest. There are wild animals and many trees. Go back to the village to the south.",
     {"south"},
     0},

    {"The Blacksmith",
     "You are in the blacksmith's shop. He can repair your equipment and sell you weapons.",
     {"village"},
     0},

    {"The Oracle",
     "You are at the oracle's temple. Ask her for advice and she may give you a clue to find the golden apple.",
     {"village"},
     0}
};

void look(location *location) {
    printf("%s\n", location->description);
}

void go(location *current, char *direction) {
    int i;
    for (i = 0; i < NUM_LOCATIONS; i++) {
        if (strcmp(locations[i].name, current->exits[0][strlen(current->exits[0])]) == 0) {
            current = &locations[i];
            break;
        }
    }
    look(current);
}

int main() {
    location *current = &locations[0];
    char command[MAX_LENGTH];

    while (1) {
        printf("%s> ", current->name);
        scanf("%s", command);

        if (strcmp(command, "look") == 0) {
            look(current);
        } else if (strcmp(command, "go") == 0) {
            char direction[MAX_LENGTH];
            scanf("%s", direction);
            go(current, direction);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}