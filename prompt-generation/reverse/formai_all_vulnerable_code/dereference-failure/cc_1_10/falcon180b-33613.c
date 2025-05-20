//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 64
#define MAX_RESUME_LEN 100000

typedef struct {
    char name[MAX_WORD_LEN];
    char email[MAX_WORD_LEN];
    char phone[MAX_WORD_LEN];
    char address[MAX_LINE_LEN];
    char education[MAX_LINE_LEN];
    char experience[MAX_LINE_LEN];
} Resume;

Resume* parseResume(FILE* fp) {
    Resume* resume = (Resume*)malloc(sizeof(Resume));
    char line[MAX_LINE_LEN];
    char* word;
    int i = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (i == 0) {
            strcpy(resume->name, line);
        } else if (i == 1) {
            strcpy(resume->email, line);
        } else if (i == 2) {
            strcpy(resume->phone, line);
        } else if (i == 3) {
            strcpy(resume->address, line);
        } else if (i == 4) {
            strcpy(resume->education, line);
        } else if (i == 5) {
            strcpy(resume->experience, line);
        }
        i++;
    }

    return resume;
}

void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

int main(int argc, char* argv[]) {
    FILE* fp;
    Resume* resume;

    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    resume = parseResume(fp);
    printResume(resume);

    free(resume);
    fclose(fp);

    return 0;
}