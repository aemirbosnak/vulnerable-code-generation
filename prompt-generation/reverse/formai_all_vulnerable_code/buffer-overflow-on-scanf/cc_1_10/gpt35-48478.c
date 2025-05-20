//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

//Define the struct of student
struct student{
    char name[50];
    int age;
    float gpa;
};

void printStudent(struct student s){

    printf("\nStudent Name: %s", s.name);
    printf("\nStudent Age: %d", s.age);
    printf("\nStudent GPA: %f", s.gpa);
}

int main(){

    int i, n;

    //Prompt the user for number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    //Allocate memory dynamically
    struct student *p = (struct student*)malloc(n*sizeof(struct student));

    //Use for-loop to get student information
    for(i=0;i<n;i++){

        printf("\nEnter the information of student %d", i+1);

        printf("\nName: ");
        scanf("%s", (p+i)->name);

        printf("Age: ");
        scanf("%d", &(p+i)->age);

        printf("GPA: ");
        scanf("%f", &(p+i)->gpa);
    }

    //Print student information
    printf("\n============Student Information============\n");

    for(i=0;i<n;i++){

        printf("\nInformation of student %d\n", i+1);
        printStudent(*(p+i));
    }

    //Free allocated memory
    free(p);

    return 0;
}