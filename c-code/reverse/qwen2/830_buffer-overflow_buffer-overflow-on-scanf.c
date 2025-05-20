#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_COMPONENTS 10

typedef struct {
    char name[50];
    double value;
} Component;

int main() {
    Component components[MAX_COMPONENTS];
    int num_components = 0;
    int player_turn = 0;

    while (num_components < MAX_COMPONENTS) {
        printf("Player %d's turn. Enter component type (R/C/V): ", player_turn + 1);
        char type;
        scanf(" %c", &type);

        if (type == 'R') {
            printf("Enter resistor name: ");
            scanf("%s", components[num_components].name);
            printf("Enter resistor value: ");
            scanf("%lf", &components[num_components].value);
        } else if (type == 'C') {
            printf("Enter capacitor name: ");
            scanf("%s", components[num_components].name);
            printf("Enter capacitor value: ");
            scanf("%lf", &components[num_components].value);
        } else if (type == 'V') {
            printf("Enter voltage source name: ");
            scanf("%s", components[num_components].name);
            printf("Enter voltage source value: ");
            scanf("%lf", &components[num_components].value);
        }

        num_components++;
        player_turn = (player_turn + 1) % 2;
    }

    printf("\nSimulation complete.\n");

    return 0;
}
