//GEMINI-pro DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A true detective must be able to read the clues from a file.
FILE *SceneOfCrime;

// The case file holds all the important details.
typedef struct {
    char *name;
    int age;
    char *address;
} Suspect;

// The list of suspects is a labyrinth of possibilities.
Suspect suspects[100];

// The time is of the essence in solving the crime.
time_t time_of_crime;

// The weather conditions can sometimes be a crucial clue.
char *weather_conditions;

// The main function is the first step in unraveling the mystery.
int main(int argc, char **argv) {
    // Opening the case file is paramount.
    SceneOfCrime = fopen("casefile.txt", "r");
    if (SceneOfCrime == NULL) {
        // If the case file cannot be opened, the investigation is doomed.
        printf("My dear Watson, it seems the case file has been misplaced. Our investigation is at a standstill.\n");
        return 1;
    }

    // Reading the time of the crime is essential.
    fscanf(SceneOfCrime, "%ld", &time_of_crime);

    // Reading the weather conditions can be enlightening.
    weather_conditions = malloc(100);
    fscanf(SceneOfCrime, "%s", weather_conditions);

    // Identifying the suspects is the cornerstone of any investigation.
    int num_suspects;
    fscanf(SceneOfCrime, "%d", &num_suspects);
    for (int i = 0; i < num_suspects; i++) {
        suspects[i].name = malloc(100);
        fscanf(SceneOfCrime, "%s", suspects[i].name);
        fscanf(SceneOfCrime, "%d", &suspects[i].age);
        suspects[i].address = malloc(100);
        fscanf(SceneOfCrime, "%s", suspects[i].address);
    }

    // The investigation is starting to take shape.
    printf("My dear Watson, we have uncovered some intriguing details.\n");
    printf("The time of the crime was %s.\n", ctime(&time_of_crime));
    printf("The weather conditions were %s.\n", weather_conditions);
    printf("The list of suspects includes:\n");
    for (int i = 0; i < num_suspects; i++) {
        printf("%s, aged %d, residing at %s\n", suspects[i].name, suspects[i].age, suspects[i].address);
    }

    // Closing the case file ensures the integrity of the evidence.
    fclose(SceneOfCrime);

    // The pursuit of justice has begun.
    printf("Elementary, my dear Watson. Let us embark on this thrilling journey to uncover the truth.\n");

    return 0;
}