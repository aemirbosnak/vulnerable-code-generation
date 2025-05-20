//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include<stdio.h>
#include<string.h>
#define MAX 1000

typedef struct {
    char f_name[MAX];
    char l_name[MAX];
    char email[MAX];
    char phone[MAX];
    char summary[MAX];
    char skills[MAX];
    char experience[MAX];
    char education[MAX];
} Resume;

void parseResume(char *filename) {
    FILE *fp;
    Resume r;
    char temp[MAX], *token;
    int count = 0;
    
    fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error opening file");
        return;
    }
    
    while (fgets(temp, MAX, fp) != NULL) {
        token = strtok(temp, " ");
        
        while (token != NULL) {
            switch (count) {
                case 0 :
                    strcpy(r.f_name, token);
                    break;
                case 1 :
                    strcpy(r.l_name, token);
                    break;
                case 2 :
                    strcpy(r.email, token);
                    break;
                case 3 :
                    strcpy(r.phone, token);
                    break;
                case 4 :
                    strcpy(r.summary, token);
                    break;
                case 5 :
                    strcpy(r.skills, token);
                    break;
                case 6 :
                    strcpy(r.experience, token);
                    break;
                case 7 :
                    strcpy(r.education, token);
                    break;
            }
            token = strtok(NULL, " ");
            count++;
        }
        count = 0;
    }
    fclose(fp);
    printf("First Name: %s\n", r.f_name);
    printf("Last Name: %s\n", r.l_name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Summary: %s\n", r.summary);
    printf("Skills: %s\n", r.skills);
    printf("Experience: %s\n", r.experience);
    printf("Education: %s\n", r.education);
}

int main() {
    char filename[MAX];
    printf("Enter filename: ");
    scanf("%s", filename);
    parseResume(filename);
    return 0;
}