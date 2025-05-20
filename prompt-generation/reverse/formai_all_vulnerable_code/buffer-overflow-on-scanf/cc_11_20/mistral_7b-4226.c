//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100
#define MAX_OPTIONS 5

typedef struct Option {
    char description[MAX_LINE];
    char command;
} Option;

Option options[MAX_OPTIONS] = {
    {"You see a beautiful sunflower field. What do you want to do?", 'F'},
    {"You come across a group of happy children playing. What do you do?", 'P'},
    {"You find a nice bench under a tree. Do you want to sit down and rest?", 'R'},
    {"You hear a beautiful melody. Do you want to follow the sound?", 'M'},
    {"You come across a crossroads. Do you go left, right or straight ahead?", 'L', 'R', 'S'}
};

int main() {
    char input[MAX_LINE];
    int i, j;

    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("\n%s\n", options[i].description);
        scanf("%s", input);

        if (strlen(input) > 0) {
            if (input[0] == options[i].command || (i > 0 && options[i - 1].command == input[0])) {
                printf("\nYou chose option %d. Let's see what happens...\n", i + 1);
                if (i == 3) {
                    for (j = 0; j < MAX_OPTIONS; j++) {
                        if (options[j].command == 'M') {
                            printf("\nYou followed the beautiful melody and found a group of musicians playing. They invite you to join in and you feel truly happy.\n");
                            return 0;
                        }
                    }
                    printf("\nYou couldn't find the source of the melody. Maybe next time.\n");
                } else {
                    for (j = 0; j < MAX_OPTIONS; j++) {
                        if (options[j].command == input[0] && j != i) {
                            printf("\nYou chose the wrong option. Let's try again.\n");
                            i--;
                            break;
                        }
                    }
                    printf("\nYou made a good choice. Let's see what happens next.\n");

                    // Here you can add the logic for each option
                    // For example, if option i is the happiness end, add the following code:
                    if (i == 4) {
                        printf("\nCongratulations! You have found happiness!\n");
                        return 0;
                    }
                }
            } else {
                printf("\nInvalid command. Let's try again.\n");
            }
        }
    }

    printf("\nYou gave up on finding happiness. Better luck next time!\n");
    return 0;
}