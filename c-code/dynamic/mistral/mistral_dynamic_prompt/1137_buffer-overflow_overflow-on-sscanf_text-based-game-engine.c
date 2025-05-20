#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void game_input(char *buf, int size) {
    char input[100];
    printf("Enter your move (max %d characters): ", size);
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", buf);
}

void display_game_state(const char *state) {
    printf("\n%s\n", state);
}

int main() {
    char buf[10];
    char state[1024];
    int i;

    printf("Welcome to VulnGame v1.0!\n\n");
    strcpy(state, "It's a simple game. Type 'quit' to end.\n");
    display_game_state(state);

    while (1) {
        game_input(buf, 9);

        if (strcmp(buf, "quit") == 0) {
            break;
        }

        if (strlen(buf) > 9) {
            strcpy(state, "Warning! Input overflow detected.\n");
            display_game_state(state);
        } else {
            strcpy(state, "Your move: ");
            strcat(state, buf);
            strcat(state, "\n");
            display_game_state(state);
        }
    }

    return 0;
}
