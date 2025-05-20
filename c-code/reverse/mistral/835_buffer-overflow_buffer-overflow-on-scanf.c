#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_COMPONENT_LENGTH 20

typedef struct Component {
    char type[MAX_COMPONENT_LENGTH];
    int value;
} Component;

void get_name(char* name, int max_length) {
    char input[max_length];
    fgets(input, max_length, stdin);
    strtok(input, "\n");
    strcpy(name, strtok(NULL, "\n"));
}

void get_component(Component* component) {
    fgets(component->type, MAX_COMPONENT_LENGTH, stdin);
    component->type[strcspn(component->type, "\n")] = '\0';
    scanf("%d", &component->value);
}

int main() {
    int num_players, i;
    char player_names[10][MAX_NAME_LENGTH];
    Component designs[10];

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; ++i) {
        printf("Enter player %d's name: ", i + 1);
        get_name(player_names[i], MAX_NAME_LENGTH);
    }

    for (i = 0; i < num_players; ++i) {
        printf("Player %s, enter your circuit design:\n", player_names[i]);
        get_component(&designs[i]);
    }

    // Game logic here

    return 0;
}
