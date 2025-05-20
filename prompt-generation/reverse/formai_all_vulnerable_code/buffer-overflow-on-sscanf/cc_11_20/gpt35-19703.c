//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct experience {
    char job_title[30];
    char company[50]; 
    char start_date[20];
    char end_date[20]; 
};

struct education {
    char degree[50];
    char institution[50];
    char start_date[20];
    char end_date[20];
};

struct resume {
    char name[50];
    char email[50];
    char phone[15];
    int num_experiences;
    struct experience experiences[10];
    int num_educations;
    struct education educations[10];
};

void parse_resume(char *filename, struct resume *r) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file");
        exit(1);
    }
    char line[200];
    int line_count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        line_count++;
        if (line_count == 1) {
            sscanf(line, "%[^\n]s", r->name);
        } else if (line_count == 2) {
            sscanf(line, "%[^\n]s", r->email);
        } else if (line_count == 3) {
            sscanf(line, "%[^\n]s", r->phone);
        } else if (strstr(line, "EXPERIENCE") != NULL) {
            int num_experiences = 0;
            while (fgets(line, sizeof(line), fp) != NULL) {
                if (line[0] == '-') {
                    num_experiences++;
                    sscanf(line, "- %[^\n]s", r->experiences[num_experiences-1].job_title);
                } else if (line[0] == '\t') {
                    if (strstr(line, "Company") != NULL) {
                        sscanf(line, "\tCompany: %[^\n]s", r->experiences[num_experiences-1].company);
                    } else if (strstr(line, "Start Date") != NULL) {
                        sscanf(line, "\tStart Date: %[^\n]s", r->experiences[num_experiences-1].start_date);
                    } else if (strstr(line, "End Date") != NULL) {
                        sscanf(line, "\tEnd Date: %[^\n]s", r->experiences[num_experiences-1].end_date);
                    }
                } else if (line[0] == '\n') {
                    break;
                } else {
                    printf("Error: invalid experience format\nLine: %s", line);
                    exit(1);
                }
            }
            r->num_experiences = num_experiences;
        } else if (strstr(line, "EDUCATION") != NULL) {
            int num_educations = 0;
            while (fgets(line, sizeof(line), fp) != NULL) {
                if (line[0] == '-') {
                    num_educations++;
                    sscanf(line, "- %[^\n]s", r->educations[num_educations-1].degree);
                } else if (line[0] == '\t') {
                    if (strstr(line, "Institution") != NULL) {
                        sscanf(line, "\tInstitution: %[^\n]s", r->educations[num_educations-1].institution);
                    } else if (strstr(line, "Start Date") != NULL) {
                        sscanf(line, "\tStart Date: %[^\n]s", r->educations[num_educations-1].start_date);
                    } else if (strstr(line, "End Date") != NULL) {
                        sscanf(line, "\tEnd Date: %[^\n]s", r->educations[num_educations-1].end_date);
                    }
                } else if (line[0] == '\n') {
                    break;
                } else {
                    printf("Error: invalid education format\nLine: %s", line);
                    exit(1);
                }
            }
            r->num_educations = num_educations;
        }
    }
    fclose(fp);
}

int main() {
    struct resume r;
    parse_resume("resume.txt", &r);
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("EXPERIENCE:\n");
    for (int i=0; i<r.num_experiences; i++) {
        printf("- %s\n", r.experiences[i].job_title);
        printf("\tCompany: %s\n", r.experiences[i].company);
        printf("\tStart Date: %s\n", r.experiences[i].start_date);
        printf("\tEnd Date: %s\n", r.experiences[i].end_date);
    }
    printf("EDUCATION:\n");
    for (int i=0; i<r.num_educations; i++) {
        printf("- %s\n", r.educations[i].degree);
        printf("\tInstitution: %s\n", r.educations[i].institution);
        printf("\tStart Date: %s\n", r.educations[i].start_date);
        printf("\tEnd Date: %s\n", r.educations[i].end_date);
    }
    return 0;
}