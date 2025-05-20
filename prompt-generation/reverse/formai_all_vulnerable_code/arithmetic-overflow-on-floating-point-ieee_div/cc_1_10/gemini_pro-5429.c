//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
// Deductive Alien Invasion Probability Calculator, by Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Watson's notes on alien invasion probabilities
#define MIN_PROBABILITY 0.01
#define MAX_PROBABILITY 0.99
#define STEP_SIZE 0.01

// Holmes' evidence categories
#define EVIDENCE_UFO_SIGHTINGS 1
#define EVIDENCE_CROP_CIRCLES 2
#define EVIDENCE_ABDUCTIONS 3
#define EVIDENCE_GOVERNMENT_CONSPIRACY 4

// Bayes' theorem formula
#define BAYES_PROBABILITY(p_a, p_b, p_a_given_b) (p_a_given_b * p_b) / (p_a_given_b * p_b + (1 - p_a_given_b) * (1 - p_b))

// Function to calculate the probability of an alien invasion based on given evidence
double calculate_invasion_probability(int evidence_category, double evidence_probability) {
    // Initialize the prior probability of an alien invasion
    double invasion_probability = 0.5;

    // Update the probability based on the given evidence
    switch (evidence_category) {
        case EVIDENCE_UFO_SIGHTINGS:
            invasion_probability = BAYES_PROBABILITY(invasion_probability, evidence_probability, 0.75);
            break;
        case EVIDENCE_CROP_CIRCLES:
            invasion_probability = BAYES_PROBABILITY(invasion_probability, evidence_probability, 0.6);
            break;
        case EVIDENCE_ABDUCTIONS:
            invasion_probability = BAYES_PROBABILITY(invasion_probability, evidence_probability, 0.85);
            break;
        case EVIDENCE_GOVERNMENT_CONSPIRACY:
            invasion_probability = BAYES_PROBABILITY(invasion_probability, evidence_probability, 0.9);
            break;
        default:
            printf("Invalid evidence category provided.\n");
            break;
    }

    // Ensure the probability is within the valid range
    if (invasion_probability < MIN_PROBABILITY) {
        invasion_probability = MIN_PROBABILITY;
    } else if (invasion_probability > MAX_PROBABILITY) {
        invasion_probability = MAX_PROBABILITY;
    }

    return invasion_probability;
}

// Function to display the results of the calculation
void display_results(double invasion_probability) {
    printf("Elementary, my dear Watson!\n");
    printf("Based on the evidence you have presented, the probability of an alien invasion is: %.2f%%\n", invasion_probability * 100);

    if (invasion_probability < 0.2) {
        printf("It appears the threat is minimal. No need to worry, Watson.\n");
    } else if (invasion_probability < 0.5) {
        printf("The evidence suggests a moderate risk. We should remain vigilant, but not overly alarmed.\n");
    } else {
        printf("The situation is dire, Watson! We must prepare for the worst.\n");
    }
}

// Main function to gather evidence and calculate the invasion probability
int main() {
    // Welcome message
    printf("Welcome to my Alien Invasion Probability Calculator, Dr. Watson.\n");

    // Gather evidence from Watson
    int evidence_category;
    double evidence_probability;

    printf("What type of evidence have you gathered, Watson? (Enter evidence category number):\n");
    printf("1. UFO sightings\n2. Crop circles\n3. Abductions\n4. Government conspiracy\n");
    scanf("%d", &evidence_category);

    printf("What is the estimated probability of this evidence being genuine? (Enter a value between 0.01 and 0.99):\n");
    scanf("%lf", &evidence_probability);

    // Calculate the invasion probability based on the evidence
    double invasion_probability = calculate_invasion_probability(evidence_category, evidence_probability);

    // Display the results
    display_results(invasion_probability);

    return 0;
}