//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Resume
typedef struct {
    char name[50];
    char email[50];
    char mobile[15];
    char education[100];
    char skills[500];
} Resume;

// Function to parse Resume
Resume parseResume(char* filename) {
    Resume resume;
    FILE* fp;

    // Open Resume file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read Resume data
    fscanf(fp, "%[^\n]s", resume.name);
    fscanf(fp, "\n%[^\n]s", resume.email);
    fscanf(fp, "\n%[^\n]s", resume.mobile);
    fscanf(fp, "\n%[^\n]s", resume.education);
    fscanf(fp, "\n%[^\n]s", resume.skills);

    // Close file
    fclose(fp);

    // Return parsed Resume
    return resume;
}

int main() {
    char filename[] = "resume.txt";
    Resume resume = parseResume(filename);

    // Print parsed Resume data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Mobile: %s\n", resume.mobile);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);

    return 0;
}