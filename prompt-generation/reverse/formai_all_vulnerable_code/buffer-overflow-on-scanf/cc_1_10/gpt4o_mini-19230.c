//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_FACTORS 10

typedef struct {
    char name[50];
    float likelihood; // Scale from 0.0 (impossible) to 1.0 (certain)
    float impact;     // Scale from 0.0 (no impact) to 1.0 (catastrophic)
} RiskFactor;

void inputRiskFactors(RiskFactor factors[], int *count) {
    printf("Enter the number of risk factors (max %d): ", MAX_FACTORS);
    scanf("%d", count);
    
    if (*count > MAX_FACTORS) {
        printf("Please enter a value less than or equal to %d.\n", MAX_FACTORS);
        *count = MAX_FACTORS;
    }
    
    for (int i = 0; i < *count; i++) {
        printf("\nEnter the name of risk factor %d: ", i + 1);
        scanf("%s", factors[i].name);
        printf("Enter the likelihood of %s (0.0 to 1.0): ", factors[i].name);
        scanf("%f", &factors[i].likelihood);
        printf("Enter the impact of %s (0.0 to 1.0): ", factors[i].name);
        scanf("%f", &factors[i].impact);
    }
}

float calculateProbability(RiskFactor factors[], int count) {
    float totalProbability = 0.0;
    float totalImpact = 0.0;

    for (int i = 0; i < count; i++) {
        totalProbability += factors[i].likelihood * factors[i].impact;
        totalImpact += factors[i].impact;
    }

    // Normalize the probability score based on total impact
    return (totalImpact > 0) ? totalProbability / totalImpact : 0.0;
}

void displayResult(float probability) {
    printf("\nCalculated Alien Invasion Probability: %.2f\n", probability * 100);
    
    if (probability < 0.2) {
        printf("Risk Level: Low Danger.\n");
    } else if (probability < 0.7) {
        printf("Risk Level: Moderate Danger.\n");
    } else {
        printf("Risk Level: High Danger!\n");
    }
}

int main() {
    RiskFactor riskFactors[MAX_FACTORS];
    int factorCount = 0;
    
    printf("=== Alien Invasion Probability Calculator ===\n");
    inputRiskFactors(riskFactors, &factorCount);
    
    float invasionProbability = calculateProbability(riskFactors, factorCount);
    displayResult(invasionProbability);
    
    return 0;
}