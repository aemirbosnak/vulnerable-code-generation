//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char skills[200];
    int experience;
    char education[50];
};

int main() {
    struct Resume r[5];
    char parse_skills[200];
    int num_resumes, i, j;
    char c;

    printf("Welcome to the Resume Parsing System!\n");
    printf("How many resumes would you like to parse? (up to 5)\n");
    scanf("%d", &num_resumes);

    while ((c = getchar()) != '\n' && c != EOF); // to clear input buffer

    for (i = 0; i < num_resumes; i++) {
        printf("Resume %d\n", i+1);

        printf("Enter full name: ");
        fgets(r[i].name, sizeof(r[i].name), stdin);
        r[i].name[strlen(r[i].name)-1] = '\0'; // removing newline character

        printf("Enter email address: ");
        fgets(r[i].email, sizeof(r[i].email), stdin);
        r[i].email[strlen(r[i].email)-1] = '\0'; // removing newline character

        printf("Enter list of skills (separated by commas): ");
        fgets(parse_skills, sizeof(parse_skills), stdin);
        parse_skills[strlen(parse_skills)-1] = '\0'; // removing newline character

        // Splitting skills into array
        char *ptr = strtok(parse_skills, ",");
        j = 0;
        while (ptr != NULL) {
            strcpy(r[i].skills+(j*50), ptr);
            ptr = strtok(NULL, ",");
            j++;
        }

        printf("Enter years of experience: ");
        scanf("%d", &r[i].experience);
        while ((c = getchar()) != '\n' && c != EOF); // to clear input buffer

        printf("Enter highest level of education: ");
        fgets(r[i].education, sizeof(r[i].education), stdin);
        r[i].education[strlen(r[i].education)-1] = '\0'; // removing newline character

        printf("\n");
    }

    printf("Resume Parsing Results:\n\n");

    for (i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i+1);
        printf("Name: %s\n", r[i].name);
        printf("Email: %s\n", r[i].email);
        printf("Skills:");
        for (j = 0; j < 4; j++) {
            printf("\n- %s", r[i].skills+(j*50));
        }
        printf("\nYears of experience: %d\n", r[i].experience);
        printf("Education: %s\n\n", r[i].education);
    }

    return 0;
}