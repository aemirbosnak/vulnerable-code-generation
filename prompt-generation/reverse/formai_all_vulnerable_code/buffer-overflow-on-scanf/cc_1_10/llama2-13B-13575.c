//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define MAX_WIDTH 20

// Structure to hold the knight's information
typedef struct {
    char name[MAX_LENGTH];
    int strength;
} knight_t;

// Function to print a knight's information
void print_knight(knight_t knight) {
    printf("Hail, noble %s! Thy strength doth %d. \n", knight.name, knight.strength);
}

// Function to generate a random knight
knight_t generate_knight() {
    char name[MAX_LENGTH];
    int strength;

    // Generate a random name
    srand(time(NULL));
    for (int i = 0; i < MAX_LENGTH; i++) {
        name[i] = 'A' + (rand() % 26);
    }

    // Generate a random strength
    strength = rand() % 10 + 1;

    return (knight_t) { .name = name, .strength = strength };
}

int main() {
    // Declare a knight
    knight_t knight = generate_knight();

    // Print the knight's information
    print_knight(knight);

    // Ask the user to guess the knight's strength
    printf("Guess the knight's strength: ");
    int guess;
    scanf("%d", &guess);

    // Check if the user guessed correctly
    if (guess == knight.strength) {
        printf("Thou hast guessed correctly, brave adventurer! \n");
    } else {
        printf("Alas, thy guess was incorrect. The knight's strength was %d. \n", knight.strength);
    }

    return 0;
}