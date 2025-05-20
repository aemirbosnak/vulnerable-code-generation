//FormAI DATASET v1.0 Category: Online Examination System ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    char name[20];
    int rollno;
    int marks;
}s[100];//structure to store student details

void addstudent(int n){
    int j;
    for(j=0;j<n;j++){
        printf("Enter the name of student %d :\n",j+1);
        scanf("%s",s[j].name);
        printf("Enter the rollno of student %d :\n",j+1);
        scanf("%d",&s[j].rollno);
        s[j].marks=0;//initializing marks to 0
    }
}

void displaystudent(int n){
    int j;
    printf("------------------------------------------------\n");
    printf("Roll No \t Name \t\t Marks \n");
    printf("------------------------------------------------\n");
    for(j=0;j<n;j++){
        printf("%d \t\t %s \t\t %d \n",s[j].rollno,s[j].name,s[j].marks);
    }
    printf("------------------------------------------------\n");
}

void exam(int n){
    int i,j,num,ans,marks=0;
    char filename[20];
    FILE *fptr;
    printf("Enter the number of students to take exam: ");
    scanf("%d",&num);
    printf("Enter the name of the quiz file: ");
    scanf("%s",filename);//input quiz file name
    strcat(filename,".txt");//adding file extension
    fptr=fopen(filename,"r");//opening quiz file
    if(fptr==NULL){
        printf("\n File not found.");
        return;
    }
    for(i=0;i<num;i++){
        marks=0;
        printf("*******Exam for %s begin*******\n",s[i].name);
        for(j=0;j<10;j++){//10 questions in the exam
            printf("%d. ",j+1);
            char question[100],op1[20],op2[20],op3[20],op4[20];
            fscanf(fptr,"%s",question);//reading question from file
            printf("%s\n",question);
            fscanf(fptr,"%s",op1);//reading option 1 from file
            printf("  (a) %s\n",op1);
            fscanf(fptr,"%s",op2);//reading option 2 from file
            printf("  (b) %s\n",op2);
            fscanf(fptr,"%s",op3);//reading option 3 from file
            printf("  (c) %s\n",op3);
            fscanf(fptr,"%s",op4);//reading option 4 from file
            printf("  (d) %s\n",op4);
            printf("Enter your answer: ");
            scanf("%d",&ans);
            if(ans==1)
                marks+=5;//5 marks for correct answer
            printf("\n");
        }
        s[i].marks=marks;//updating marks for the student
        printf("*******Exam for %s over*******\n",s[i].name);
    }
    fclose(fptr);//closing quiz file
}

void main(){
    int n,choice;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    do{
        printf("1. Add student \n2. Display students \n3. Conduct exam \n4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: addstudent(n); break;
            case 2: displaystudent(n); break;
            case 3: exam(n); break;
            default: printf("Invalid choice\n");
        }
    }while(choice!=4);
}