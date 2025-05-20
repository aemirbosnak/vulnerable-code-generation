//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a quest location
typedef struct QuestLocation {
    char name[50];
    int x; // x-coordinate in the realm
    int y; // y-coordinate in the realm
    char description[256];
} QuestLocation;

// Function to calculate the distance between two locations
double calculateDistance(QuestLocation a, QuestLocation b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Function to display available quests
void displayQuests(QuestLocation quests[], int count) {
    printf("Available Quests:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Coordinates: [%d, %d]) - %s\n", i + 1, quests[i].name, quests[i].x, quests[i].y, quests[i].description);
    }
}

// Function for navigation simulation
void navigate(QuestLocation quests[], int count) {
    QuestLocation currentLocation = { "Castle", 0, 0, "The grand castle of the King." };
    int choice;

    printf("Hark, brave adventurer! Thou art now in %s.\n", currentLocation.name);
    printf("Thou canst embark on one of the following quests:\n");

    displayQuests(quests, count);

    printf("Choose thy quest by entering the corresponding number: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("A most grievous selection! The quest number chosen is unworthy.\n");
        return;
    }

    QuestLocation selectedQuest = quests[choice - 1];

    printf("Thou hast chosen the quest: %s! (Coordinates: [%d, %d])\n",
           selectedQuest.name, selectedQuest.x, selectedQuest.y);

    double distance = calculateDistance(currentLocation, selectedQuest);
    printf("It is a journey of %.2f leagues from the castle to the quest!\n", distance);
    printf("Now, set forth, valiant hero, to fulfill thy destiny!\n");
}

int main() {
    // Define some quest locations
    QuestLocation quests[] = {
        {"Dragon's Cave", 10, 5, "A perilous cave inhabited by a ferocious dragon."},
        {"Witch's Lair", 3, 4, "A dark forest where a witch brews ominous potions."},
        {"Ancient Ruins", -2, 8, "Crumbled stones that whisper tales of old."},
        {"Enchanted Grove", 6, -3, "A mystical grove filled with enthralling wonders."}
    };

    int questCount = sizeof(quests) / sizeof(quests[0]);

    navigate(quests, questCount);

    return 0;
}