//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

struct student{
    char name[50];
    int roll;
    int marks[5];
};

struct question{
    char ques[100];
    int ans;
};

void main(){
    int n,m,i,j,k,l,sum=0;
    char ch;
    struct student s[MAX];
    struct question q[MAX];

    printf("Enter the number of questions:");
    scanf("%d",&m);

    printf("Enter the number of students:");
    scanf("%d",&n);

    for(i=0;i<m;i++){
        printf("Enter question %d:",i+1);
        scanf("%s",q[i].ques);
        printf("Enter the answer:");
        scanf("%d",&q[i].ans);
    }

    for(i=0;i<n;i++){
        printf("Enter the name of student %d:",i+1);
        scanf("%s",s[i].name);
        printf("Enter the roll number:");
        scanf("%d",&s[i].roll);

        for(j=0;j<m;j++){
            printf("Enter marks for question %d:",j+1);
            scanf("%d",&s[i].marks[j]);
        }
    }

    printf("Enter the minimum passing marks:");
    scanf("%d",&k);

    for(i=0;i<n;i++){
        sum=0;

        for(j=0;j<m;j++){
            sum+=s[i].marks[j];
        }

        if(sum>=k){
            printf("\nStudent %s with roll number %d has passed with %d marks\n",s[i].name,s[i].roll,sum);
        }
        else{
            printf("\nStudent %s with roll number %d has failed with %d marks\n",s[i].name,s[i].roll,sum);
        }
    }
}