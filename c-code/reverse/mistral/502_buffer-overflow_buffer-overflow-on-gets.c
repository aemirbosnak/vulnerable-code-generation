#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CODE_LENGTH 10
#define NUM_ALIEN_TYPES 3

int main() {
    char name[MAX_NAME_LENGTH];
    char code[MAX_CODE_LENGTH];
    int alienType, strength;
    int invasionProbability;

    printf("Enter your name: ");
    gets(name);

    printf("Enter secret code: ");
    gets(code);

    printf("Enter alien type (1: Grays, 2: Reptilians, 3: Zorgons): ");
    scanf("%d", &alienType);

    printf("Enter alien strength (1-10): ");
    scanf("%d", &strength);

    if (strength > 5 && strcmp(code, "ABCDEFGHIJ") == 0) {
        invasionProbability = 1;
    } else if (alienType == 1 && strength > 7) {
        invasionProbability = 3;
    } else if (alienType == 2 && strength > 5) {
        invasionProbability = 5;
    } else if (alienType == 3 && strength > 3) {
        invasionProbability = 7;
    } else {
        invasionProbability = 9;
    }

    printf("Invasion probability: %d%%\n", invasionProbability);

    return 0;
}
