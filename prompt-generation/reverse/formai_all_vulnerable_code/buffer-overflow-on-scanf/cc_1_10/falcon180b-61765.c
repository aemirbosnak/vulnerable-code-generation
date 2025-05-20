//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char name[50];
    char email[100];
    char phone[15];
    char address[200];
    char skills[200];
    char experience[200];
    char education[200];
} Candidate;

void addCandidate(Candidate* candidates, int numCandidates) {
    printf("Enter candidate name: ");
    scanf("%s", candidates[numCandidates].name);
    printf("Enter candidate email: ");
    scanf("%s", candidates[numCandidates].email);
    printf("Enter candidate phone number: ");
    scanf("%s", candidates[numCandidates].phone);
    printf("Enter candidate address: ");
    scanf("%s", candidates[numCandidates].address);
    printf("Enter candidate skills: ");
    scanf("%s", candidates[numCandidates].skills);
    printf("Enter candidate experience: ");
    scanf("%s", candidates[numCandidates].experience);
    printf("Enter candidate education: ");
    scanf("%s", candidates[numCandidates].education);
    numCandidates++;
}

void printCandidate(Candidate candidate) {
    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone: %s\n", candidate.phone);
    printf("Address: %s\n", candidate.address);
    printf("Skills: %s\n", candidate.skills);
    printf("Experience: %s\n", candidate.experience);
    printf("Education: %s\n", candidate.education);
}

void searchCandidate(Candidate* candidates, int numCandidates, char* query) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        if (strstr(candidates[i].name, query) || strstr(candidates[i].email, query) || strstr(candidates[i].phone, query) || strstr(candidates[i].address, query) || strstr(candidates[i].skills, query) || strstr(candidates[i].experience, query) || strstr(candidates[i].education, query)) {
            printCandidate(candidates[i]);
        }
    }
}

int main() {
    Candidate candidates[100];
    int numCandidates = 0;

    addCandidate(candidates, numCandidates);
    addCandidate(candidates, numCandidates);
    addCandidate(candidates, numCandidates);

    char query[50];
    printf("Enter search query: ");
    scanf("%s", query);

    searchCandidate(candidates, numCandidates, query);

    return 0;
}