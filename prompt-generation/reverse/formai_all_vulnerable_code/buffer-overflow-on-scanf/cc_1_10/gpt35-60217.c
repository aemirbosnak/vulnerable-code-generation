//FormAI DATASET v1.0 Category: Robot movement control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 15
#define MAX_VALUE 100

enum Direction {
    LEFT, RIGHT, UP, DOWN
};

typedef struct {
    enum Direction facing;
    int x;
    int y;
} Robot;

void go_left(Robot *bot, int value) {
    bot->x -= value;
}

void go_right(Robot *bot, int value) {
    bot->x += value;
}

void go_up(Robot *bot, int value) {
    bot->y += value;
}

void go_down(Robot *bot, int value) {
    bot->y -= value;
}

void move(Robot *bot, char command[], int value) {
    if (isdigit(command[0])) {
        value = atoi(command);
        command[MAX_COMMAND_LENGTH - 1] = '\0';
    }
    if (strcmp(command, "left") == 0) {
        if (bot->facing == LEFT) {
            go_left(bot, value);
        } else if (bot->facing == RIGHT) {
            go_right(bot, value);
        } else if (bot->facing == UP) {
            go_left(bot, value);
            bot->facing = LEFT;
        } else if (bot->facing == DOWN) {
            go_right(bot, value);
            bot->facing = RIGHT;
        }
    } else if (strcmp(command, "right") == 0) {
        if (bot->facing == LEFT) {
            go_right(bot, value);
        } else if (bot->facing == RIGHT) {
            go_left(bot, value);
        } else if (bot->facing == UP) {
            go_right(bot, value);
            bot->facing = RIGHT;
        } else if (bot->facing == DOWN) {
            go_left(bot, value);
            bot->facing = LEFT;
        }
    } else if (strcmp(command, "up") == 0) {
        if (bot->facing == LEFT) {
            go_up(bot, value);
            bot->facing = UP;
        } else if (bot->facing == RIGHT) {
            go_up(bot, value);
            bot->facing = UP;
        } else if (bot->facing == UP) {
            go_up(bot, value);
        } else if (bot->facing == DOWN) {
            go_down(bot, value);
        }
    } else if (strcmp(command, "down") == 0) {
        if (bot->facing == LEFT) {
            go_down(bot, value);
            bot->facing = DOWN;
        } else if (bot->facing == RIGHT) {
            go_down(bot, value);
            bot->facing = DOWN;
        } else if (bot->facing == UP) {
            go_down(bot, value);
        } else if (bot->facing == DOWN) {
            go_up(bot, value);
        }
    } else {
        printf("Invalid command: %s\n", command);
    }
}

int main() {
    Robot bot = { RIGHT, 0, 0 };
    char input[MAX_COMMAND_LENGTH];
    int value;

    printf("Enter commands:\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        scanf("%d", &value);
        move(&bot, input, value);
    }

    printf("Position: (%d,%d)\n", bot.x, bot.y);

    return 0;
}