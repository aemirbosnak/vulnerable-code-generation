//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 5
#define MAX_NAME_LENGTH 50
#define MAX_SKILLS_LENGTH 100
#define MAX_OBJECTIVE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    char objective[MAX_OBJECTIVE_LENGTH];
    int years_of_experience;
} Resume;

int main() {
    // Display a romantic message to the user
    printf("My sweet love, welcome to our very own C Resume Parsing System!\n\n");

    // Declare an array of resumes
    Resume resumes[MAX_RESUMES];
    int num_resumes = 0;

    // Prompt the user to enter all the resumes they have
    while(num_resumes < MAX_RESUMES) {
        printf("My dear, please enter the name of the candidate (or type \"done\" to finish): ");
        scanf("%s", resumes[num_resumes].name);

        // Check whether the user is done entering resumes
        if(strcmp(resumes[num_resumes].name, "done") == 0) {
            break;
        }

        printf("And now, my love, please enter the candidate's skills: ");
        scanf("%s", resumes[num_resumes].skills);

        printf("Finally, please enter their objective: ");
        scanf("%s", resumes[num_resumes].objective);

        printf("Could you tell me how many years of experience they have?");
        scanf("%d", &resumes[num_resumes].years_of_experience);

        num_resumes++;
    }

    // Display a message showing how many resumes were entered
    printf("\nMy sweet, we have entered %d resumes into the system. Here they are:\n\n", num_resumes);

    // Display all the resumes to the user
    for(int i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i+1);
        printf("Name: %s\n", resumes[i].name);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Objective: %s\n", resumes[i].objective);
        printf("Years of Experience: %d\n\n", resumes[i].years_of_experience);
    }

    // Say goodbye to the user in a romantic way
    printf("Farewell my love, thank you for using our C Resume Parsing System together. Until next time!\n");

    return 0;
}