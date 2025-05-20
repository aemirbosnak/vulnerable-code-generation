//Falcon-180B DATASET v1.0 Category: File handling ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct student{
    char name[50];
    int age;
    char course[30];
    float marks;
};

void main(){
    FILE *fp;
    struct student s[MAX];
    int i,n,ch;
    
    printf("Enter the number of students: ");
    scanf("%d",&n);
    
    fp=fopen("students.txt","wb");
    
    if(fp==NULL){
        printf("Error in opening file.\n");
        exit(0);
    }
    
    printf("Enter the details of %d students:\n",n);
    
    for(i=0;i<n;i++){
        printf("\nFor student %d:\n",i+1);
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter age: ");
        scanf("%d",&s[i].age);
        printf("Enter course: ");
        scanf("%s",s[i].course);
        printf("Enter marks: ");
        scanf("%f",&s[i].marks);
    }
    
    for(i=0;i<n;i++){
        fprintf(fp,"%s\t%d\t%s\t%.2f\n",s[i].name,s[i].age,s[i].course,s[i].marks);
    }
    
    fclose(fp);
    
    printf("\nThe details have been saved in students.txt.\n");
    
    fp=fopen("students.txt","r");
    
    if(fp==NULL){
        printf("Error in opening file.\n");
        exit(0);
    }
    
    printf("\nThe details of students are:\n");
    
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