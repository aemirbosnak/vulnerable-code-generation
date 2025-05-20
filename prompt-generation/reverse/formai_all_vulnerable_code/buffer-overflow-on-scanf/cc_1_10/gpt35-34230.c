//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[100];
    char phone[15];
    char education[200];
    char skills[500];
    char experience[1000];
};

int main() {
    struct resume candidate;
    FILE *fptr;
    char filename[100];
    
    // Prompt user for file name
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // Open file
    fptr = fopen(filename, "r");
    
    // Check if file exists and can be opened
    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // Parse file and fill struct
    char line[1000];
    while (fgets(line, 1000, fptr)) {
        // Parse name
        if (strstr(line, "Name:")) {
            strcpy(candidate.name, line + 6);
            candidate.name[strlen(candidate.name) - 1] = '\0';
        }
        
        // Parse email
        if (strstr(line, "Email:")) {
            strcpy(candidate.email, line + 7);
            candidate.email[strlen(candidate.email) - 1] = '\0';
        }
        
        // Parse phone number
        if (strstr(line, "Phone:")) {
            strcpy(candidate.phone, line + 7);
            candidate.phone[strlen(candidate.phone) - 1] = '\0';
        }
        
        // Parse education
        if (strstr(line, "Education:")) {
            strcpy(candidate.education, line + 11);
            candidate.education[strlen(candidate.education) - 1] = '\0';
        }
        
        // Parse skills
        if (strstr(line, "Skills:")) {
            strcpy(candidate.skills, line + 8);
            candidate.skills[strlen(candidate.skills) - 1] = '\0';
        }
        
        // Parse experience
        if (strstr(line, "Experience:")) {
            strcpy(candidate.experience, line + 12);
            candidate.experience[strlen(candidate.experience) - 1] = '\0';
        }
    }
    
    // Close file
    fclose(fptr);
    
    // Output parsed resume information
    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone: %s\n", candidate.phone);
    printf("Education: %s\n", candidate.education);
    printf("Skills: %s\n", candidate.skills);
    printf("Experience: %s\n", candidate.experience);
    
    return 0;
}