//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100
#define MAX_RESUMES 10

typedef struct {
    char name[MAX_STRING_SIZE];
    char email[MAX_STRING_SIZE];
    char phone[MAX_STRING_SIZE];
    char education[MAX_STRING_SIZE];
    char experience[MAX_STRING_SIZE];
    char skills[MAX_STRING_SIZE];
} Resume;

Resume resumes[MAX_RESUMES];
int num_resumes = 0;

void parse_resume(FILE *fp, int resume_index) {
    char buffer[MAX_STRING_SIZE];
    while (fgets(buffer, MAX_STRING_SIZE, fp) != NULL) {
        if (strstr(buffer, "Name:")) {
            strcpy(resumes[resume_index].name, buffer+strlen("Name: "));
        }
        else if (strstr(buffer, "Email:")) {
            strcpy(resumes[resume_index].email, buffer+strlen("Email: "));
        }
        else if (strstr(buffer, "Phone:")) {
            strcpy(resumes[resume_index].phone, buffer+strlen("Phone: "));
        }
        else if (strstr(buffer, "Education:")) {
            strcpy(resumes[resume_index].education, buffer+strlen("Education: "));
        }
        else if (strstr(buffer, "Experience:")) {
            strcpy(resumes[resume_index].experience, buffer+strlen("Experience: "));
        }
        else if (strstr(buffer, "Skills:")) {
            strcpy(resumes[resume_index].skills, buffer+strlen("Skills: "));
        }   
    }
}

void print_resume(int resume_index) {
    printf("Name: %s\n", resumes[resume_index].name);
    printf("Email: %s\n", resumes[resume_index].email);
    printf("Phone: %s\n", resumes[resume_index].phone);
    printf("Education: %s\n", resumes[resume_index].education);
    printf("Experience: %s\n", resumes[resume_index].experience);
    printf("Skills: %s\n", resumes[resume_index].skills);
}

int main() {
    char filename[MAX_STRING_SIZE];
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    
    while (fp != NULL && num_resumes < MAX_RESUMES) {
        parse_resume(fp, num_resumes);
        num_resumes++;
    }
    
    fclose(fp);
    
    for (int i = 0; i < num_resumes; i++) {
        printf("Resumé #%d:\n", i+1);
        print_resume(i);
        printf("\n");
    }
    
    return 0;
}