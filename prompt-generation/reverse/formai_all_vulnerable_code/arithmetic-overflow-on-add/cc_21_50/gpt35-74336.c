//FormAI DATASET v1.0 Category: Online Examination System ; Style: configurable
#include<stdio.h>   // includes standard input and output functions
#include<stdlib.h>  // includes functions for dynamic memory allocation
#include<string.h>  // includes functions for string operations

// defining a structure for storing student record
struct student{
    char name[50];
    int rollno;
    int marks;
    char grade;
}stud[100];     // creating array of structure

int main(){
    int choice, n, i, j, roll, found, hmarks, lmarks, total, avgmarks;
    char ch, grade;

    do{
        printf("\n\t\t ONLINE EXAMINATION SYSTEM");
        printf("\n\t\t -------------------------");
        printf("\n\n\t 1. CREATE DATABASE OF STUDENTS");
        printf("\n\t 2. DISPLAY DATABASE");
        printf("\n\t 3. FIND STUDENT RECORD BY ROLL NUMBER");
        printf("\n\t 4. FIND HIGHEST AND LOWEST MARKS");
        printf("\n\t 5. FIND CLASS AVERAGE");
        printf("\n\t 6. EXIT FROM PROGRAM");
        printf("\n\n\t Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:         // to create database of students
                    printf("\n\n\t ENTER THE NUMBER OF STUDENTS: ");
                    scanf("%d", &n);

                    // input student details
                    for(i=0; i<n; i++){
                        printf("\n\t ENTER THE DETAILS OF STUDENT %d:", i+1);
                        printf("\n\t NAME: ");
                        scanf("%s", stud[i].name);
                        printf("\n\t ROLL NUMBER: ");
                        scanf("%d", &stud[i].rollno);
                        printf("\n\t MARKS (out of 100): ");
                        scanf("%d", &stud[i].marks);
                        total += stud[i].marks;     // calculating total marks
                    }

                    avgmarks = total/n;     // calculating average marks
                    printf("\n\n\t DATABASE CREATED SUCCESSFULLY!");
                    printf("\n\t TOTAL STUDENTS: %d", n);
                    printf("\n\t TOTAL MARKS: %d", total);
                    printf("\n\t AVERAGE MARKS: %d", avgmarks);
                    break;

            case 2:         // to display database of students
                    printf("\n\n\t STUDENT DATABASE");
                    printf("\n\t ----------------");
                    printf("\n\t NAME\t\tROLL NO\tMARKS\tGRADE");
                    printf("\n\t ----\t\t-------\t-----\t-----");

                    // displaying student details
                    for(i=0; i<n; i++){
                        if(stud[i].marks >= 80)
                            grade = 'A';
                        else if(stud[i].marks >= 60)
                            grade = 'B';
                        else if(stud[i].marks >= 40)
                            grade = 'C';
                        else
                            grade = 'F';

                        printf("\n\t %s\t%d\t%d\t%c", stud[i].name, stud[i].rollno, stud[i].marks, grade);
                    }
                    break;

            case 3:         // to search student record by roll number
                    printf("\n\n\t ENTER THE ROLL NUMBER TO SEARCH FOR: ");
                    scanf("%d", &roll);

                    // searching for student record
                    found = 0;
                    for(i=0; i<n; i++){
                        if(stud[i].rollno == roll){
                            printf("\n\n\t STUDENT RECORD FOUND!");
                            printf("\n\t NAME: %s", stud[i].name);
                            printf("\n\t ROLL NUMBER: %d", stud[i].rollno);
                            printf("\n\t MARKS: %d", stud[i].marks);
                            found = 1;
                            break;
                        }
                    }

                    if(!found)
                        printf("\n\n\t STUDENT RECORD NOT FOUND!");
                    break;

            case 4:         // to find highest and lowest marks
                    hmarks = stud[0].marks;
                    lmarks = stud[0].marks;
                    for(i=1; i<n; i++){
                        if(stud[i].marks > hmarks)
                            hmarks = stud[i].marks;     // new highest marks
                        if(stud[i].marks < lmarks)
                            lmarks = stud[i].marks;     // new lowest marks
                    }

                    printf("\n\n\t HIGHEST MARKS: %d", hmarks);
                    printf("\n\t LOWEST MARKS: %d", lmarks);
                    break;

            case 5:         // to find class average
                    printf("\n\n\t CLASS AVERAGE: %d", avgmarks);
                    break;

            case 6:         // to exit the program
                    printf("\n\n\t PRESS 'Y' TO CONFIRM EXIT: ");
                    scanf(" %c", &ch);
                    if(ch == 'y' || ch == 'Y'){
                        printf("\n\n\t THANK YOU FOR USING ONLINE EXAMINATION SYSTEM!");
                        exit(0);   // exit from program
                    }
                    break;

            default:        // to handle invalid input
                    printf("\n\n\t INVALID CHOICE! PLEASE CHOOSE AGAIN.");
        }
    }while(1);

    return 0;
}