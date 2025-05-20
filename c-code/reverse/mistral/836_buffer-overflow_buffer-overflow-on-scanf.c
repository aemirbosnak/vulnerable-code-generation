#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Circuit {
    char playerName[20];
    int components;
} Circuit;

void addComponent(Circuit *circuit, char componentName[20]) {
    strcpy(circuit->playerName, componentName);
    circuit->components++;
}

int main() {
    Circuit myCircuit;
    char input[100];

    printf("Enter player name: ");
    scanf("%s", input);
    addComponent(&myCircuit, input);

    return 0;
}
