//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct{
    char name[MAX_SIZE];
    int age;
    char gender[MAX_SIZE];
    int score;
}student;

student *create_student(char *name,int age,char *gender,int score){
    student *stu = (student *)malloc(sizeof(student));
    strcpy(stu->name,name);
    stu->age = age;
    strcpy(stu->gender,gender);
    stu->score = score;
    return stu;
}

void print_student(student *stu){
    printf("Name: %s\n",stu->name);
    printf("Age: %d\n",stu->age);
    printf("Gender: %s\n",stu->gender);
    printf("Score: %d\n",stu->score);
}

int compare_score(student *stu1,student *stu2){
    if(stu1->score > stu2->score)
        return -1;
    else if(stu1->score < stu2->score)
        return 1;
    else
        return 0;
}

int main(){
    int n,i,j;
    scanf("%d",&n);
    student **students = (student **)malloc(n * sizeof(student *));
    for(i=0;i<n;i++){
        students[i] = create_student("","", "",0);
        printf("Enter the name of student %d:\n",i+1);
        scanf("%s",students[i]->name);
        printf("Enter the age of student %s:\n",students[i]->name);
        scanf("%d",&students[i]->age);
        printf("Enter the gender of student %s:\n",students[i]->name);
        scanf("%s",students[i]->gender);
        printf("Enter the score of student %s:\n",students[i]->name);
        scanf("%d",&students[i]->score);
    }
    qsort(students,n,sizeof(student *),compare_score);
    printf("\nSorted by score in descending order:\n");
    for(i=0;i<n;i++){
        print_student(students[i]);
    }
    return 0;
}