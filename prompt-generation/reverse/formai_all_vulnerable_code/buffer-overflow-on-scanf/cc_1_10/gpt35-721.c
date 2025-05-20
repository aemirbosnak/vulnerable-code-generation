//FormAI DATASET v1.0 Category: File handling ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int roll;
    char name[20];
    float cgpa;
};

void addStudentRecord(){
    FILE *fp;
    struct student s;
    fp = fopen("Students.txt","a");
    printf("\nEnter the Roll Number of the Student: ");
    scanf("%d",&s.roll);
    printf("\nEnter the Name of the Student: ");
    scanf("%s",s.name);
    printf("\nEnter the CGPA of the Student: ");
    scanf("%f",&s.cgpa);
    fprintf(fp,"%d\t%s\t%f\n",s.roll,s.name,s.cgpa);
    printf("\nStudent Record Added Successfully!\n");
    fclose(fp);
}

void displayStudentRecord(){
    FILE *fp;
    struct student s;
    fp = fopen("Students.txt","r");
    printf("\n\tRoll Number\tName\t\tCGPA\n");
    while(fscanf(fp,"%d %s %f",&s.roll,&s.name,&s.cgpa)!=EOF){
        printf("\n\t%d\t\t%s\t\t%.2f",s.roll,s.name,s.cgpa);
    }
    printf("\n");
    fclose(fp);
}

void searchStudentRecord(){
    FILE *fp;
    struct student s;
    int roll, flag = 0;
    fp = fopen("Students.txt","r");
    printf("\nEnter the Roll Number to Search: ");
    scanf("%d",&roll);
    while(fscanf(fp,"%d %s %f",&s.roll,&s.name,&s.cgpa)!=EOF){
        if(s.roll == roll){
            printf("\n\tRoll Number\tName\t\tCGPA\n");
            printf("\n\t%d\t\t%s\t\t%.2f",s.roll,s.name,s.cgpa);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("\nRecord Not Found!\n");
    }
    fclose(fp);
}

void deleteStudentRecord(){
    FILE *fp, *fp1;
    struct student s;
    int roll, flag = 0;
    fp = fopen("Students.txt","r");
    fp1 = fopen("temp.txt","w");
    printf("\nEnter the Roll Number to Delete: ");
    scanf("%d",&roll);
    while(fscanf(fp,"%d %s %f",&s.roll,&s.name,&s.cgpa)!=EOF){
        if(s.roll != roll){
            fprintf(fp1,"%d\t%s\t%f\n",s.roll,s.name,s.cgpa);
        }
        else{
            flag = 1;
        }
    }
    if(flag == 1){
        printf("\nStudent Record Deleted Successfully!\n");
    }
    else{
        printf("\nRecord Not Found!\n");
    }
    fclose(fp);
    fclose(fp1);
    remove("Students.txt");
    rename("temp.txt","Students.txt");
}

int main(){
    int option;
    printf("\n\t\t***** Welcome to the Student Record Management System *****\n");
    while(1){
        printf("\nChoose an Option:\n");
        printf("\n1. Add Student Record\n2. Display All Student Records\n3. Search Student Record\n4. Delete Student Record\n5. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&option);
        switch(option){
            case 1: addStudentRecord();
                    break;
            case 2: displayStudentRecord();
                    break;
            case 3: searchStudentRecord();
                    break;
            case 4: deleteStudentRecord();
                    break;
            case 5: exit(0);
            default: printf("\nInvalid Choice, Try Again!\n");
        }
    }
    return 0;
}