#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 100
#define MAX_DATE_LENGTH 11
#define NUM_ALIEN_TYPES 3
#define MIN_CC 1
#define MAX_CC 10

int calculateProbability(char*, char*, int, int, int);

int main() {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    int alienType, alienStrength, secretCode;

    printf("Enter your name: ");
    gets(name);

    printf("Enter date (YYYY-MM-DD): ");
    gets(date);

    printf("Select alien type (1-3): ");
    scanf("%d", &alienType);

    printf("Enter alien strength (1-10): ");
    scanf("%d", &alienStrength);

    printf("Enter secret code (1-9999): ");
    scanf("%d", &secretCode);

    int probability = calculateProbability(name, date, alienType, alienStrength, secretCode);
    printf("Alien invasion probability: %d%%\n", probability);

    return 0;
}

int calculateProbability(char* name, char* date, int alienType, int alienStrength, int secretCode) {
    int probability = (alienType + alienStrength + secretCode) % 100;
    return probability;
}
