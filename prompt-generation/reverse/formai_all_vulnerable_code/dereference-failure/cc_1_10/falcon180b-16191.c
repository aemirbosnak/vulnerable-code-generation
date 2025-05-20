//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet style performance-critical component example program

// Define a struct to represent a character in the play
typedef struct {
    char *name;
    int age;
    char *house;
} Character;

// Function to print a character's information
void print_character(Character *character) {
    printf("Name: %s\n", character->name);
    printf("Age: %d\n", character->age);
    printf("House: %s\n", character->house);
}

// Function to create a new character with default values
Character *new_character() {
    Character *character = malloc(sizeof(Character));
    character->name = "Unknown";
    character->age = 0;
    character->house = "None";
    return character;
}

// Function to set a character's name
void set_character_name(Character *character, char *name) {
    character->name = name;
}

// Function to set a character's age
void set_character_age(Character *character, int age) {
    character->age = age;
}

// Function to set a character's house
void set_character_house(Character *character, char *house) {
    character->house = house;
}

// Function to free a character's memory
void free_character(Character *character) {
    free(character);
}

// Main function to demonstrate the usage of the performance-critical component
int main() {
    // Create two characters
    Character *romeo = new_character();
    Character *juliet = new_character();

    // Set their names, ages, and houses
    set_character_name(romeo, "Romeo");
    set_character_age(romeo, 18);
    set_character_house(romeo, "Montague");

    set_character_name(juliet, "Juliet");
    set_character_age(juliet, 16);
    set_character_house(juliet, "Capulet");

    // Print their information
    print_character(romeo);
    print_character(juliet);

    // Free their memory
    free_character(romeo);
    free_character(juliet);

    return 0;
}