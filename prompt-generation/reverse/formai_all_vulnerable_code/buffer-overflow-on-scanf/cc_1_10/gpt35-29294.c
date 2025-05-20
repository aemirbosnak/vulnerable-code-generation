//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include<stdio.h>
#include<string.h>
#define MAX 50

struct info {
    char name[MAX];
    char email[MAX];
    char phone[MAX];
    char address[MAX];
    char skills[MAX];
    char education[MAX];
    char experience[MAX];
};

//function to parse the resume
void parseResume(char resume[]) {
    struct info applicant;
    FILE * fptr;
    fptr = fopen(resume, "r");
    if(fptr == NULL) {
        printf("File could not be opened\n");
        return;
    }
    char buffer[MAX];
    int i = 0;
    while(fgets(buffer, MAX, fptr) != NULL) {
        if(strstr(buffer, "Name")) {
            sscanf(buffer, "%*s %[^'\n']s", applicant.name);
        }
        else if(strstr(buffer, "Email")) {
            sscanf(buffer, "%*s %[^'\n']s", applicant.email);
        }
        else if(strstr(buffer, "Phone")) {
            sscanf(buffer, "%*s %[^'\n']s", applicant.phone);
        }
        else if(strstr(buffer, "Address")) {
            sscanf(buffer, "%*s %[^'\n']s", applicant.address);
        }
        else if(strstr(buffer, "Skills")) {
            sscanf(buffer, "%*s %[^'\n']s", applicant.skills);
        }
        else if(strstr(buffer, "Education")) {
            sscanf(buffer, "%*s %[^'\n']s", applicant.education);
        }
        else if(strstr(buffer, "Experience")) {
            sscanf(buffer, "%*s %[^'\n']s", applicant.experience);
        }
    }
    fclose(fptr);

    printf("Name: %s\n", applicant.name);
    printf("Email: %s\n", applicant.email);
    printf("Phone: %s\n", applicant.phone);
    printf("Address: %s\n", applicant.address);
    printf("Skills: %s\n", applicant.skills);
    printf("Education: %s\n", applicant.education);
    printf("Experience: %s\n", applicant.experience);
}

int main() {
    char resume[MAX];
    printf("Enter the name of the resume file: ");
    scanf("%s", resume);
    parseResume(resume);
    return 0;
}