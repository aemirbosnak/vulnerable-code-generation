//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define max_length 1000
#define max_choices 10

char *choices[max_choices];
int num_choices = 0;

void add_choice(char *option) {
    if (num_choices < max_choices) {
        choices[num_choices] = option;
        num_choices++;
    } else {
        printf("Error: Too many choices!\n");
    }
}

int main() {
    char input[max_length];
    char *story = "You are a space explorer on a mission to discover new planets. Your ship is equipped with the latest technology and weapons to defend against any threats you may encounter. As you navigate through the galaxy, you receive a distress signal from an unknown planet. You decide to investigate.\n";
    int choice;
    int i;

    srand(time(NULL));
    add_choice("Continue");
    add_choice("Quit");

    printf("Welcome to the Space Adventure!\n\n");

    while (1) {
        printf("%s", story);

        scanf("%s", input);
        for (i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        choice = rand() % num_choices;
        printf("\nYour choices are:\n");
        for (i = 0; i < num_choices; i++) {
            printf("%d. %s\n", i + 1, choices[i]);
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            printf("You continue your journey towards the unknown planet...\n");
        } else {
            printf("You decide to turn back and abandon the mission.\n");
        }

        strcat(story, "\n");
    }

    return 0;
}