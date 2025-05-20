//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CYBERPUNK_CHARS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int level;
    float hackingSkill;
} CyberpunkCharacter;

void printCharacters(CyberpunkCharacter characters[], int count);
int compareCharacters(const void *a, const void *b);
void generateRandomCharacter(CyberpunkCharacter *character);

int main() {
    printf("Accessing the Neon Array... Initializing...\n");

    int n;
    printf("Enter the number of Cyberpunk characters to generate (Max: %d): ", NUM_CYBERPUNK_CHARS);
    scanf("%d", &n);
    
    if (n > NUM_CYBERPUNK_CHARS) {
        printf("Exceeding maximum character limit. Resetting to %d...\n", NUM_CYBERPUNK_CHARS);
        n = NUM_CYBERPUNK_CHARS;
    }
  
    CyberpunkCharacter characters[NUM_CYBERPUNK_CHARS];
  
    for (int i = 0; i < n; ++i) {
        generateRandomCharacter(&characters[i]);
    }
    
    printf("\nHere are your raw Cyberpunk characters:\n");
    printCharacters(characters, n);

    qsort(characters, n, sizeof(CyberpunkCharacter), compareCharacters);
    
    printf("\nCharacters sorted by Hacking Skill:\n");
    printCharacters(characters, n);

    printf("Exiting the Neon Grid...\n");
    return 0;
}

void printCharacters(CyberpunkCharacter characters[], int count) {
    for (int i = 0; i < count; ++i) {
        printf("Character %d: %s, Level: %d, Hacking Skill: %.2f\n", i + 1, characters[i].name, characters[i].level, characters[i].hackingSkill);
    }
}

int compareCharacters(const void *a, const void *b) {
    CyberpunkCharacter *charA = (CyberpunkCharacter *)a;
    CyberpunkCharacter *charB = (CyberpunkCharacter *)b;
    if (charA->hackingSkill < charB->hackingSkill) {
        return -1;
    } else if (charA->hackingSkill > charB->hackingSkill) {
        return 1;
    }
    return 0;
}

void generateRandomCharacter(CyberpunkCharacter *character) {
    const char *names[] = {
        "Spectre", "Vortex", "Neon", "Cyborg", "Echo", 
        "Phantom", "Cipher", "Shade", "Blitz", "Rebel"
    };
    
    int nameIndex = rand() % 10;

    strcpy(character->name, names[nameIndex]);
    character->level = rand() % 100 + 1; // Levels from 1 to 100
    character->hackingSkill = (float)(rand() % 10000) / 100; // Hacking skills from 0.00 to 99.99
}