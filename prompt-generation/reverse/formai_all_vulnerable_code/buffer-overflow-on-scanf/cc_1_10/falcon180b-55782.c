//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    char *token;
    int choice;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a dark forest. What would you like to do?\n");
    printf("1. Walk forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Look around\n");
    scanf("%s", input);

    token = strtok(input, " ");
    choice = atoi(token);

    switch(choice) {
        case 1:
            printf("You walk forward and find a treasure chest.\n");
            printf("Do you want to open it? (y/n)\n");
            scanf("%s", input);
            token = strtok(input, " ");
            if(strcmp(token, "y") == 0) {
                printf("You open the chest and find a golden key.\n");
            } else {
                printf("You leave the chest untouched.\n");
            }
            break;
        case 2:
            printf("You turn left and find a river.\n");
            printf("Do you want to cross it? (y/n)\n");
            scanf("%s", input);
            token = strtok(input, " ");
            if(strcmp(token, "y") == 0) {
                printf("You cross the river and find a magical flower.\n");
            } else {
                printf("You decide not to cross the river.\n");
            }
            break;
        case 3:
            printf("You turn right and find a cave.\n");
            printf("Do you want to enter it? (y/n)\n");
            scanf("%s", input);
            token = strtok(input, " ");
            if(strcmp(token, "y") == 0) {
                printf("You enter the cave and find a map.\n");
            } else {
                printf("You decide not to enter the cave.\n");
            }
            break;
        case 4:
            printf("You look around and see a beautiful sunset.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}