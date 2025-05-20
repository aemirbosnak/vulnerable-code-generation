//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_RECORDS 100

struct student{
    int roll_no;
    char name[50];
    float cgpa;
};

struct database{
    struct student data[MAX_RECORDS];
    int record_count;
};

void add_student(struct database* db){
    struct student s;
    printf("Enter Roll Number: ");
    scanf("%d",&s.roll_no);
    printf("Enter Name: ");
    scanf("%s",s.name);
    printf("Enter CGPA: ");
    scanf("%f",&s.cgpa);
    db->data[db->record_count++] = s;
    printf("Record Added Successfully.\n");
}

void delete_student(struct database* db){
    int roll_no,i,pos=-1;
    printf("Enter Roll Number: ");
    scanf("%d",&roll_no);
    for(i=0;i<db->record_count;i++){
        if(db->data[i].roll_no == roll_no){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        printf("Record Not Found.\n");
    }
    else{
        for(i=pos;i<db->record_count;i++){
            db->data[i] = db->data[i+1];
        }
        db->record_count--;
        printf("Record Deleted Successfully.\n");
    }
}

void modify_student(struct database* db){
    int roll_no,i,pos=-1;
    printf("Enter Roll Number: ");
    scanf("%d",&roll_no);
    for(i=0;i<db->record_count;i++){
        if(db->data[i].roll_no == roll_no){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        printf("Record Not Found.\n");
    }
    else{
        struct student s;
        printf("Enter New Name: ");
        scanf("%s",s.name);
        printf("Enter New CGPA: ");
        scanf("%f",&s.cgpa);
        db->data[pos] = s;
        printf("Record Modified Successfully.\n");
    }
}

void print_records(struct database* db){
    int i;
    if(db->record_count == 0){
        printf("No Records Found.\n");
    }
    else{
        printf("Roll No.\tName\tCGPA\n");
        printf("--------\t----\t----\n");
        for(i=0;i<db->record_count;i++){
            printf("%d\t\t%s\t%f\n",db->data[i].roll_no,db->data[i].name,db->data[i].cgpa);
        }
    }
}

int main(){
    struct database db;
    db.record_count = 0;
    int choice;
    printf("Welcome to Student Database Simulation Program.\n");
    do{
        printf("\nMenu:\n1. Add Student\n2. Delete Student\n3. Modify Student\n4. Print Records\n5. Exit\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_student(&db); break;
            case 2: delete_student(&db); break;
            case 3: modify_student(&db); break;
            case 4: print_records(&db); break;
            case 5: printf("Thank you for using our program.\n"); break;
            default: printf("Invalid Choice. Try Again.\n"); break;
        }
    }while(choice != 5);
    return 0;
}