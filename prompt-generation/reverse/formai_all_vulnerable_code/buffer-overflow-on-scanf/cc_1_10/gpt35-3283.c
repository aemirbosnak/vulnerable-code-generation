//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char education[50];
    char skills[100];
    char experience[100];
};

int main() {
    int num_resumes;
    printf("Enter the number of resumes to parse: ");
    scanf("%d", &num_resumes);
    struct resume resumes[num_resumes];
    char temp[100]; //temp string to hold input
    
    for (int i = 0; i < num_resumes; i++) {
        printf("Enter name of applicant %d: ", i+1);
        fgets(temp, 100, stdin); //flush stdin
        fgets(temp, 100, stdin);
        strcpy(resumes[i].name, temp);
        
        printf("Enter education of applicant %d: ", i+1);
        fgets(temp, 100, stdin); //flush stdin
        fgets(temp, 100, stdin);
        strcpy(resumes[i].education, temp);
        
        printf("Enter skills of applicant %d: ", i+1);
        fgets(temp, 100, stdin); //flush stdin
        fgets(temp, 100, stdin);
        strcpy(resumes[i].skills, temp);
        
        printf("Enter experience of applicant %d: ", i+1);
        fgets(temp, 100, stdin); //flush stdin
        fgets(temp, 100, stdin);
        strcpy(resumes[i].experience, temp);
    }
    
    printf("\n\n***RESUME PARSING RESULTS***\n\n");
    
    for (int i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i+1);
        printf("Name: %s", resumes[i].name);
        printf("Education: %s", resumes[i].education);
        printf("Skills: %s", resumes[i].skills);
        printf("Experience: %s\n\n", resumes[i].experience);
    }
    
    return 0;
}