//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to parse the resume
void parseResume(char *resume){
    //open the resume file in read mode
    FILE *fp;
    fp=fopen(resume,"r");
    if(fp==NULL){
        printf("Could not open file");
        exit(1);
    }

    char line [1000];
    int lineNumber = 0;
    while(fgets(line,sizeof(line),fp)!=NULL){
        lineNumber++;

        //check for name
        if(lineNumber==1){
            printf("Name : %s",line);
        }

        //check for email
        if(strstr(line,"@")){
            printf("Email : %s",line);
        }

        //check for mobile number
        if(strstr(line,"Mobile") || strstr(line,"Phone")){
            printf("Mobile Number : %s",line);
        }

        //check for education
        if(strstr(line,"Education")){
            printf("Education : %s",line);
        }

        //check for work experience
        if(strstr(line,"Experience") || strstr(line,"Career")){
            printf("Work Experience : %s",line);
        }

        //check for skills
        if(strstr(line,"Skills")){
            printf("Skills : %s",line);
        }
    }
    //close the resume file
    fclose(fp);
}

int main(){

    printf("Welcome to the Resume Parsing System\n");
    printf("\n");

    printf("Please enter the name of the resume file: ");
    char resume[50];
    scanf("%s",resume);
    printf("\n");

    //parse the resume
    parseResume(resume);

    return 0;
}