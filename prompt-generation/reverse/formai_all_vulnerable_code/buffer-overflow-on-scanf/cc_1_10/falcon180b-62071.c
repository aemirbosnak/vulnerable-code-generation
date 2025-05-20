//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_SIZE 1000

typedef struct resume resume_t;

struct resume {
    char name[50];
    char email[100];
    char phone[20];
    char address[200];
    char summary[300];
    char experience[MAX_RESUME_SIZE];
    char education[MAX_RESUME_SIZE];
};

void read_resume(resume_t *resume) {
    printf("Enter your name: ");
    scanf("%s", resume->name);

    printf("Enter your email: ");
    scanf("%s", resume->email);

    printf("Enter your phone number: ");
    scanf("%s", resume->phone);

    printf("Enter your address: ");
    scanf("%s", resume->address);

    printf("Enter your summary: ");
    scanf("%s", resume->summary);

    printf("Enter your experience: ");
    scanf("%[^\n]s", resume->experience);

    printf("Enter your education: ");
    scanf("%[^\n]s", resume->education);
}

void print_resume(resume_t *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Summary: %s\n", resume->summary);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

int main() {
    resume_t resume;
    read_resume(&resume);
    print_resume(&resume);

    return 0;
}