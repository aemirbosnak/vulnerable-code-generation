//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_SIZE 1000

typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char education[100];
    char experience[200];
} Resume;

Resume* createResume() {
    Resume* r = (Resume*)malloc(sizeof(Resume));
    strcpy(r->name, "");
    strcpy(r->email, "");
    strcpy(r->phone, "");
    strcpy(r->address, "");
    strcpy(r->education, "");
    strcpy(r->experience, "");
    return r;
}

void readResume(Resume* r, FILE* f) {
    char line[MAX_RESUME_SIZE];
    while (fgets(line, MAX_RESUME_SIZE, f)!= NULL) {
        if (strstr(line, "Name:")!= NULL) {
            strcpy(r->name, strtok(line, ":"));
        } else if (strstr(line, "Email:")!= NULL) {
            strcpy(r->email, strtok(line, ":"));
        } else if (strstr(line, "Phone:")!= NULL) {
            strcpy(r->phone, strtok(line, ":"));
        } else if (strstr(line, "Address:")!= NULL) {
            strcpy(r->address, strtok(line, ":"));
        } else if (strstr(line, "Education:")!= NULL) {
            strcpy(r->education, strtok(line, ":"));
        } else if (strstr(line, "Experience:")!= NULL) {
            strcpy(r->experience, strtok(line, ":"));
        }
    }
}

void printResume(Resume* r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Education: %s\n", r->education);
    printf("Experience: %s\n", r->experience);
}

int main() {
    FILE* f = fopen("resume.txt", "r");
    if (f == NULL) {
        printf("Cannot open resume file.\n");
        return 1;
    }

    Resume* r = createResume();
    readResume(r, f);
    printResume(r);

    fclose(f);
    free(r);
    return 0;
}