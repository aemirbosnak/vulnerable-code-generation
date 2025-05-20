//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_LENGTH 512

typedef struct {
    char name[MAX_LENGTH];
    char skills[MAX_LENGTH];
    int experience; // years of experience
} Candidate;

typedef struct {
    Candidate candidates[MAX_CANDIDATES];
    int count;
} CandidateDatabase;

// Function prototypes
void parseResume(const char *filepath, Candidate *candidate);
void addCandidate(CandidateDatabase *db, Candidate *candidate);
void displayCandidates(const CandidateDatabase *db);
void queryCandidates(const CandidateDatabase *db, const char *skill);

int main() {
    CandidateDatabase db = { .count = 0 };
    char *files[] = {
        "cyberwarrior.txt",
        "netrunner.txt",
        "techsmith.txt"
    };

    for (int i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
        Candidate candidate;
        parseResume(files[i], &candidate);
        addCandidate(&db, &candidate);
    }
    
    printf("Cyberpunk Candidate Database:\n");
    displayCandidates(&db);
    
    char querySkill[MAX_LENGTH];
    printf("\nEnter a skill to query candidates (e.g. hacking, programming): ");
    fgets(querySkill, sizeof(querySkill), stdin);
    querySkill[strcspn(querySkill, "\n")] = 0; // Remove newline
    queryCandidates(&db, querySkill);

    return 0;
}

void parseResume(const char *filepath, Candidate *candidate) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filepath);
        return;
    }

    // Simple parsing logic
    fgets(candidate->name, MAX_LENGTH, file);
    fgets(candidate->skills, MAX_LENGTH, file);
    fscanf(file, "%d", &candidate->experience);
    
    // Remove newline characters
    candidate->name[strcspn(candidate->name, "\n")] = 0;
    candidate->skills[strcspn(candidate->skills, "\n")] = 0;

    fclose(file);
}

void addCandidate(CandidateDatabase *db, Candidate *candidate) {
    if (db->count < MAX_CANDIDATES) {
        db->candidates[db->count++] = *candidate;
    } else {
        fprintf(stderr, "Database is full! Cannot add more candidates.\n");
    }
}

void displayCandidates(const CandidateDatabase *db) {
    for (int i = 0; i < db->count; i++) {
        printf("Candidate %d:\n", i + 1);
        printf("Name: %s\n", db->candidates[i].name);
        printf("Skills: %s\n", db->candidates[i].skills);
        printf("Experience: %d years\n\n", db->candidates[i].experience);
    }
}

void queryCandidates(const CandidateDatabase *db, const char *skill) {
    printf("Searching for candidates with skill: %s\n", skill);
    int found = 0;
    
    for (int i = 0; i < db->count; i++) {
        if (strstr(db->candidates[i].skills, skill) != NULL) {
            printf("Found Candidate: %s with %d years of experience\n", db->candidates[i].name, db->candidates[i].experience);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No candidates found with skill: %s\n", skill);
    }
}