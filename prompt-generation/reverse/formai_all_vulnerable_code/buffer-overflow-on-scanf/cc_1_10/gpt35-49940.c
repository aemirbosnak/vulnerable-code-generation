//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct resume {
    char name[50];
    int age;
    char email[50];
    char education[50];
    char skills[100];
} Resume;

int main() {
    printf("Welcome to the C Resume Parsing System! We take your resume seriously... but not too seriously.\n");
    printf("Please enter your name: \n");
    char name[50];
    scanf("%s", name);
    printf("Please enter your age: \n");
    int age;
    scanf("%d", &age);
    printf("Please enter your email: \n");
    char email[50];
    scanf("%s", email);
    printf("Please enter your education: \n");
    char education[50];
    scanf("%s", education);
    printf("Please enter your skills: \n");
    char skills[100];
    scanf("%s", skills);

    Resume *newResume = (Resume*) malloc(sizeof(Resume));
    if (newResume == NULL) {
        printf("Oops, something went wrong! Please try again later.\n");
        return 1;
    }

    //Assigning values to resume structure
    for (int i = 0; i < 50; i++) {
        newResume->name[i] = name[i];
        if (i < 50) {
          newResume->email[i] = email[i];
          newResume->education[i] = education[i];
       }
       if (i < 100) {
          newResume->skills[i] = skills[i];
       }
    }
    newResume->age = age;

    printf("Congratulations, your resume has been parsed successfully!\n");
    printf("Here is your information:\n");
    printf("Name: %s\n", newResume->name);
    printf("Age: %d\n", newResume->age);
    printf("Email: %s\n", newResume->email);
    printf("Education: %s\n", newResume->education);
    printf("Skills: %s\n", newResume->skills);

    free(newResume);
    return 0;
}