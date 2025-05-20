//Falcon-180B DATASET v1.0 Category: File handling ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct student{
    char name[50];
    int roll_no;
    float marks;
};

void main(){
    FILE *fp;
    char ch;
    int i=0,j;
    struct student stu[MAX];

    fp=fopen("student.dat","wb");

    if(fp==NULL){
        printf("Error in opening file\n");
        exit(0);
    }

    printf("Enter number of students: ");
    scanf("%d",&i);

    printf("Enter student details:\n");

    for(j=0;j<i;j++){
        printf("Enter name: ");
        scanf("%s",stu[j].name);

        printf("Enter roll number: ");
        scanf("%d",&stu[j].roll_no);

        printf("Enter marks: ");
        scanf("%f",&stu[j].marks);
    }

    fwrite(stu,sizeof(stu[0]),i,fp);

    fclose(fp);

    fp=fopen("student.dat","rb");

    if(fp==NULL){
        printf("Error in opening file\n");
        exit(0);
    }

    printf("Student details:\n");

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