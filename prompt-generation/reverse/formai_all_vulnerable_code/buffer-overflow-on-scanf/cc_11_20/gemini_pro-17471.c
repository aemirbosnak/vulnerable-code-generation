//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 100

typedef struct {
    char *name;
    int age;
    char *gender;
    char *interests;
} person_t;

int main() {
    // Initialize our database of romantic prospects
    person_t prospects[] = {
        {"Alice", 21, "Female", "Books, movies, music"},
        {"Bob", 25, "Male", "Sports, cars, hiking"},
        {"Carol", 23, "Female", "Cooking, dancing, travel"},
        {"Dave", 27, "Male", "Video games, technology, food"},
        {"Eve", 22, "Female", "Art, photography, fashion"},
    };
    int num_prospects = sizeof(prospects) / sizeof(person_t);

    // Get the user's preferences
    person_t user;
    printf("What is your name?\n");
    scanf("%s", user.name);
    printf("How old are you?\n");
    scanf("%d", &user.age);
    printf("What is your gender?\n");
    scanf("%s", user.gender);
    printf("What are your interests?\n");
    scanf("%s", user.interests);

    // Calculate the compatibility score for each prospect
    double compatibility_scores[num_prospects];
    for (int i = 0; i < num_prospects; i++) {
        compatibility_scores[i] = 0;

        // Age difference
        int age_diff = abs(user.age - prospects[i].age);
        if (age_diff <= 5) {
            compatibility_scores[i] += 0.1;
        } else if (age_diff <= 10) {
            compatibility_scores[i] += 0.05;
        }

        // Gender match
        if (strcmp(user.gender, prospects[i].gender) == 0) {
            compatibility_scores[i] += 0.1;
        }

        // Interest overlap
        char *user_interests = strtok(user.interests, ", ");
        while (user_interests != NULL) {
            char *prospect_interests = strtok(prospects[i].interests, ", ");
            while (prospect_interests != NULL) {
                if (strcmp(user_interests, prospect_interests) == 0) {
                    compatibility_scores[i] += 0.1;
                }
                prospect_interests = strtok(NULL, ", ");
            }
            user_interests = strtok(NULL, ", ");
        }
    }

    // Find the most compatible prospect
    int best_prospect_index = -1;
    double best_compatibility_score = -1;
    for (int i = 0; i < num_prospects; i++) {
        if (compatibility_scores[i] > best_compatibility_score) {
            best_compatibility_score = compatibility_scores[i];
            best_prospect_index = i;
        }
    }

    // Print the results
    if (best_prospect_index != -1) {
        printf("Your best match is %s!\n", prospects[best_prospect_index].name);
        printf("Your compatibility score is %f\n", best_compatibility_score);
    } else {
        printf("Unfortunately, we couldn't find any suitable matches for you.\n");
        printf("Please try broadening your search criteria or checking back later.\n");
    }

    return 0;
}