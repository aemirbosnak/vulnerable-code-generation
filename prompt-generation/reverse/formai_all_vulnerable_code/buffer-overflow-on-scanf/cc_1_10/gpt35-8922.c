//FormAI DATASET v1.0 Category: Database querying ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int roll_no;
    char name[50];
    float cgpa;
};

int main(){
    FILE *fp;
    struct student s[10];
    int i, j;
    int menu_choice = 0;
    int roll_no_search = -1;

    fp = fopen("student_db.dat","rb");
    if(fp == NULL){
        printf("Unable to open file\n");
        exit(1);
    }

    fread(s,sizeof(struct student),10,fp);

    while(menu_choice != 3){
        printf("\n=======================\n");
        printf("Menu\n");
        printf("1. Search by Roll Number\n");
        printf("2. List all students\n");
        printf("3. Exit\n");
        printf("=======================\n");
        printf("Enter choice: ");
        scanf("%d",&menu_choice);

        switch(menu_choice){
            case 1:
                printf("Enter Roll Number to search for: ");
                scanf("%d",&roll_no_search);
                for(i=0;i<10;i++){
                    if(s[i].roll_no == roll_no_search){
                        printf("\nRoll Number: %d\nName: %s\nCGPA: %f\n",s[i].roll_no,s[i].name,s[i].cgpa);
                        break;
                    }
                }
                if(i==10){
                    printf("\nStudent not found\n");
                }
                break;
            case 2:
                for(i=0;i<10;i++){
                    printf("\nRoll Number: %d\nName: %s\nCGPA: %f\n",s[i].roll_no,s[i].name,s[i].cgpa);
                }
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    fclose(fp);

    return 0;
}