//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SKILLS 10

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills[MAX_SKILLS];
    int num_skills;
} Survivor;

int main() {
    // Initialize the resume database
    Survivor survivors[] = {
        {
            .name = "Rick Grimes",
            .email = "rick.grimes@apocalypse.com",
            .phone = "555-123-4567",
            .skills = {"Leadership", "Combat", "Survival"},
            .num_skills = 3
        },
        {
            .name = "Daryl Dixon",
            .email = "daryl.dixon@apocalypse.com",
            .phone = "555-234-5678",
            .skills = {"Hunting", "Tracking", "Archery"},
            .num_skills = 3
        },
        {
            .name = "Michonne Hawthorne",
            .email = "michonne.hawthorne@apocalypse.com",
            .phone = "555-345-6789",
            .skills = {"Swordsmanship", "Survival", "First Aid"},
            .num_skills = 3
        }
    };

    // Get the user's search query
    char *query;
    printf("Enter your search query: ");
    scanf("%s", query);

    // Search the database for matching survivors
    int num_matches = 0;
    for (int i = 0; i < sizeof(survivors) / sizeof(survivors[0]); i++) {
        Survivor survivor = survivors[i];
        if (strstr(survivor.name, query) || strstr(survivor.email, query) || strstr(survivor.phone, query)) {
            printf("Found a match: %s\n", survivor.name);
            num_matches++;
        }
        for (int j = 0; j < survivor.num_skills; j++) {
            if (strstr(survivor.skills[j], query)) {
                printf("Found a match: %s\n", survivor.name);
                num_matches++;
            }
        }
    }

    // Print the number of matches
    printf("Found %d matches.\n", num_matches);

    return 0;
}