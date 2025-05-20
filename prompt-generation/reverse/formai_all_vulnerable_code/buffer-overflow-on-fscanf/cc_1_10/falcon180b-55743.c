//Falcon-180B DATASET v1.0 Category: File handling ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//Structure for student
struct student{
    int roll_no;
    char name[20];
    char course[20];
    float marks;
};

void main(){
    FILE *fp;
    struct student stu[MAX];
    int i,n;

    //Opening file in read mode
    fp = fopen("student.txt","r");

    //Checking if file is opened successfully
    if(fp==NULL){
        printf("Error in opening file");
        exit(0);
    }

    //Reading data from file
    for(i=0;i<MAX;i++){
        fscanf(fp,"%d %s %s %f",&stu[i].roll_no,stu[i].name,stu[i].course,&stu[i].marks);
    }

    //Closing file
    fclose(fp);

    //Sorting students based on marks in descending order
    for(i=0;i<MAX-1;i++){
        for(n=i+1;n<MAX;n++){
            if(stu[i].marks<stu[n].marks){
                struct student temp;
                temp = stu[i];
                stu[i] = stu[n];
                stu[n] = temp;
            }
        }
    }

    //Writing sorted data to a new file
    fp = fopen("sorted_student.txt","w");

    //Checking if file is opened successfully
    if(fp==NULL){
        printf("Error in opening file");
        exit(0);
    }

    //Writing data to file
    for(i=0;i<MAX;i++){
        fprintf(fp,"%d %s %s %f\n",stu[i].roll_no,stu[i].name,stu[i].course,stu[i].marks);
    }

    //Closing file
    fclose(fp);

    printf("Data sorted and written to file successfully");
}