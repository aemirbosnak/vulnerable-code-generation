//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 50
#define MAX_EXP_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXP_LENGTH];
} Resume;

Resume resumes[MAX_RESUMES];
int numResumes = 0;

void addResume(char* name, char* experience) {
    if (numResumes >= MAX_RESUMES) {
        printf("Error: Too many resumes!\n");
        return;
    }

    strcpy(resumes[numResumes].name, name);
    strcpy(resumes[numResumes].experience, experience);

    numResumes++;
}

void searchResumes(char* keyword) {
    int i;

    for (i = 0; i < numResumes; i++) {
        if (strstr(resumes[i].name, keyword)!= NULL || strstr(resumes[i].experience, keyword)!= NULL) {
            printf("Resume %d:\nName: %s\nExperience: %s\n", i, resumes[i].name, resumes[i].experience);
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add resume\n2. Search resumes\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", resumes[numResumes].name);
                printf("Enter experience: ");
                scanf("%s", resumes[numResumes].experience);
                break;
            case 2:
                printf("Enter keyword: ");
                scanf("%s", resumes[numResumes].name);
                searchResumes(resumes[numResumes].name);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}