//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 256
#define FILENAME "clue.txt"

// A mysterious case file structure
typedef struct {
    char name[MAX_CHARACTERS];
    char description[MAX_CHARACTERS];
    int cluesGathered;
} CaseFile;

// Function declarations
void investigateCase(CaseFile *casefile);
void loadCaseFile(CaseFile *casefile);
void handleFileError(FILE *file);
void reportClue(const char *clue);

int main() {
    CaseFile currentCase;
    memset(&currentCase, 0, sizeof(currentCase));

    printf("Detective Sherlock Holmes at your service!\n");
    printf("Analyzing the case file...\n");

    loadCaseFile(&currentCase);
    investigateCase(&currentCase);

    return 0;
}

void loadCaseFile(CaseFile *casefile) {
    FILE *file = fopen(FILENAME, "r");
    handleFileError(file);
    
    fscanf(file, "%[^,],%[^,],%d", casefile->name, casefile->description, &casefile->cluesGathered);
    printf("Case Loaded: %s - %s\n", casefile->name, casefile->description);
    fclose(file);
}

void handleFileError(FILE *file) {
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
}

void reportClue(const char *clue) {
    if (clue == NULL || strlen(clue) == 0) {
        fprintf(stderr, "Failure: Cue for reporting is empty!\n");
        return;
    }
    printf("Clue reported: %s\n", clue);
}

void investigateCase(CaseFile *casefile) {
    if (casefile->cluesGathered <= 0) {
        fprintf(stderr, "No clues gathered for the case \"%s\". Time to search elsewhere!\n", casefile->name);
        return;
    }
    
    printf("Commencing the investigation...\n");
    
    for (int i = 1; i <= casefile->cluesGathered; i++) {
        char clue[MAX_CHARACTERS];
        snprintf(clue, sizeof(clue), "Clue #%d: Evidence found at the scene.", i);
        reportClue(clue);
    }
    
    printf("Investigation complete. All clues analyzed for case \"%s\".\n", casefile->name);
}