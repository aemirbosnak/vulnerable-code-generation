//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[50];
    char skills[100];
    char experience[200];
};

int main() {
    struct Resume *res;
    int n, i;
    char search[20];
    printf("Enter the number of resumes to parse: ");
    scanf("%d", &n);

    res = (struct Resume*) malloc(n * sizeof(struct Resume));
    for(i = 0; i < n; i++) {
        printf("\nResume %d:", i+1);
        printf("\nEnter name: ");
        scanf("%s", res[i].name);
        printf("Enter email: ");
        scanf("%s", res[i].email);
        printf("Enter phone number: ");
        scanf("%s", res[i].phone);
        printf("Enter education : ");
        scanf("%s", res[i].education);
        printf("Enter skills: ");
        scanf("%s", res[i].skills);
        printf("Enter experience: ");
        scanf("%s", res[i].experience);
    }

    printf("\nEnter a skill to search (e.g. Java, Python): ");
    scanf("%s", search);
    printf("\nResumes with %s skill:\n", search);
    for(i = 0; i < n; i++) {
        if(strstr(res[i].skills, search) != NULL) {
            printf("\nResume %d\n", i+1);
            printf("Name: %s\n", res[i].name);
            printf("Email: %s\n", res[i].email);
            printf("Phone: %s\n", res[i].phone);
            printf("Education: %s\n", res[i].education);
            printf("Skills: %s\n", res[i].skills);
            printf("Experience: %s\n", res[i].experience);
        }
    }

    free(res);
    return 0;
}