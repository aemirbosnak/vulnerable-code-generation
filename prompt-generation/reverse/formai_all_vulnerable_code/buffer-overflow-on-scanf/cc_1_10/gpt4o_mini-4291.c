//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_TREASURES 100
#define TREASURE_NAME_LENGTH 50

// Declare a structure for a treasure
typedef struct {
    char name[TREASURE_NAME_LENGTH];
} Treasure;

// The noble function that conducts the search for the treasure
int search_for_treasure(Treasure treasures[], int count, const char* sought_treasure) {
    for (int i = 0; i < count; i++) {
        if (strcmp(treasures[i].name, sought_treasure) == 0) {
            return i; // Return the index if the treasure is found
        }
    }
    return -1; // Treasure not found
}

// The grand adventure begins!
int main() {
    printf("Hark! Welcome to the Grand Treasure Hunt!\n");

    Treasure treasures[MAX_TREASURES];
    int treasure_count = 0;

    // The wise merchant bestows treasures upon the knights
    strcpy(treasures[treasure_count++].name, "Golden Chalice");
    strcpy(treasures[treasure_count++].name, "Elven Bow");
    strcpy(treasures[treasure_count++].name, "Dragon's Heart");
    strcpy(treasures[treasure_count++].name, "Titan's Shield");
    strcpy(treasures[treasure_count++].name, "Mystic Amulet");
    strcpy(treasures[treasure_count++].name, "Cursed Sword");
    strcpy(treasures[treasure_count++].name, "Phoenix Feather");
    strcpy(treasures[treasure_count++].name, "Mermaid's Tear");
    
    // Declare the valiant knight's quest
    char sought_treasure[TREASURE_NAME_LENGTH];
    printf("Brave Knight, what treasure dost thou seek? ");
    scanf("%s", sought_treasure);

    // The knight embarks on the search
    printf("Searching for the treasured '%s'...\n", sought_treasure);
    int found_index = search_for_treasure(treasures, treasure_count, sought_treasure);

    // Report the fate of the quest
    if (found_index != -1) {
        printf("Huzzah! Thou hast found the '%s' at index %d!\n", treasures[found_index].name, found_index);
    } else {
        printf("Alas! The treasure '%s' is not among the stash of riches! Seek elsewhere, brave Knight!\n", sought_treasure);
    }
    
    // Display all treasures for good measure
    printf("\nHerein lies the full treasury of the kingdom:\n");
    for (int i = 0; i < treasure_count; i++) {
        printf(" - %s\n", treasures[i].name);
    }
    
    // Conclude the adventure
    printf("\nMay fortune guide your next quest, noble Knight!\n");
    return 0;
}