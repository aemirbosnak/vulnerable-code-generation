//Falcon-180B DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of knights that can be managed
#define MAX_KNIGHTS 100

// Structure to store information about each knight
typedef struct {
    char name[50];
    int age;
    int victories;
} Knight;

// Function prototypes
void createKnight(Knight* knight);
void displayKnight(Knight knight);
void joust(Knight* knight1, Knight* knight2);

int main() {
    Knight* knights = (Knight*)malloc(MAX_KNIGHTS * sizeof(Knight));
    int numKnights = 0;

    // Create new knights
    createKnight(&knights[numKnights]);
    numKnights++;
    createKnight(&knights[numKnights]);
    numKnights++;

    // Display information about each knight
    printf("The Knights of the Realm:\n");
    for (int i = 0; i < numKnights; i++) {
        displayKnight(knights[i]);
    }

    // Host a jousting tournament
    joust(&knights[0], &knights[1]);

    // Display updated information about each knight
    printf("\nAfter the Joust:\n");
    for (int i = 0; i < numKnights; i++) {
        displayKnight(knights[i]);
    }

    free(knights);
    return 0;
}

// Create a new knight with default values
void createKnight(Knight* knight) {
    strcpy(knight->name, "Sir Unknown");
    knight->age = 25;
    knight->victories = 0;
}

// Display information about a knight
void displayKnight(Knight knight) {
    printf("Name: %s\n", knight.name);
    printf("Age: %d\n", knight.age);
    printf("Victories: %d\n\n", knight.victories);
}

// Host a jousting tournament between two knights
void joust(Knight* knight1, Knight* knight2) {
    printf("\n%s challenges %s to a joust!\n", knight1->name, knight2->name);
    int result = rand() % 2; // Simulate the result of the joust (0 = knight1 wins, 1 = knight2 wins)

    if (result == 0) {
        knight1->victories++;
        printf("%s has won the joust!\n", knight1->name);
    } else {
        knight2->victories++;
        printf("%s has won the joust!\n", knight2->name);
    }
}