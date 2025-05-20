//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Virus {
    char name[128];
    char description[512];
    int severity;
    int detection_method;
} Virus;

Virus viruses[10] = {
    {"The Dragon's Breath", "A fiery virus that melts computer systems", 3, 1},
    {"The Shadow's Bite", "A stealthy virus that corrupts data", 2, 2},
    {"The Lich's Kiss", "A deadly virus that spreads through networks", 4, 3},
    {"The Werewolf's Bite", "A vicious virus that attacks system files", 3, 1},
    {"The Vampire's Drain", "A draining virus that consumes system resources", 2, 2},
    {"The Sorcerer's Spell", "A mischievous virus that causes system crashes", 3, 1},
    {"The Alchemist's Brew", "A potent virus that mutates rapidly", 4, 3},
    {"The Goblin's Greave", "A nasty virus that infects user data", 2, 2},
    {"The Troll's Toll", "A disruptive virus that locks users out of their systems", 3, 1},
    {"The Witch's Hex", "A chaotic virus that causes system instability", 4, 3}
};

int main() {
    char buffer[MAX_BUFFER_SIZE];
    int i, j, found = 0;
    printf("Welcome, brave knight, to the battle against the digital plague.\n");
    printf("Please provide a file name: ");
    scanf("%s", buffer);

    for (i = 0; i < 10; i++) {
        for (j = 0; viruses[i].name[j] != '\0'; j++) {
            if (strcmp(buffer, viruses[i].name) == 0) {
                found = 1;
                break;
            }
        }
    }

    if (found) {
        printf("The file, %s, has been infected with the dreaded %s virus.\n", buffer, viruses[i].name);
        printf("Prepare for a fierce battle against the forces of darkness.\n");
    } else {
        printf("The file, %s, is safe from the clutches of the digital plague.\n", buffer);
        printf("May the wind blow in your hair, brave knight.\n");
    }

    return 0;
}