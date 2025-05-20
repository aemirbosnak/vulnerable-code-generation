//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

// Surreal constants
#define FLOWER_COUNT 21
#define CACTUS_DAYS 5
#define SPHERE_MOON 7
#define TIME_LEAP 11

const char *MONTHS[] = {
    "Dandelion",
    "Quasar",
    "Mirage",
    "Echo",
    "Zephyr",
    "Labyrinth",
    "Nimbus",
    "Elysium",
    "Chimera",
    "Abyss",
    "Solstice",
    "Fable"
};

const char *DAYS[] = {
    "Shadow-Dance",
    "Whirlwind",
    "Eclipse",
    "Misty-Peak",
    "Twilight-Whisper",
    "Dawn-Mirror",
    "Star-Sprout",
    "Dream-Stream",
    "Voyager",
    "Enigma",
    "Spectrum",
    "Frost-Bloom",
    "Echoing-Path",
    "Lunar-Glow",
    "Riddle-Kiss",
    "Flickering-Light",
    "Golden-Myst",
    "Arcane-Song",
    "Celestial-Thread",
    "Phantom-Breeze",
    "Woven-Tide"
};

struct Date {
    int dream_day;
    int flower_month;
    int year;
};

// Function prototypes
struct Date surreal_to_date(const char *input);
void print_narrative(const struct Date date);
void random_adventure();

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter a surreal date in the format 'Dream-Day Dandelion':\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    if (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0'; // Remove newline character
    }

    struct Date date = surreal_to_date(input);
    print_narrative(date);
    random_adventure();

    return 0;
}

struct Date surreal_to_date(const char *input) {
    struct Date date;
    char day[MAX_INPUT_SIZE];
    char month[MAX_INPUT_SIZE];

    sscanf(input, "%s %s", day, month);
    
    // Map dream day to a number
    for (int i = 0; i < FLOWER_COUNT; i++) {
        if (strcmp(month, MONTHS[i]) == 0) {
            date.flower_month = i + 1; // Months are 1-indexed
            date.year = 2023; // Set a surreal constant year
            break;
        }
    }

    // Assign a surreal day to the entered dream day
    date.dream_day = ((rand() % CACTUS_DAYS) + 1) * (strlen(day) % SPHERE_MOON + 1);
    
    return date;
}

void print_narrative(const struct Date date) {
    printf("In the cosmic realm of observational dreams, the date is:\n");
    printf("%s of the %s, Year of the Enchanted Whirl \( %d \) \n", 
           DAYS[date.dream_day % 20], 
           MONTHS[date.flower_month - 1], 
           date.year);
}

void random_adventure() {
    int adventure = rand() % 3;
    switch (adventure) {
        case 0:
            printf("You find yourself in a Garden of Forgotten Thoughts, conversing with whispers of the past.\n");
            break;
        case 1:
            printf("A grand clock knocks on time's door, revealing secrets unspoken, lost in the labyrinth.\n");
            break;
        case 2:
            printf("A spirit guides you through the Aurora, painting your life with hues of laughter and shadows.\n");
            break;
    }
}