//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
// C Resume Parsing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initializing variables
    char name[50], email[50], education[100];
    int age, experience;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your email: ");
    scanf("%s", email);

    printf("Enter your education: ");
    scanf("%s", education);

    printf("Enter your experience (in years): ");
    scanf("%d", &experience);

    // Performing resume parsing
    int score = 0;

    if (strlen(name) >= 5 && strchr(name, ' ') != NULL) {
        score++;
    }

    if (strstr(email, ".com") != NULL) {
        score++;
    }

    if (strstr(education, "B.E") != NULL || strstr(education, "B.Tech") != NULL) {
        score++;
    }

    if (experience >= 2) {
        score++;
    }

    // Generating result based on score
    if (score == 0) {
        printf("Sorry, your resume does not meet our requirements.\n");
    } else if (score == 1) {
        printf("Your resume has potential, but needs improvement.\n");
    } else if (score == 2) {
        printf("You have a good chance of being selected for an interview.\n");
    } else if (score == 3) {
        printf("Congratulations! You have been shortlisted for an interview.\n");
    } else {
        printf("Something went wrong with the scoring system.\n");
    }

    return 0;
}