//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100

// Candidate data structure
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char skills[100];
} Candidate;

// Function to parse a resume
Candidate parse_resume(char *resume) {
    Candidate candidate;

    // Extract name
    sscanf(resume, "%s %s", candidate.name, candidate.name + strlen(candidate.name) + 1);

    // Extract email
    char *email_start = strstr(resume, "Email:");
    if (email_start) {
        sscanf(email_start, "Email: %s", candidate.email);
    }

    // Extract phone
    char *phone_start = strstr(resume, "Phone:");
    if (phone_start) {
        sscanf(phone_start, "Phone: %s", candidate.phone);
    }

    // Extract skills
    char *skills_start = strstr(resume, "Skills:");
    if (skills_start) {
        sscanf(skills_start, "Skills: %s", candidate.skills);
    }

    return candidate;
}

int main() {
    // Array of candidates
    Candidate candidates[MAX_CANDIDATES];

    // Number of candidates
    int num_candidates = 0;

    // Open resume file
    FILE *fp = fopen("resumes.txt", "r");
    if (!fp) {
        perror("Error opening resume file");
        return -1;
    }

    // Read each resume
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the resume
        Candidate candidate = parse_resume(line);

        // Add the candidate to the array
        candidates[num_candidates++] = candidate;
    }

    // Close the resume file
    fclose(fp);

    // Print the candidates
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d:\n", i + 1);
        printf("Name: %s\n", candidates[i].name);
        printf("Email: %s\n", candidates[i].email);
        printf("Phone: %s\n", candidates[i].phone);
        printf("Skills: %s\n", candidates[i].skills);
        printf("\n");
    }

    return 0;
}