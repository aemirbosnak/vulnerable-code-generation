//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[100];
    char phone[15];
    char education[100];
    char work_exp[500];
    char skills[500];
};

// Function to read resume data from a file and store it in a struct array
int read_resumes_from_file(struct Resume* resume_array, char* filename, int max_resumes) {
    FILE* fp;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        return 0;
    }

    while (i < max_resumes && fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", resume_array[i].name, resume_array[i].email,
                                       resume_array[i].phone, resume_array[i].education, resume_array[i].work_exp,
                                       resume_array[i].skills) == 6) {
        i++;
    }

    fclose(fp);
    return i;
}

// Function to parse resumes and print out selected information
void parse_resumes(struct Resume* resume_array, int num_resumes) {
    int i;
    for (i = 0; i < num_resumes; i++) {
        printf("Name   : %s\n", resume_array[i].name);
        printf("Email  : %s\n", resume_array[i].email);
        printf("Phone  : %s\n", resume_array[i].phone);
        printf("Education  : %s\n", resume_array[i].education);
        printf("Work Exp.  : %s\n", resume_array[i].work_exp);
        printf("Skills : %s\n", resume_array[i].skills);
        printf("\n");
    }
}

int main() {
    int max_resumes = 5;
    struct Resume* resume_array = malloc(max_resumes * sizeof(struct Resume));

    // Read resumes from file
    char* filename = "resume_data.csv";
    int num_resumes = read_resumes_from_file(resume_array, filename, max_resumes);

    // Parse resumes and print out information
    parse_resumes(resume_array, num_resumes);

    free(resume_array);
    return 0;
}