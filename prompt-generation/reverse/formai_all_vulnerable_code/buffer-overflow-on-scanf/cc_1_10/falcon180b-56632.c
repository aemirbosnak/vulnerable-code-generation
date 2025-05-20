//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char name[100];
    char address[200];
    char phone[20];
    char email[50];
    char education[200];
    char experience[500];
} Resume;

void getResume(Resume *resume) {
    printf("Enter your name: ");
    scanf("%s", resume->name);

    printf("Enter your address: ");
    scanf("%s", resume->address);

    printf("Enter your phone number: ");
    scanf("%s", resume->phone);

    printf("Enter your email address: ");
    scanf("%s", resume->email);

    printf("Enter your education: ");
    scanf("%s", resume->education);

    printf("Enter your experience: ");
    scanf("%s", resume->experience);
}

void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

int main() {
    Resume resume;

    getResume(&resume);

    printResume(resume);

    return 0;
}