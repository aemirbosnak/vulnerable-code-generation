//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHOICE 5

typedef struct {
    char name[50];
    char description[200];
} Planet;

typedef struct {
    char name[50];
    char lover[50];
    int fate; // 1: love, 0: tragedy
} Character;

void display_planet(Planet planet) {
    printf("Welcome to %s!\n", planet.name);
    printf("%s\n\n", planet.description);
}

void make_choice(Character *character, Planet *planet) {
    int choice;
    printf("Do you dare to court the beauty of the cosmos, brave %s? Choose wisely:\n", character->name);
    printf("1. Proclaim your love boldly.\n");
    printf("2. Whisper sweet nothings in the starlight.\n");
    printf("3. Seek the blessing of the planetary spirits.\n");
    printf("4. Defy fate and challenge the stars.\n");
    printf("5. Retreat to your vessel in fear.\n");
    
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(character->lover, "Celestia");
            character->fate = 1; // love
            printf("With a voice full of ardor, you cry: 'Celestia, my heart belongs to thee!'\n");
            break;
        case 2:
            strcpy(character->lover, "Luna");
            character->fate = 0; // tragedy
            printf("You utter soft words, but the winds carry them away, lost among the stars.\n");
            break;
        case 3:
            strcpy(character->lover, "Stellara");
            character->fate = 1; // love
            printf("With reverence, you call upon the spirits. Stellara smiles upon you.\n");
            break;
        case 4:
            strcpy(character->lover, "Fate");
            character->fate = 0; // tragedy
            printf("You challenge Fate, but the stars align against you.\n");
            break;
        case 5:
            strcpy(character->lover, "");
            character->fate = 0; // tragedy
            printf("Overcome by fear, you retreat to your vessel, leaving the cosmos in sadness.\n");
            break;
        default:
            printf("An ominous silence falls upon you. Make your choice, star traveler!\n");
            break;
    }
}

void conclude(Character character) {
    if (character.fate == 1) {
        printf("In a twist of fate, love blossoms among the stars as %s and %s unite!\n\n", character.name, character.lover);
        printf("Together, they sail the cosmic currents, weaving their tale across the universe.\n");
    } else {
        printf("Alas! The stars have conspired against you, dear %s. The cosmos weeps as love is lost.\n\n", character.name);
        printf("In a tragic turn, shadows loom over the galaxies, forever reminding you of your lost love.\n");
    }
}

int main() {
    Character character;
    Planet planets[] = {
        {"Zyphos", "A planet of swirling mists and ethereal beauty, known for its enchanting moons."},
        {"Vesperia", "A world of twinkling lights, where every shadow hides a romantic tale."},
        {"Elysium", "The realm of eternal bliss, but beware the whims of fate that linger here."}
    };

    printf("Enter your name, brave traveler: ");
    scanf("%s", character.name);
    character.lover[0] = '\0'; // Initialize with no lover
    character.fate = 0; // Initialize fate

    for (int i = 0; i < 3; i++) {
        display_planet(planets[i]);
        make_choice(&character, &planets[i]);
        printf("\n");
    }

    conclude(character);

    return 0;
}