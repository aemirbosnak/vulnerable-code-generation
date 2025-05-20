//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of keywords
#define MAX_KEYWORDS 50

// Define the maximum length of each keyword
#define MAX_KEYWORD_LENGTH 100

// Define the maximum length of the resume text
#define MAX_RESUME_LENGTH 10000

// Define the maximum number of skills that can be extracted
#define MAX_SKILLS 10

// Define the length of the skill names
#define MAX_SKILL_NAME_LENGTH 50

// Define the length of the match percentage string
#define MATCH_PERCENTAGE_LENGTH 8

// Define an array to store the keywords
char keywords[MAX_KEYWORDS][MAX_KEYWORD_LENGTH] = {
    "C",
    "Java",
    "Python",
    "HTML",
    "CSS",
    "JavaScript",
    "SQL",
    "Android",
    "iOS",
    "Machine Learning",
    "Natural Language Processing",
    "Data Analytics",
    "Software Development",
    "Full Stack Development",
    "Web Development",
    "UI/UX Design",
    "Agile Methodology",
    "Project Management",
    "Team Leadership"
};

// Define the struct to hold the resume details
typedef struct {
    char text[MAX_RESUME_LENGTH];
    char skills[MAX_SKILLS][MAX_SKILL_NAME_LENGTH];
    float match_percentage;
    int num_skills;
} Resume;

// Function to get the list of keywords from the user
void get_keywords() {
    printf("Enter the list of keywords:\n");
    for(int i=0; i<MAX_KEYWORDS; i++) {
        scanf("%s", keywords[i]);
    }
}

// Function to parse a resume and extract the skills
Resume parse_resume(char *resume_text) {
    
    // Create a new Resume struct
    Resume new_resume;
    strcpy(new_resume.text, resume_text);
    new_resume.num_skills = 0;
    new_resume.match_percentage = 0.0;
    
    // Loop through all the keywords and check if they are present in the resume
    for(int i=0; i<MAX_KEYWORDS; i++) {
        char *pos = strstr(resume_text, keywords[i]);
        if(pos) {
            strcpy(new_resume.skills[new_resume.num_skills], keywords[i]);
            new_resume.num_skills++;
        }
    }
    
    return new_resume;
}

// Function to calculate the match percentage between two resumes
float calculate_match_percentage(Resume resume1, Resume resume2) {
    
    int num_skills_matching = 0;
    
    // Loop through the skills in resume1 and check if they are present in resume2
    for(int i=0; i<resume1.num_skills; i++) {
        for(int j=0; j<resume2.num_skills; j++) {
            if(strcmp(resume1.skills[i], resume2.skills[j]) == 0) {
                num_skills_matching++;
                break;
            }
        }
    }
    
    // Calculate the match percentage
    float match_percentage = (float) num_skills_matching / (float) resume1.num_skills;
    
    return match_percentage;
}

int main() {
    
    // Get the list of keywords from the user
    get_keywords();
    
    // Get the two resumes from the user
    char resume1_text[MAX_RESUME_LENGTH], resume2_text[MAX_RESUME_LENGTH];
    printf("Enter the text for resume 1:\n");
    gets(resume1_text);
    printf("Enter the text for resume 2:\n");
    gets(resume2_text);
    
    // Parse the resumes and extract the skills
    Resume resume1 = parse_resume(resume1_text);
    Resume resume2 = parse_resume(resume2_text);
    
    // Calculate the match percentage between the two resumes
    float match_percentage = calculate_match_percentage(resume1, resume2);
    
    // Print the result
    printf("\nResume 1:\n%s\n", resume1.text);
    printf("%d skills found:\n", resume1.num_skills);
    for(int i=0; i<resume1.num_skills; i++) {
        printf("%s\n", resume1.skills[i]);
    }
    
    printf("\nResume 2:\n%s\n", resume2.text);
    printf("%d skills found:\n", resume2.num_skills);
    for(int i=0; i<resume2.num_skills; i++) {
        printf("%s\n", resume2.skills[i]);
    }
    
    printf("\nMatch percentage: %.2f%%\n", match_percentage*100);
    
    return 0;
}