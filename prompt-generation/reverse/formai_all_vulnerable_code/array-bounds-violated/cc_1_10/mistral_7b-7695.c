//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100

void game_over(char *message);
void print_intro();
void print_options(int *options, int num_options);
int check_input(int *options, int num_options, char *input);
int main() {
    char input[MAX_LINE];
    int options[3] = {0, 1, 2};

    print_intro();

    while (1) {
        print_options(options, 3);
        fgets(input, MAX_LINE, stdin);
        input[strlen(input) - 1] = '\0'; // remove newline character

        if (check_input(options, 3, input) != -1) {
            switch (check_input(options, 3, input)) {
                case 0:
                    printf("You chose option 1: Explore the forest.\n");
                    // forest exploration code here
                    break;
                case 1:
                    printf("You chose option 2: Visit the village.\n");
                    // village visiting code here
                    break;
                case 2:
                    printf("You chose option 3: Rest in the inn.\n");
                    // inn resting code here
                    break;
                default:
                    printf("Invalid input. Please choose a valid option.\n");
            }
        } else {
            printf("Invalid input. Please choose a valid option.\n");
        }
    }

    return 0;
}

void print_intro() {
    printf("Welcome, brave adventurer! You find yourself in a small village at the edge of a vast forest.\n");
    printf("Your quest is to find the legendary Crystal of Life.\n");
    printf("Choose wisely and explore the forest, visit the village, or rest in the inn.\n");
}

void print_options(int *options, int num_options) {
    int i;

    printf("Your options are:\n");

    for (i = 0; i < num_options; i++) {
        printf("%d. %s\n", i + 1, options[i] >= 0 ? "Explore the forest" : "Unknown option");
    }
}

int check_input(int *options, int num_options, char *input) {
    int i;

    for (i = 0; i < num_options; i++) {
        if (strcmp(input, options[i] >= 0 ? "1" : "Unknown input") == 0) {
            return i;
        }
    }

    return -1;
}

void game_over(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}