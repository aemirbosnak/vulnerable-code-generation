//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store individual's personal details
typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
} personal_details;

// Structure to store individual's work experience details
typedef struct {
    char company[50];
    char designation[50];
    char start_date[10];
    char end_date[10];
} work_experience_details;

// Structure to store individual's educational details
typedef struct {
    char degree[50];
    char college[50];
    char start_date[10];
    char end_date[10];
} educational_details;

// Structure to integrate all the details
typedef struct {
    personal_details personal;
    work_experience_details work_experience[5];
    educational_details educational[5];
} resume_details;

int main() {
    resume_details resume;
    int num_work_exp, num_education;

    // Prompt user to enter personal details
    printf("Enter your name: ");
    scanf("%[^\n]", resume.personal.name);
    getchar();
    printf("Enter your email: ");
    scanf("%s", resume.personal.email);
    printf("Enter your phone number (XXX-XXX-XXXX): ");
    scanf("%s", resume.personal.phone);
    printf("Enter your address: ");
    scanf("%[^\n]", resume.personal.address);
    getchar();

    // Prompt user to enter work experience details
    printf("How many work experiences do you have? ");
    scanf("%d", &num_work_exp);
    getchar();
    for (int i = 0; i < num_work_exp; i++) {
        printf("\n- Work Experience %d -\n", i+1);
        printf("Enter the company name: ");
        scanf("%[^\n]", resume.work_experience[i].company);
        getchar();
        printf("Enter your designation: ");
        scanf("%[^\n]", resume.work_experience[i].designation);
        getchar();
        printf("Enter the start date (MM/DD/YYYY): ");
        scanf("%s", resume.work_experience[i].start_date);
        printf("Enter the end date (MM/DD/YYYY): ");
        scanf("%s", resume.work_experience[i].end_date);
        getchar();
    }

    // Prompt user to enter educational details
    printf("How many educational degrees do you have? ");
    scanf("%d", &num_education);
    getchar();
    for (int i = 0; i < num_education; i++) {
        printf("\n- Educational Degree %d -\n", i+1);
        printf("Enter the degree name: ");
        scanf("%[^\n]", resume.educational[i].degree);
        getchar();
        printf("Enter the college name: ");
        scanf("%[^\n]", resume.educational[i].college);
        getchar();
        printf("Enter the start date (MM/DD/YYYY): ");
        scanf("%s", resume.educational[i].start_date);
        printf("Enter the end date (MM/DD/YYYY): ");
        scanf("%s", resume.educational[i].end_date);
        getchar();
    }

    // Display the parsed details
    printf("\n- Personal Details -\n");
    printf("Name: %s\n", resume.personal.name);
    printf("Email: %s\n", resume.personal.email);
    printf("Phone: %s\n", resume.personal.phone);
    printf("Address: %s\n", resume.personal.address);
    printf("\n- Work Experience Details -\n");
    for (int i = 0; i < num_work_exp; i++) {
        printf("Company Name: %s\n", resume.work_experience[i].company);
        printf("Designation: %s\n", resume.work_experience[i].designation);
        printf("Start Date: %s\n", resume.work_experience[i].start_date);
        printf("End Date: %s\n", resume.work_experience[i].end_date);
    }
    printf("\n- Educational Details -\n");
    for (int i = 0; i < num_education; i++) {
        printf("Degree: %s\n", resume.educational[i].degree);
        printf("College: %s\n", resume.educational[i].college);
        printf("Start Date: %s\n", resume.educational[i].start_date);
        printf("End Date: %s\n", resume.educational[i].end_date);
    }

    return 0;
}