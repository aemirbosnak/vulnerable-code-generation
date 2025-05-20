//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include<stdio.h>
#include<string.h>

struct Resume{
    char name[50];
    char email[50];
    char phone[15];
    char experience[100];
    char education[100];
    char skills[200];
};

int main(){
    int n, i;
    printf("Enter the number of resumes to be parsed: ");
    scanf("%d", &n);
    struct Resume resume[n];
    for(i=0; i<n; i++){
        printf("\nEnter Resume Details for Applicant #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", resume[i].name);
        printf("Email: ");
        scanf("%s", resume[i].email);
        printf("Phone: ");
        scanf("%s", resume[i].phone);
        printf("Experience: ");
        scanf("%s", resume[i].experience);
        printf("Education: ");
        scanf("%s", resume[i].education);
        printf("Skills: ");
        scanf("%s", resume[i].skills);
    }
    char search_exp[100];
    printf("\nEnter the search experience: ");
    scanf("%s", search_exp);
    printf("\nResumes matching the experience \"%s\":\n", search_exp);
    int count=0;
    for(i=0; i<n; i++){
        if(strstr(resume[i].experience, search_exp) != NULL){
            printf("\nApplicant %d:\n", i+1);
            printf("Name: %s\n", resume[i].name);
            printf("Email: %s\n", resume[i].email);
            printf("Phone: %s\n", resume[i].phone);
            printf("Experience: %s\n", resume[i].experience);
            printf("Education: %s\n", resume[i].education);
            printf("Skills: %s\n", resume[i].skills);
            count++;
        }
    }
    if(count==0){
        printf("\nNo resumes found matching the experience \"%s\".\n", search_exp);
    }
    return 0;
}