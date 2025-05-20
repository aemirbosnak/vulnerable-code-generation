//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of candidates and skills, should be adjusted
// based on the expected number
#define MAX_CANDIDATES 100
#define MAX_SKILLS 20

// Define the structure of a candidate
typedef struct candidate {
    char name[20];
    int id;
    int numSkills;
    char skills[MAX_SKILLS][20];
} candidate_t;

// Define the structure of a skill
typedef struct skill {
    char name[20];
    int weight;
} skill_t;

// Define the structure of a job description
typedef struct jobDescription {
    char title[20];
    int numSkills;
    skill_t skills[MAX_SKILLS];
} jobDescription_t;

// Function to calculate the similarity between two candidates and a job description
double similarity(candidate_t candidate, jobDescription_t jobDescription) {
    double similarity = 0.0;
    
    // Calculate the sum of the weights of the matching skills
    int numMatchingSkills = 0;
    for (int i = 0; i < candidate.numSkills; i++) {
        for (int j = 0; j < jobDescription.numSkills; j++) {
            if (strcmp(candidate.skills[i], jobDescription.skills[j].name) == 0) {
                similarity += jobDescription.skills[j].weight;
                numMatchingSkills++;
            }
        }
    }
    
    // Normalize the similarity by the number of skills in the job description
    similarity /= jobDescription.numSkills;
    
    return similarity;
}

int main() {

    // Define the list of candidates
    candidate_t candidates[MAX_CANDIDATES];
    int numCandidates = 0;
    
    // Get the number of candidates
    scanf("%d", &numCandidates);
    
    // Get the details of each candidate
    for (int i = 0; i < numCandidates; i++) {
        scanf("%s %d %d", candidates[i].name, &candidates[i].id, &candidates[i].numSkills);
        for (int j = 0; j < candidates[i].numSkills; j++) {
            scanf("%s", candidates[i].skills[j]);
        }
    }
    
    // Define the job description
    jobDescription_t jobDescription;
    
    // Get the title of the job
    scanf("%s", jobDescription.title);
    
    // Get the number of skills required for the job
    scanf("%d", &jobDescription.numSkills);
    
    // Get the details of each skill required for the job
    for (int i = 0; i < jobDescription.numSkills; i++) {
        scanf("%s %d", jobDescription.skills[i].name, &jobDescription.skills[i].weight);
    }
    
    // Calculate the similarity between each candidate and the job description
    double similarities[MAX_CANDIDATES];
    for (int i = 0; i < numCandidates; i++) {
        similarities[i] = similarity(candidates[i], jobDescription);
    }
    
    // Find the candidate with the highest similarity
    int bestCandidateIndex = 0;
    double bestSimilarity = 0.0;
    for (int i = 1; i < numCandidates; i++) {
        if (similarities[i] > bestSimilarity) {
            bestCandidateIndex = i;
            bestSimilarity = similarities[i];
        }
    }
    
    // Print the name and ID of the best candidate
    printf("%s %d\n", candidates[bestCandidateIndex].name, candidates[bestCandidateIndex].id);
    
    return 0;
}