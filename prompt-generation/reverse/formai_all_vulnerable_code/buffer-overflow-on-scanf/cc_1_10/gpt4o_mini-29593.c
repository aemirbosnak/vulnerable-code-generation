//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_EVIDENCE 10

typedef struct {
    char description[100];
    int significance;
} Evidence;

typedef struct {
    Evidence evidences[MAX_EVIDENCE];
    int count;
} Case;

void addEvidence(Case *caseFile, const char* description, int significance) {
    if (caseFile->count < MAX_EVIDENCE) {
        strcpy(caseFile->evidences[caseFile->count].description, description);
        caseFile->evidences[caseFile->count].significance = significance;
        caseFile->count++;
        printf("Evidence added: %s (Significance: %d)\n", description, significance);
    } else {
        printf("Maximum number of evidences reached.\n");
    }
}

double calculateProbability(Case *caseFile) {
    double totalSignificance = 0;
    for (int i = 0; i < caseFile->count; i++) {
        totalSignificance += caseFile->evidences[i].significance;
    }
    return totalSignificance / (caseFile->count > 0 ? caseFile->count : 1);
}

void displayCase(Case *caseFile) {
    printf("\n--- Sherlock Holmes' Alien Invasion Case File ---\n");
    for (int i = 0; i < caseFile->count; i++) {
        printf("Evidence #%d: %s (Significance: %d)\n", 
            i + 1,
            caseFile->evidences[i].description,
            caseFile->evidences[i].significance);
    }
    double probability = calculateProbability(caseFile);
    printf("Estimated probability of alien invasion: %.2f%%\n", probability);
    printf("-----------------------------------------------\n");
}

int main() {
    Case alienCase = {.count = 0};
    char command[50];
    
    printf("Welcome to the Sherlock Holmes Alien Invasion Probability Calculator!\n");
    
    while (1) {
        printf("Enter a command (add, display, exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            char description[100];
            int significance;
            printf("Enter evidence description: ");
            getchar(); // Clear newline character from input buffer
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0'; // Remove newline
            
            printf("Enter evidence significance (1-10): ");
            scanf("%d", &significance);
            if (significance < 1 || significance > 10) {
                printf("Significance must be between 1 and 10.\n");
                continue;
            }
            addEvidence(&alienCase, description, significance);
        } else if (strcmp(command, "display") == 0) {
            displayCase(&alienCase);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Alien Invasion Probability Calculator...\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
    
    return 0;
}