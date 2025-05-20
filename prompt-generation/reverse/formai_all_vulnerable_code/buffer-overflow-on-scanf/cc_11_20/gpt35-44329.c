//FormAI DATASET v1.0 Category: Database simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int id;
    char name[20];
    char department[20];
    float cgpa;
};

int main(){
    int choice,count=0,i=0,n;
    struct student s[20];

    printf("\nWelcome to the Student Database Simulation Program \n");

    while(1){ // keep running the program until the user exits
        printf("\nPlease select one of the following options:\n");
        printf("1. Add a new student\n");
        printf("2. Search for a student\n");
        printf("3. Update student data\n");
        printf("4. Delete a student record\n");
        printf("5. Display all students\n");
        printf("6. Exit\n");

        scanf("%d",&choice);

        switch(choice){

            case 1: // add a new student record
                printf("\nEnter the following details of the student:\n");
                printf("ID: ");
                scanf("%d",&s[count].id);
                printf("Name: ");
                scanf("%s",&s[count].name);
                printf("Department: ");
                scanf("%s",&s[count].department);
                printf("CGPA: ");
                scanf("%f",&s[count].cgpa);
                count++;
                break;

            case 2: // search for a student record
                printf("\nEnter the ID of the student you want to search: ");
                int search_id;
                scanf("%d",&search_id);
                for(i=0;i<count;i++){
                    if(s[i].id==search_id){
                        printf("\nStudent found!\n");
                        printf("ID: %d\n",s[i].id);
                        printf("Name: %s\n",s[i].name);
                        printf("Department: %s\n",s[i].department);
                        printf("CGPA: %f\n",s[i].cgpa);
                        break;
                    }
                }

                if(i==count){
                    printf("\nStudent not found!\n");
                }
                break;

            case 3: // update a student record
                printf("\nEnter the ID of the student you want to update: ");
                int update_id;
                scanf("%d",&update_id);
                for(i=0;i<count;i++){
                    if(s[i].id==update_id){
                        printf("\nStudent found! Enter new details:\n");
                        printf("Name: ");
                        scanf("%s",&s[i].name);
                        printf("Department: ");
                        scanf("%s",&s[i].department);
                        printf("CGPA: ");
                        scanf("%f",&s[i].cgpa);
                        break;
                    }
                }

                if(i==count){
                    printf("\nStudent not found!\n");
                }
                break;

            case 4: // delete a student record
                printf("\nEnter the ID of the student you want to delete: ");
                int delete_id;
                scanf("%d",&delete_id);
                for(i=0;i<count;i++){
                    if(s[i].id==delete_id){
                        printf("\nStudent found! Deleting record...\n");
                        for(int j=i;j<count-1;j++){
                            s[j]=s[j+1];
                        }
                        count--;
                        break;
                    }
                }
                if(i==count){
                    printf("\nStudent not found!\n");
                }
                break;

            case 5: // display all student records
                printf("\nDisplaying all student records:\n");
                for(i=0;i<count;i++){
                    printf("\n----------------------\n");
                    printf("ID: %d\n",s[i].id);
                    printf("Name: %s\n",s[i].name);
                    printf("Department: %s\n",s[i].department);
                    printf("CGPA: %f\n",s[i].cgpa);
                }
                printf("\n----------------------\n");
                break;

            case 6: //exiting the program
                printf("\nExiting the program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please choose a valid option.\n");
        }

    }

    return 0;
}