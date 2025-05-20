//FormAI DATASET v1.0 Category: Online Examination System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{  //structure for storing student data
    char name[20];
    int age;
    char gender;
    int roll_no;
    int marks[5]; //marks of each subject
    float total_marks;
    float percentage;
};

int main(){
    int no_of_students,i,j;
    printf("Enter the number of students: ");
    scanf("%d",&no_of_students);
    struct student s[no_of_students];
    for(i=0;i<no_of_students;i++){
        printf("\nEnter details of student %d\n",i+1);
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter age: ");
        scanf("%d",&s[i].age);
        printf("Enter gender (M/F): ");
        scanf(" %c",&s[i].gender);
        printf("Enter roll number: ");
        scanf("%d",&s[i].roll_no);
        for(j=0;j<5;j++){ //loop to enter marks of each subject
            printf("Enter marks of subject %d: ",j+1);
            scanf("%d",&s[i].marks[j]);
            s[i].total_marks += s[i].marks[j]; //calculate total marks
        }
        s[i].percentage = s[i].total_marks/5; //calculate percentage
    }

    //Printing examination results
    printf("\n\nExamination Results\n");
    for(i=0;i<no_of_students;i++){
        printf("\nName: %s\n",s[i].name);
        printf("Age: %d\n",s[i].age);
        printf("Gender: %c\n",s[i].gender);
        printf("Roll Number: %d\n",s[i].roll_no);
        for(j=0;j<5;j++){
            printf("Marks of subject %d: %d\n",j+1,s[i].marks[j]);
        }
        printf("Total Marks: %.2f\n",s[i].total_marks);
        printf("Percentage: %.2f%%\n",s[i].percentage);
    }
    return 0;
}