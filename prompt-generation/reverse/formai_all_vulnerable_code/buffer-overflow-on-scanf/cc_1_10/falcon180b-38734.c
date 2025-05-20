//Falcon-180B DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct student{
    char name[50];
    int age;
    char course[50];
    float grade;
};

void input(struct student s[]);
void display(struct student s[]);
void sort(struct student s[]);
void write_to_file(struct student s[]);
void read_from_file(struct student s[]);

int main(){
    struct student s[MAX];
    int choice,i;

    do{
        printf("\n1. Input student details\n2. Display student details\n3. Sort student details\n4. Write to file\n5. Read from file\n6. Exit");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                input(s);
                break;
            case 2:
                display(s);
                break;
            case 3:
                sort(s);
                break;
            case 4:
                write_to_file(s);
                break;
            case 5:
                read_from_file(s);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }while(choice!=6);

    return 0;
}

void input(struct student s[]){
    int i;

    for(i=0;i<MAX;i++){
        printf("\nEnter name: ");
        scanf("%s",s[i].name);

        printf("Enter age: ");
        scanf("%d",&s[i].age);

        printf("Enter course: ");
        scanf("%s",s[i].course);

        printf("Enter grade: ");
        scanf("%f",&s[i].grade);
    }
}

void display(struct student s[]){
    int i;

    for(i=0;i<MAX;i++){
        printf("\nName: %s",s[i].name);
        printf("\nAge: %d",s[i].age);
        printf("\nCourse: %s",s[i].course);
        printf("\nGrade: %.2f",s[i].grade);
        printf("\n");
    }
}

void sort(struct student s[]){
    int i,j;
    struct student temp;

    for(i=0;i<MAX-1;i++){
        for(j=i+1;j<MAX;j++){
            if(strcmp(s[i].name,s[j].name)>0){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}

void write_to_file(struct student s[]){
    FILE *fp;
    int i;

    fp=fopen("student_details.txt","w");

    if(fp==NULL){
        printf("Error in creating file!");
        exit(0);
    }

    for(i=0;i<MAX;i++){
        fprintf(fp,"%s %d %s %.2f\n",s[i].name,s[i].age,s[i].course,s[i].grade);
    }

    fclose(fp);
}

void read_from_file(struct student s[]){
    FILE *fp;
    char ch;
    int i=0;

    fp=fopen("student_details.txt","r");

    if(fp==NULL){
        printf("Error in opening file!");
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            i++;
        }
    }

    rewind(fp);

    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            fscanf(fp,"%s %d %s %.2f",s[i].name,&s[i].age,s[i].course,&s[i].grade);
            i++;
        }
    }

    fclose(fp);
}