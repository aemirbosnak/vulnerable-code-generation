//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

struct Education {
    char degree[50];
    char institution[100];
    int year_of_passing;
    float percentage;
};

struct Experience {
    char company[100];
    char designation[50];
    int year_of_joining;
    int year_of_leaving;
};

struct Resume {
    char name[100];
    char email[100];
    char contact_number[20];
    char address[200];
    char skills[200];
    struct Education education[3];   // struct array to store education details
    struct Experience experience[5]; // struct array to store experience details
};

void parse_resume(struct Resume *res) {
    printf("\t\tRESUME PARSING SYSTEM\n\n");
    printf("Enter your name: ");
    fgets(res->name, 100, stdin);
    printf("Enter your email: ");
    fgets(res->email, 100, stdin);
    printf("Enter your contact number: ");
    fgets(res->contact_number, 20, stdin);
    printf("Enter your address: ");
    fgets(res->address, 200, stdin);
    printf("Enter your skills: ");
    fgets(res->skills, 200, stdin);

    // Parse Education Details
    printf("\nEnter your education details:\n");
    for(int i=0; i<3; i++) {
        printf("Enter your degree: ");
        fgets(res->education[i].degree, 50, stdin);
        printf("Enter the institution: ");
        fgets(res->education[i].institution, 100, stdin);
        printf("Enter year of passing: ");
        scanf("%d", &res->education[i].year_of_passing);
        printf("Enter percentage: ");
        scanf("%f", &res->education[i].percentage);
        getchar(); // get rid of the newline character
    }

    // Parse Experience Details
    printf("\nEnter your experience details:\n");
    int count = 0;
    while(count < 5) {
        printf("Enter company name (or 'quit' to exit): ");
        fgets(res->experience[count].company, 100, stdin);
        if(strcmp(res->experience[count].company, "quit\n") == 0) // check if user wants to quit
            break;
        printf("Enter your designation: ");
        fgets(res->experience[count].designation, 50, stdin);
        printf("Enter year of joining: ");
        scanf("%d", &res->experience[count].year_of_joining);
        printf("Enter year of leaving (or 0 if still working): ");
        scanf("%d", &res->experience[count].year_of_leaving);
        getchar(); // get rid of the newline character
        count++;
    }
}

void print_resume(struct Resume *res) {
    printf("\n\t\tRESUME\n\n");
    printf("Name: %s", res->name);
    printf("Email: %s", res->email);
    printf("Contact Number: %s", res->contact_number);
    printf("Address: %s", res->address);
    printf("Skills: %s", res->skills);

    printf("\nEducation Details:\n");
    for(int i=0; i<3; i++) {
        printf("Degree: %s", res->education[i].degree);
        printf("Institution: %s", res->education[i].institution);
        printf("Passing Year: %d\n", res->education[i].year_of_passing);
        printf("Percentage: %.2f\n\n", res->education[i].percentage);
    }

    printf("Experience Details:\n");
    int count = 0;
    while(count < 5 && strcmp(res->experience[count].company, "\n") != 0) {
        printf("Company: %s", res->experience[count].company);
        printf("Designation: %s", res->experience[count].designation);
        printf("Year of joining: %d\n", res->experience[count].year_of_joining);
        if(res->experience[count].year_of_leaving == 0)
            printf("Year of leaving: Still working\n\n");
        else
            printf("Year of leaving: %d\n\n", res->experience[count].year_of_leaving);
        count++;
    }
}

int main() {
    struct Resume resume;
    parse_resume(&resume);
    print_resume(&resume);
    return 0;
}