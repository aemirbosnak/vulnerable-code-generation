//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACIES 10
#define MAX_LENGTH 256

typedef struct {
    char *name;
    char *theme;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];

// Function to initialize the conspiracy theories database
void initialize_conspiracies() {
    conspiracies[0] = (Conspiracy){"The Moon Landing Hoax", "space exploration"};
    conspiracies[1] = (Conspiracy){"Flat Earth Theory", "geography"};
    conspiracies[2] = (Conspiracy){"The Reptilian Elite", "politics"};
    conspiracies[3] = (Conspiracy){"Chemtrails", "environment"};
    conspiracies[4] = (Conspiracy){"The 5G Mind Control", "technology"};
    conspiracies[5] = (Conspiracy){"COVID-19 as a Bioweapon", "health"};
    conspiracies[6] = (Conspiracy){"Bigfoot Coverup", "cryptozoology"};
    conspiracies[7] = (Conspiracy){"The Denver Airport Conspiracy", "architecture"};
    conspiracies[8] = (Conspiracy){"Time Travel Hush-Hush", "science"};
    conspiracies[9] = (Conspiracy){"The Simulation Theory", "philosophy"};
}

// Function to generate a random conspiracy theory
void generate_conspiracy_theory() {
    srand(time(0));
    int index = rand() % MAX_CONSPIRACIES;
    char *locations[] = {
        "Area 51", "the Bermuda Triangle", "the Vatican", 
        "Walt Disney World", "the Bilderberg Conference"
    };
    char *mysterious_items[] = {
        "the secret agenda", "ancient manuscripts", "lost civilizations",
        "a coded message", "fluoridated water"
    };

    int loc_index = rand() % (sizeof(locations) / sizeof(locations[0]));
    int item_index = rand() % (sizeof(mysterious_items) / sizeof(mysterious_items[0]));

    printf("Conspiracy Theory: %s\n", conspiracies[index].name);
    printf("Theme: %s\n", conspiracies[index].theme);
    printf("Details: This theory suggests that %s holds %s that reveals the truth.\n", 
           locations[loc_index], mysterious_items[item_index]);
}

// Function to display all conspiracy theories
void display_all_conspiracy_theories() {
    printf("=== List of Conspiracy Theories ===\n");
    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        printf("%d. %s - Theme: %s\n", i + 1, conspiracies[i].name, conspiracies[i].theme);
    }
}

int main() {
    initialize_conspiracies();
    int choice;

    do {
        printf("\n--- Conspiracy Theory Generator ---\n");
        printf("1. Generate a random conspiracy theory\n");
        printf("2. Display all conspiracy theories\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_conspiracy_theory();
                break;
            case 2:
                display_all_conspiracy_theories();
                break;
            case 3:
                printf("Exiting the program. Stay skeptical!\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 and 3.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}