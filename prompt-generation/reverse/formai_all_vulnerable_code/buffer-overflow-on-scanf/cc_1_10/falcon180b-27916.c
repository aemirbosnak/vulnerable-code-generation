//Falcon-180B DATASET v1.0 Category: File handling ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct student{
    int rollno;
    char name[50];
    float marks[5];
};

void main(){
    FILE *fp;
    int i,n,ch;
    char filename[20];

    printf("Enter the name of the file: ");
    scanf("%s",filename);

    fp=fopen(filename,"r");

    if(fp==NULL){
        printf("File does not exist\n");
        exit(0);
    }

    printf("Enter the number of records: ");
    scanf("%d",&n);

    struct student s[n];

    for(i=0;i<n;i++){
        fscanf(fp,"%d %s %f %f %f %f %f",&s[i].rollno,s[i].name,&s[i].marks[0],&s[i].marks[1],&s[i].marks[2],&s[i].marks[3],&s[i].marks[4]);
    }

    fclose(fp);

    printf("\nName\tRoll No.\tMarks\n");

    for(i=0;i<n;i++){
        printf("%s\t%d\t",s[i].name,s[i].rollno);

        for(ch=0;ch<5;ch++){
            printf("%f\t",s[i].marks[ch]);
        }

        printf("\n");
    }

    fp=fopen(filename,"w");

    if(fp==NULL){
        printf("File could not be opened\n");
        exit(0);
    }

    for(i=0;i<n;i++){
        fprintf(fp,"%d %s %f %f %f %f %f\n",s[i].rollno,s[i].name,s[i].marks[0],s[i].marks[1],s[i].marks[2],s[i].marks[3],s[i].marks[4]);
    }

    fclose(fp);

    printf("\nData written to file successfully\n");
}