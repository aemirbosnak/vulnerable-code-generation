//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct student{
    char name[30];
    int rollno;
    float marks[5];
};

void main(){
    FILE *fp;
    struct student s[MAX];
    int i,j,n=0;
    char ch;

    fp=fopen("student.txt","a");
    if(fp==NULL){
        printf("File not found\n");
        exit(0);
    }

    printf("Enter the number of students:\n");
    scanf("%d",&n);

    printf("Enter the details of %d students:\n",n);

    for(i=0;i<n;i++){
        printf("Enter name of student %d:\n",i+1);
        scanf("%s",s[i].name);

        printf("Enter roll no of student %d:\n",i+1);
        scanf("%d",&s[i].rollno);

        printf("Enter marks of %s in subject 1:\n",s[i].name);
        scanf("%f",&s[i].marks[0]);

        printf("Enter marks of %s in subject 2:\n",s[i].name);
        scanf("%f",&s[i].marks[1]);

        printf("Enter marks of %s in subject 3:\n",s[i].name);
        scanf("%f",&s[i].marks[2]);

        printf("Enter marks of %s in subject 4:\n",s[i].name);
        scanf("%f",&s[i].marks[3]);

        printf("Enter marks of %s in subject 5:\n",s[i].name);
        scanf("%f",&s[i].marks[4]);
    }

    rewind(fp);

    printf("The details of students are:\n");

    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            printf("\n");
        }
        else{
            printf("%c",ch);
        }
    }

    fclose(fp);
}