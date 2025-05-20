//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume{
    char name[50];
    char email[50];
    char education[200];
    char experience[500];
} Resume;

void parseResume(char* filename, Resume* res){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char line[1000];
    while(fgets(line, sizeof(line), fp)){
        if(strstr(line, "Name:")){
            sscanf(line, "Name: %[^\n]", res->name);
        }
        else if(strstr(line, "Email:")){
            sscanf(line, "Email: %[^\n]", res->email);
        }
        else if(strstr(line, "Education:")){
            sscanf(line, "Education: %[^\n]", res->education);
        }
        else if(strstr(line, "Experience:")){
            sscanf(line, "Experience: %[^\n]", res->experience);
        }
    }

    fclose(fp);
}

int main(){
    Resume myResume;
    char filename[50];
    printf("Enter resume filename: ");
    scanf("%s", filename);
    
    parseResume(filename, &myResume);

    printf("Name: %s\n", myResume.name);
    printf("Email: %s\n", myResume.email);
    printf("Education: %s\n", myResume.education);
    printf("Experience: %s\n", myResume.experience);

    return 0;
}