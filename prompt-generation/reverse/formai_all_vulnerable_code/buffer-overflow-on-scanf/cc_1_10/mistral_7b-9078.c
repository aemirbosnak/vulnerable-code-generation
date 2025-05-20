//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATE 5
#define MAX_INPUT_LEN 30

typedef struct {
    char name[30];
    int next_state;
} state_t;

state_t states[MAX_STATE] = {
    {"You are in the forest. There is a tree in front of you. Paths lead left and right.", 0},
    {"You are near a river. A bridge leads to the other side. You see a glittering object in the distance.", 2},
    {"You are in a cave. There is a chest in the corner. The way back is blocked by a fallen rock.", 3},
    {"You have found the treasure! Congratulations!", 4},
    {"Game over. You have quit.", 4}
};

int current_state = 0;
char input[MAX_INPUT_LEN];

void print_state() {
    printf("%s", states[current_state].name);
}

void process_input() {
    char* token;
    char* command;

    token = strtok(input, " ");
    command = strtok(NULL, " ");

    switch (command[0]) {
        case 'l':
            current_state = states[current_state].next_state - 1;
            break;
        case 'r':
            current_state = states[current_state].next_state + 1;
            break;
        case 't':
            if (strcmp(token, "chest") == 0) {
                printf("You have taken the treasure.\n");
                current_state = 4;
            } else {
                printf("There is no %s here.\n", token);
            }
            break;
        case 'g':
            if (strcmp(token, "bridge") == 0) {
                current_state = 2;
            } else {
                printf("There is no %s here.\n", token);
            }
            break;
        case 'q':
            current_state = 4;
            break;
        default:
            printf("Invalid command. Use 'l' for left, 'r' for right, 't' for take, 'g' for go, and 'q' for quit.\n");
    }
}

int main() {
    int quit = 0;

    while (quit == 0) {
        print_state();
        printf("> ");
        scanf("%s", input);
        process_input();
    }

    return 0;
}