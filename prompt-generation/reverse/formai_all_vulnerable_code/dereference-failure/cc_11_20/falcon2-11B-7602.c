//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* read_line() {
    char* input = (char*) malloc(256);
    int length = 0;

    while (1) {
        printf("> ");
        fgets(input, 256, stdin);
        if (strlen(input) == 0) {
            return NULL;
        }
        input[strcspn(input, "\n")] = 0;
        length = strlen(input);
        if (length == 0) {
            continue;
        }
        break;
    }

    return input;
}

void print_line(char* line) {
    printf("%s", line);
}

int main() {
    char* input;
    char* input2;
    char* command;

    while (1) {
        input = read_line();
        if (input == NULL) {
            printf("Game over.\n");
            break;
        }

        command = strtok(input, " ");
        if (strcmp(command, "north") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "south") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "east") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "west") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "inventory") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "drop") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "take") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "use") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "attack") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "eat") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "open") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "close") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "say") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "pickup") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "jump") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "run") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "climb") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "go") == 0) {
            input2 = read_line();
            if (strcmp(input2, "exit") == 0) {
                printf("You have exited the game.\n");
                break;
            }
        } else if (strcmp(command, "help") == 0) {
            printf("You can move in any direction or you can interact with objects by typing the name of the object.\n");
            printf("Available commands: \n");
            printf("north, south, east, west, inventory, drop, take, use, attack, eat, open, close, say, pickup, jump, run, climb, go, help.\n");
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}