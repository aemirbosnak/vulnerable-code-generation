//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVIDENCE 5
#define NAME_LENGTH 30

typedef struct Evidence {
    char *name;
    char *description;
} Evidence;

void allocateEvidence(Evidence *evidence) {
    // Memory allocation for name and description
    evidence->name = (char *)malloc(NAME_LENGTH * sizeof(char));
    evidence->description = (char *)malloc(100 * sizeof(char));

    if (evidence->name == NULL || evidence->description == NULL) {
        fprintf(stderr, "Memory allocation failure\n");
        exit(EXIT_FAILURE);
    }
}

void freeEvidence(Evidence *evidence) {
    // Free allocated memory
    free(evidence->name);
    free(evidence->description);
}

void investigate(Evidence *evidenceArr, int count) {
    printf("Investigation Report:\n");
    printf("---------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Evidence #%d:\n", i + 1);
        printf("Name: %s\n", evidenceArr[i].name);
        printf("Description: %s\n\n", evidenceArr[i].description);
    }
}

int main() {
    Evidence evidence[MAX_EVIDENCE];
    int evidenceCount = 0;

    // Sherlock Holmes' initial observations
    printf("Welcome to the Investigation Room of Sherlock Holmes.\n");
    printf("We shall gather pieces of evidence below:\n");

    while (evidenceCount < MAX_EVIDENCE) {
        // Let the detective input the evidence
        printf("Enter the name of evidence #%d: ", evidenceCount + 1);
        allocateEvidence(&evidence[evidenceCount]);
        fgets(evidence[evidenceCount].name, NAME_LENGTH, stdin);
        evidence[evidenceCount].name[strcspn(evidence[evidenceCount].name, "\n")] = '\0'; // Remove newline

        printf("Enter the description of evidence #%d: ", evidenceCount + 1);
        fgets(evidence[evidenceCount].description, 100, stdin);
        evidence[evidenceCount].description[strcspn(evidence[evidenceCount].description, "\n")] = '\0'; // Remove newline

        evidenceCount++;

        char choice;
        if (evidenceCount < MAX_EVIDENCE) {
            printf("Would you like to add another evidence? (y/n): ");
            scanf(" %c", &choice);
            getchar(); // Clear the newline character from the input buffer
            if (choice != 'y') break;
        }
    }

    // Conduct the investigation
    investigate(evidence, evidenceCount);

    // Free allocated memory
    for (int i = 0; i < evidenceCount; i++) {
        freeEvidence(&evidence[i]);
    }

    printf("Thank you for participating in the investigation. The case may continue...\n");
    return 0;
}