//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <string.h>

struct Resume{
    char name[50], email[50], phone[20], experience[1000], skills[1000], education[500];
};

int main()
{
    struct Resume resume1;
    printf("Enter your name: ");
    scanf("%[^\n]", resume1.name);
    getchar();
    printf("Enter your email: ");
    scanf("%[^\n]", resume1.email);
    getchar();
    printf("Enter your phone number: ");
    scanf("%[^\n]", resume1.phone);
    getchar();
    printf("Enter your experience: ");
    scanf("%[^\n]", resume1.experience);
    getchar();
    printf("Enter your skills: ");
    scanf("%[^\n]", resume1.skills);
    getchar();
    printf("Enter your education: ");
    scanf("%[^\n]", resume1.education);
    getchar();

    char* token = strtok(resume1.experience, " ");
    while(token != NULL){
        if(strcmp(token, "C") == 0 || strcmp(token, "Java") == 0 || strcmp(token, "Python") == 0){
            printf("Candidate has experience in %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    token = strtok(resume1.skills, ",");
    while(token != NULL){
        if(strcmp(token, "C") == 0 || strcmp(token, "Java") == 0 || strcmp(token, "Python") == 0){
            printf("Candidate has skills in %s\n", token);
        }
        token = strtok(NULL, ",");
    }

    if(strcmp(resume1.education, "Computer Science") == 0){
        printf("Candidate has a degree in computer science\n");
    }

    return 0;
}