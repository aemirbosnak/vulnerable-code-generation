//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char school[50];
    char degree[50];
    char company[50];
    char title[50];
    char skill[200];
};

int main() {
    int num_resumes;
    printf("How many resumes would you like to parse? ");
    scanf("%d", &num_resumes);

    struct resume *resumes = malloc(num_resumes * sizeof(struct resume));
    if (!resumes) {
        printf("Memory allocation error!\n");
        return 1;
    }

    printf("Enter the following information for each resume:\n");

    for (int i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i+1);

        printf("   Name: ");
        scanf("%s", resumes[i].name);

        printf("   Email: ");
        scanf("%s", resumes[i].email);

        printf("   Phone: ");
        scanf("%s", resumes[i].phone);

        printf("   School: ");
        scanf("%s", resumes[i].school);

        printf("   Degree: ");
        scanf("%s", resumes[i].degree);

        printf("   Company: ");
        scanf("%s", resumes[i].company);

        printf("   Title: ");
        scanf("%s", resumes[i].title);

        printf("   Skill: ");
        scanf("%s", resumes[i].skill);
    }

    // Now we can distribute the resumes to various parsers in parallel.

    // In this example, we'll just print out the information for each resume.
    for (int i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i+1);
        printf("   Name: %s\n", resumes[i].name);
        printf("   Email: %s\n", resumes[i].email);
        printf("   Phone: %s\n", resumes[i].phone);
        printf("   School: %s\n", resumes[i].school);
        printf("   Degree: %s\n", resumes[i].degree);
        printf("   Company: %s\n", resumes[i].company);
        printf("   Title: %s\n", resumes[i].title);
        printf("   Skill: %s\n", resumes[i].skill);
    }

    free(resumes);
    return 0;
}