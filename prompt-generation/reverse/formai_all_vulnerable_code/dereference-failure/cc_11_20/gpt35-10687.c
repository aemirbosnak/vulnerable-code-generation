//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    int roll_no;
    char name[20];
    int score;
}STUDENT;

int main(){
    int choice;
    STUDENT *s;
    int num_of_students=0;
    printf("Enter the total number of students: ");
    scanf("%d",&num_of_students);

    s= (STUDENT*)malloc(num_of_students*sizeof(STUDENT));
    if(s==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    for(int i=0;i<num_of_students;i++){
        printf("\nEnter details of Student %d:",i+1);
        printf("\nEnter roll no: ");
        scanf("%d",&s[i].roll_no);
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter score: ");
        scanf("%d",&s[i].score);
    }

    do{
        printf("\nEnter your choice:\n1. Display all students\n2. Display students with score above 60\n3. Display students with score below 40\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("\nAll Students:\n");
                printf("Roll No\tName\tScore\n");
                for(int i=0;i<num_of_students;i++){
                    printf("%d\t%s\t%d\n",s[i].roll_no,s[i].name,s[i].score);
                }
                break;
            }
            case 2:{
                printf("\nStudents with score above 60:\n");
                printf("Roll No\tName\tScore\n");
                for(int i=0;i<num_of_students;i++){
                    if(s[i].score>60){
                        printf("%d\t%s\t%d\n",s[i].roll_no,s[i].name,s[i].score);
                    }
                }
                break;
            }
            case 3:{
                printf("\nStudents with score below 40:\n");
                printf("Roll No\tName\tScore\n");
                for(int i=0;i<num_of_students;i++){
                    if(s[i].score<40){
                        printf("%d\t%s\t%d\n",s[i].roll_no,s[i].name,s[i].score);
                    }
                }
                break;
            }
            case 4:{
                return 0;
            }
            default:{
                printf("Invalid Choice, Try Again!");
                continue;
            }
        }
    }while(1);
    return 0;
}