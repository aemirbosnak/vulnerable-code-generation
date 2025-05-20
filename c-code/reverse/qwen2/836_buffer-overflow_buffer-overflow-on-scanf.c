#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 256

typedef struct {
    char playerName[MAX_NAME_LENGTH];
} Circuit;

int main() {
    Circuit myCircuit;
    printf("Enter your player name: ");
    scanf("%s", myCircuit.playerName);
    return 0;
}
