//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_JOB_LENGTH 50
#define MAX_SKILLS_LENGTH 100
#define MAX_EDUCATION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char job[MAX_JOB_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
} Resume;

void readResume(Resume *r) {
    printf("Enter your name: ");
    scanf("%s", r->name);

    printf("Enter your job: ");
    scanf("%s", r->job);

    printf("Enter your skills: ");
    scanf("%s", r->skills);

    printf("Enter your education: ");
    scanf("%s", r->education);
}

void printResume(Resume r) {
    printf("Name: %s\n", r.name);
    printf("Job: %s\n", r.job);
    printf("Skills: %s\n", r.skills);
    printf("Education: %s\n", r.education);
}

int main() {
    Resume player1, player2;

    printf("Player 1, enter your information:\n");
    readResume(&player1);

    printf("Player 2, enter your information:\n");
    readResume(&player2);

    printf("Player 1's resume:\n");
    printResume(player1);

    printf("Player 2's resume:\n");
    printResume(player2);

    return 0;
}