//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_EVIDENCE 100

typedef struct {
    int importance;
    char description[256];
} Evidence;

int compare(const void *a, const void *b) {
    Evidence *evidence1 = (Evidence *)a;
    Evidence *evidence2 = (Evidence *)b;
    return evidence2->importance - evidence1->importance; // Sort in descending order
}

void displayEvidence(Evidence *evidences, int count) {
    printf("Sorted Evidence Based on Importance:\n\n");
    for (int i = 0; i < count; i++) {
        printf("Importance: %d, Description: %s\n", evidences[i].importance, evidences[i].description);
    }
}

int main() {
    Evidence evidences[MAX_EVIDENCE];
    int count = 0;

    printf("Welcome to the Case of the Missing Heirloom!\n");
    printf("As Sherlock Holmes, we must gather crucial evidence...\n");

    // Collect evidence
    while (1) {
        printf("\nEnter the importance of the evidence (0 to finish): ");
        int importance;
        scanf("%d", &importance);
        
        if (importance == 0) {
            break; // Stop inputting evidence
        }

        printf("Describe the evidence: ");
        getchar(); // To consume the newline character left in the buffer
        fgets(evidences[count].description, sizeof(evidences[count].description), stdin);
        
        // Remove the newline character from description
        evidences[count].description[strcspn(evidences[count].description, "\n")] = 0;

        evidences[count].importance = importance;
        count++;
        
        if (count >= MAX_EVIDENCE) {
            printf("Maximum number of evidence entries reached!\n");
            break;
        }
    }

    // Sort evidence based on their importance using a greedy approach
    qsort(evidences, count, sizeof(Evidence), compare);
    
    displayEvidence(evidences, count);

    // Display the most important evidence
    if (count > 0) {
        printf("\nMost Important Evidence:\n");
        printf("Importance: %d, Description: %s\n", evidences[0].importance, evidences[0].description);
    } else {
        printf("No evidence collected.\n");
    }

    // Conclusion of the case
    printf("\nWith this evidence, we have enough to solve the mystery!\n");
    
    return 0;
}