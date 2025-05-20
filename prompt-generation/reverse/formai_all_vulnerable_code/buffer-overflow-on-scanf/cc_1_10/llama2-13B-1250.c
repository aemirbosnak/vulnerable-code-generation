//LLAMA2-13B DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SORRY_NOT_SORRY 1

// Declare our hero, a chicken named Cluck Norris
typedef struct {
    int age;
    int strength;
    int bravery;
} chicken_t;

chicken_t my_chicken = {3, 10, 100};  // 3 years old, 10 strength, 100 bravery (because Cluck Norris is a badass)

// Function to make Cluck Norris say something funny
void say_something(const char* message) {
    printf("Cluck Norris says: %s\n", message);
}

// Function to make Cluck Norris do something brave
void do_something_brave() {
    say_something("BOK BOK! *flex*");
}

// Function to make Cluck Norris attack an enemy
void attack_enemy(int enemy_age, int enemy_strength) {
    if (enemy_age < my_chicken.age && enemy_strength < my_chicken.strength) {
        say_something("HSSSS! You're too weak to be my enemy, BAAAH!");
    } else {
        say_something("BOK BOK! *peck*");
    }
}

int main() {
    // Ask Cluck Norris what he wants to do today
    printf("What do you want to do today, Cluck Norris?\n");
    char choice;
    scanf("%c", &choice);

    // If the user chooses to say something funny...
    if (choice == '1') {
        say_something("I'm not a chicken, I'm a rocket-powered, laser-shooting, egg-laying wonder bird!");
    }

    // If the user chooses to do something brave...
    else if (choice == '2') {
        do_something_brave();
    }

    // If the user chooses to attack an enemy...
    else if (choice == '3') {
        int enemy_age, enemy_strength;
        printf("Who do you want to attack, Cluck Norris?\n");
        scanf("%d%d", &enemy_age, &enemy_strength);
        attack_enemy(enemy_age, enemy_strength);
    }

    // If the user enters anything else...
    else {
        say_something("HSSSS! That's not a valid choice, BAAAH!");
    }

    return SORRY_NOT_SORRY;
}