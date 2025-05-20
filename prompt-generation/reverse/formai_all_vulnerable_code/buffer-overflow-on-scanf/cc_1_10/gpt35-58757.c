//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Defining structure to hold resume information
struct Resume{
    char name[50];
    char email[50];
    char education[100];
    char skills[100];
    char experience[100];
};

int main(){
    int n;
    printf("How many Resumes do you want to parse? ");
    scanf("%d", &n);

    int i;
    struct Resume arr[n];
    for(i=0; i<n; i++){
        printf("\nResume #%d\n", i+1);

        printf("Enter Name: ");
        scanf("%s", &arr[i].name);

        printf("Enter Email: ");
        scanf("%s", &arr[i].email);

        printf("Enter Education: ");
        scanf("%s", &arr[i].education);

        printf("Enter Skills: ");
        scanf("%s", &arr[i].skills);

        printf("Enter Experience: ");
        scanf("%s", &arr[i].experience);
    }

    // Searching for Resumes with specific skills
    char skill[50];
    printf("\nEnter the Skill to be searched: ");
    scanf("%s", &skill);

    printf("\nResumes with the skill %s:\n", skill);
    for(i=0; i<n; i++){
        if(strstr(arr[i].skills, skill)){
            printf("%d. Name: %s\n Email: %s\n Education: %s\n Skills: %s\n Experience: %s\n",
                   i+1, arr[i].name, arr[i].email, arr[i].education, arr[i].skills, arr[i].experience);
        }
    }

    return 0;
}