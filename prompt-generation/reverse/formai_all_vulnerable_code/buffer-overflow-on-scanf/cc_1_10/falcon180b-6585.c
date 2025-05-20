//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct student{
    char name[MAX];
    int roll;
    int marks[5];
    float percentage;
};

void main(){
    int n,i,j;
    struct student s[MAX];
    char ch;
    FILE *fp;

    printf("Enter the number of students: ");
    scanf("%d",&n);

    printf("\nEnter the details of %d students:\n",n);

    for(i=0;i<n;i++){
        printf("\nFor student %d:\n",i+1);
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter roll number: ");
        scanf("%d",&s[i].roll);

        for(j=0;j<5;j++){
            printf("Enter marks for subject %d: ",j+1);
            scanf("%d",&s[i].marks[j]);
        }

        s[i].percentage=0;

        for(j=0;j<5;j++){
            s[i].percentage+=s[i].marks[j];
        }

        s[i].percentage/=5;
    }

    printf("\n\nEnter the filename to store the details: ");
    scanf("%s",ch);

    fp=fopen(ch,"w");

    if(fp==NULL){
        printf("Error in opening file");
        exit(0);
    }

    for(i=0;i<n;i++){
        fprintf(fp,"%s\t%d\t",s[i].name,s[i].roll);

        for(j=0;j<5;j++){
            fprintf(fp,"%d\t",s[i].marks[j]);
        }

        fprintf(fp,"\n");
    }

    fclose(fp);

    printf("\nDetails saved in file %s",ch);

    exit(0);
}