//FormAI DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

struct student{
    char name[20];
    int roll;
    float cgpa;
};

int main(){

    struct student data[MAX_SIZE];
    int choice, n, i, flag, roll;
    char name[20];
    float cgpa;

    printf("Enter number of student records to be added:\n");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("\nStudent %d:\n", i+1);
        printf("Enter name:");
        scanf("%s", &data[i].name);
        printf("Enter roll number:");
        scanf("%d", &data[i].roll);
        printf("Enter CGPA:");
        scanf("%f", &data[i].cgpa);
    }

    printf("\n*** Database simulation program ***\n");
    printf("1. Search student record by name\n");
    printf("2. Search student record by roll number\n");
    printf("3. Display all student records\n");
    printf("4. Exit\n");

    do{
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice){
            
            case 1:{
                flag = 0;
                printf("\nEnter the name of student to search:");
                scanf("%s", &name);
                for(i=0; i<n; i++){
                    if(strcmp(data[i].name, name) == 0){
                        printf("\nRecord found for %s\n", data[i].name);
                        printf("Roll number:%d\n", data[i].roll);
                        printf("CGPA:%.2f\n", data[i].cgpa);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    printf("No record found for %s\n", name);
                }
                break;
            }

            case 2:{
                flag = 0;
                printf("\nEnter the roll number of student to search:");
                scanf("%d", &roll);
                for(i=0; i<n; i++){
                    if(data[i].roll == roll){
                        printf("\nRecord found for roll number %d\n", data[i].roll);
                        printf("Name:%s\n", data[i].name);
                        printf("CGPA:%.2f\n", data[i].cgpa);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    printf("No record found for roll number %d\n", roll);
                }
                break;
            }

            case 3:{
                printf("\nAll student records:\n");
                for(i=0; i<n; i++){
                    printf("\nStudent %d:\n", i+1);
                    printf("Name:%s\n", data[i].name);
                    printf("Roll number:%d\n", data[i].roll);
                    printf("CGPA:%.2f\n", data[i].cgpa);
                }
                break;
            }

            case 4:{
                printf("\nExiting the program\n");
                break;
            }

            default:{
                printf("\nInvalid choice. Please try again.\n");
            }

        }

    }while(choice != 4);

    return 0;

}