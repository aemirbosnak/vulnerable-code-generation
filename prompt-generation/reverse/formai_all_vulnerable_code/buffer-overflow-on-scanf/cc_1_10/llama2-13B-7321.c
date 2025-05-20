//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct for a "Mathemagician"
struct Mathemagician {
    int magical_powers;  // number of math operations we can perform
    double wand_power;   // strength of our wand (i.e., the number of math operations we can do at once)
    char spellbook[10];  // array of spells we know (e.g., "add", "subtract", "multiply", etc.)
};

// Function to initialize a Mathemagician's stats
void init_mathemagician(struct Mathemagician *mage) {
    mage->magical_powers = 5;
    mage->wand_power = 10.0;
    for (int i = 0; i < 10; i++) {
        mage->spellbook[i] = ' ';  // starting with a blank spellbook 😅
    }
}

// Function to cast a spell (e.g., add, subtract, multiply)
void cast_spell(struct Mathemagician *mage, char spell) {
    // Check if the spell is valid (i.e., not blank)
    if (spell != ' ') {
        // If the spell is valid, perform the math operation
        switch (spell) {
            case '+':  // add
                mage->wand_power += mage->magical_powers;
                break;
            case '-':  // subtract
                mage->wand_power -= mage->magical_powers;
                break;
            case '*':  // multiply
                mage->wand_power *= mage->magical_powers;
                break;
            default:  // invalid spell, do nothing
                break;
        }
        // Update the spellbook with the used spell
        mage->spellbook[0] = spell;
    }
}

// Function to display the Mathemagician's stats
void show_stats(struct Mathemagician *mage) {
    printf("Magical Powers: %d\n", mage->magical_powers);
    printf("Wand Power: %.2f\n", mage->wand_power);
    for (int i = 0; i < 10; i++) {
        printf("Spellbook[%c]\n", mage->spellbook[i]);
    }
}

int main() {
    struct Mathemagician mage;  // create a Mathemagician object
    init_mathemagician(&mage);  // initialize the Mathemagician's stats

    // Loop until the user decides to stop
    while (1) {
        // Print the Mathemagician's stats
        show_stats(&mage);

        // Get the user's input (e.g., "add", "subtract", "multiply", etc.)
        char spell;
        printf("Enter a spell (e.g., 'add', 'subtract', 'multiply'): ");
        scanf("%c", &spell);

        // Cast the spell
        cast_spell(&mage, spell);
    }

    return 0;  // we'll never reach this 😄
}