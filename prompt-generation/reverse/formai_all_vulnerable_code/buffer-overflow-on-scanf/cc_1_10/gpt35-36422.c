//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume{
    char name[50];
    char education[50];
    char experience[50];
    char skills[50];
};

void parseResume(char *filename){
    FILE *fp;
    char buffer[255];
    struct Resume resume;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Cannot open file %s.\n", filename);
        return;
    }

    while(fgets(buffer, 255, fp)){
        if(strstr(buffer, "Name:")){
            sscanf(buffer, "Name: %[^\n]", resume.name);
        } else if(strstr(buffer, "Education:")){
            sscanf(buffer, "Education: %[^\n]", resume.education);
        } else if(strstr(buffer, "Experience:")){
            sscanf(buffer, "Experience: %[^\n]", resume.experience);
        } else if(strstr(buffer, "Skills:")){
            sscanf(buffer, "Skills: %[^\n]", resume.skills);
        }
    }

    printf("Name: %s\n", resume.name);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);

    fclose(fp);
}

int main(){
    char filename[100];

    printf("Enter the filename of the resume: ");
    scanf("%s", filename);

    parseResume(filename);

    return 0;
}