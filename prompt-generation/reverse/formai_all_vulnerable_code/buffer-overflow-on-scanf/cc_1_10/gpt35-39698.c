//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int roll_no;
    char name[20];
    int age;
};

void add_student(){
    struct student s;
    FILE *fptr;
    fptr=fopen("students.txt","ab+");
    printf("Enter Roll No: ");
    scanf("%d",&s.roll_no);
    printf("Enter Name: ");
    scanf("%s",s.name);
    printf("Enter Age: ");
    scanf("%d",&s.age);
    fwrite(&s,sizeof(s),1,fptr);
    fclose(fptr);
}

void display_students(){
    struct student s;
    FILE *fptr;
    int count=0;
    fptr=fopen("students.txt","rb");
    if(fptr==NULL){
        printf("Error: File Not Found");
        return;
    }
    printf("%-10s%-20s%-10s\n","Roll No","Name","Age");
    while(fread(&s,sizeof(s),1,fptr)==1){
        printf("%-10d%-20s%-10d\n",s.roll_no,s.name,s.age);
        count++;
    }
    printf("Total Number of Students: %d\n",count);
    fclose(fptr);
}

void search_student(){
    struct student s;
    FILE *fptr;
    int roll_no, found=0;
    fptr=fopen("students.txt","rb");
    if(fptr==NULL){
        printf("Error: File Not Found");
        return;
    }
    printf("Enter Roll No: ");
    scanf("%d",&roll_no);
    while(fread(&s,sizeof(s),1,fptr)==1){
        if(s.roll_no==roll_no){
            printf("%-10s%-20s%-10s\n","Roll No","Name","Age");
            printf("%-10d%-20s%-10d\n",s.roll_no,s.name,s.age);
            found=1;
            break;
        }
    }
    if(!found){
        printf("Record not Found.\n");
    }
    fclose(fptr);
}

void delete_student(){
    struct student s;
    FILE *fptr1, *fptr2;
    int roll_no, found=0;
    printf("Enter Roll No: ");
    scanf("%d",&roll_no);
    fptr1=fopen("students.txt","rb");
    if(fptr1==NULL){
        printf("Error: File Not Found");
        return;
    }
    fptr2=fopen("temp.txt","wb");
    while(fread(&s,sizeof(s),1,fptr1)==1){
        if(s.roll_no!=roll_no){
            fwrite(&s,sizeof(s),1,fptr2);
        }else{
            found=1;
        }
    }
    if(!found){
        printf("Record not Found.\n");
    }else{
        printf("Record Deleted successfully.\n");
    }
    fclose(fptr1);
    fclose(fptr2);
    remove("students.txt");
    rename("temp.txt","students.txt");
}

int main(){
    int choice;
    do{
        printf("\n**** Student Database Management System ****\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }while(choice!=5);
    return 0;
}