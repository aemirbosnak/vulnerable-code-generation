//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdbool.h>

#define MAX_ARTIFACTS 100

void printArtifacts(int artifacts[], int count) {
    printf("Artifacts in the ancient museum:\n");
    for(int i = 0; i < count; i++) {
        printf("Artifact %d: %d\n", i + 1, artifacts[i]);
    }
}

bool searchArtifact(int artifacts[], int count, int treasure) {
    for(int i = 0; i < count; i++) {
        if(artifacts[i] == treasure) {
            return true;
        }
    }
    return false;
}

int main() {
    int artifacts[MAX_ARTIFACTS];
    int totalArtifacts, treasure;

    printf("Greetings, brave hero! Welcome to the ancient museum of treasures.\n");
    printf("How many artifacts are in the museum? ");
    scanf("%d", &totalArtifacts);

    if(totalArtifacts > MAX_ARTIFACTS) {
        printf("The number of artifacts exceeds the ancient limit of %d. Please reduce your quest!\n", MAX_ARTIFACTS);
        return 1;
    }

    printf("Enter the values of the artifacts (ancient numbers):\n");
    for(int i = 0; i < totalArtifacts; i++) {
        printf("Artifact %d: ", i + 1);
        scanf("%d", &artifacts[i]);
    }

    printArtifacts(artifacts, totalArtifacts);

    printf("Enter the number of the treasure you seek: ");
    scanf("%d", &treasure);

    printf("Hero, you are on a quest to find treasure %d.\n", treasure);

    if(searchArtifact(artifacts, totalArtifacts, treasure)) {
        printf("Congratulations! The treasure %d has been found among the artifacts!\n", treasure);
    } else {
        printf("Alas, the treasure %d is not among the artifacts. Your quest shall continue...\n", treasure);
    }

    // Additional creative features
    printf("Would you like to search for another treasure? (1 = Yes, 0 = No): ");
    int anotherQuest;
    scanf("%d", &anotherQuest);
    
    while(anotherQuest) {
        printf("Enter the number of the new treasure you seek: ");
        scanf("%d", &treasure);

        if(searchArtifact(artifacts, totalArtifacts, treasure)) {
            printf("Congratulations! The treasure %d has been found among the artifacts!\n", treasure);
        } else {
            printf("Alas, the treasure %d is not among the artifacts. Your quest shall continue...\n", treasure);
        }

        printf("Would you like to search for another treasure? (1 = Yes, 0 = No): ");
        scanf("%d", &anotherQuest);
    }

    printf("Thank you for visiting the ancient museum, brave hero! Your adventures shall be sung in the halls of legends.\n");
    return 0;
}