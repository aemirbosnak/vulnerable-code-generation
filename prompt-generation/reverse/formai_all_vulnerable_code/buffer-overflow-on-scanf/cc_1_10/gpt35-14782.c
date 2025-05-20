//FormAI DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

// structure of the student details
struct student{
    char name[50];
    int roll_no;
    int marks;
};

int main(){

    // declaring variables
    int n, i, j, choice;
    char password[50], admin_password[] = "1234";
    int total_marks = 0, highest_marks = -1, lowest_marks = 101;
    float average_marks;

    // asking for the number of students and creating an array of student details
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student students[n];

    // asking for the password to start the examination
    printf("Enter the password to start the examination: ");
    scanf("%s", password);

    // checking the password and giving access to start the examination
    if(strcmp(password, admin_password) != 0){
        printf("Incorrect password. Please try again.\n");
    }
    else{
        // asking for the details of each student
        for(i=0; i<n; i++){
            printf("\nEnter the details of student %d:\n", i+1);
            printf("Name: ");
            scanf("%s", students[i].name);
            printf("Roll Number: ");
            scanf("%d", &students[i].roll_no);
            students[i].marks = -1; // initialising the marks as -1
        }

        // giving instructions to the student
        printf("\n\nINSTRUCTIONS:\n");
        printf("1. The exam contains 10 multiple choice questions\n");
        printf("2. Each question carries 10 marks\n");
        printf("3. Negative marking of -1 for each wrong answer\n");
        printf("4. Enter the option number (1, 2, 3 or 4) of the correct answer\n");
        printf("5. Enter -1 if you do not know the answer\n");
        printf("6. You have 1 hour to complete the exam\n");

        // starting the examination and asking the questions
        printf("\n\nSTARTING THE EXAMINATION:\n");
        for(i=0; i<n; i++){
            printf("\n\n%d. %s (Roll Number: %d)\n", i+1, students[i].name, students[i].roll_no);
            total_marks = 0;
            for(j=0; j<10; j++){
                printf("\nQ%d. What is the capital of India?\n", j+1);
                printf("1. New Delhi\n");
                printf("2. Kolkata\n");
                printf("3. Mumbai\n");
                printf("4. Chennai\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                // checking the answer and giving marks
                if(choice == 1){
                    students[i].marks += 10;
                    total_marks += 10;
                }
                else if(choice == -1){
                    // if student does not know the answer
                    students[i].marks += 0;
                    total_marks += 0;
                }
                else{
                    students[i].marks -= 1;
                    total_marks -= 1;
                }
            }
            printf("\n\nTotal Marks Obtained: %d\n", total_marks);
        }

        // displaying the results
        printf("\n\nRESULTS:\n");
        for(i=0; i<n; i++){
            printf("\n%d. %s (Roll Number: %d) - Marks: %d\n", i+1, students[i].name, students[i].roll_no, students[i].marks);
            if(students[i].marks > highest_marks){
                highest_marks = students[i].marks;
            }
            if(students[i].marks < lowest_marks){
                lowest_marks = students[i].marks;
            }
            average_marks += students[i].marks;
        }
        average_marks /= n;

        printf("\n\nHighest Marks: %d\n", highest_marks);
        printf("Lowest Marks: %d\n", lowest_marks);
        printf("Average Marks: %.2f\n", average_marks);

    }
    return 0;
}