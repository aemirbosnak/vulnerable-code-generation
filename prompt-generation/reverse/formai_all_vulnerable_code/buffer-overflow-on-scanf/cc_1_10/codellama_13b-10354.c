//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: medieval
// A medieval C Metadata Extractor example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to store the metadata for a medieval knight
typedef struct {
    char name[32];
    char weapon[32];
    char armor[32];
    char horse[32];
    char shield[32];
} Knight;

// A function to extract the metadata from a medieval knight
void extract_metadata(Knight *knight) {
    // Extract the name
    char name[32];
    scanf("%s", name);
    strcpy(knight->name, name);

    // Extract the weapon
    char weapon[32];
    scanf("%s", weapon);
    strcpy(knight->weapon, weapon);

    // Extract the armor
    char armor[32];
    scanf("%s", armor);
    strcpy(knight->armor, armor);

    // Extract the horse
    char horse[32];
    scanf("%s", horse);
    strcpy(knight->horse, horse);

    // Extract the shield
    char shield[32];
    scanf("%s", shield);
    strcpy(knight->shield, shield);
}

int main() {
    // Create a Knight structure
    Knight knight;

    // Extract the metadata from the knight
    extract_metadata(&knight);

    // Print the metadata
    printf("Name: %s\n", knight.name);
    printf("Weapon: %s\n", knight.weapon);
    printf("Armor: %s\n", knight.armor);
    printf("Horse: %s\n", knight.horse);
    printf("Shield: %s\n", knight.shield);

    return 0;
}