//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Candidate {
    char name[50];
    char email[50];
    int phone;
    char degree[50];
    int experience;
    char skills[100];
};

int main() {
    FILE *fp;
    char filename[50], line[100];
    struct Candidate c[10];
    int i, j=0, count=0;
    
    printf("Enter file name: ");
    gets(filename);
    
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(0);
    }
    
    while(fgets(line, sizeof(line), fp)) {
        char *token;
        token = strtok(line, ",");
        i = 0;
        while(token != NULL) {
            switch(i) {
                case 0: strcpy(c[j].name, token);
                        break;
                case 1: strcpy(c[j].email, token);
                        break;
                case 2: c[j].phone = atoi(token);
                        break;
                case 3: strcpy(c[j].degree, token);
                        break;
                case 4: c[j].experience = atoi(token);
                        break;
                case 5: strcpy(c[j].skills, token);
                        break;
            }
            
            i++;
            token = strtok(NULL, ",");
        }
        j++;
        count++;
    }
    
    printf("\nTotal number of candidates: %d", count);
    
    for(i=0;i<count;i++) {
        printf("\n\nCandidate %d:", i+1);
        printf("\nName: %s", c[i].name);
        printf("\nEmail: %s", c[i].email);
        printf("\nPhone: %d", c[i].phone);
        printf("\nDegree: %s", c[i].degree);
        printf("\nExperience: %d years", c[i].experience);
        printf("\nSkills: %s", c[i].skills);
    }
    
    fclose(fp);
    
    return 0;
}