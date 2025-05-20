//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("cls");

    // Student Information
    char name[20];
    int rollNo;
    float marks;

    // Question Bank
    char questions[10][100];
    int questionNo = 0;

    // Exam Duration
    int hours = 0;
    int minutes = 0;

    // Timer
    int timeLeft = 0;

    // Marking Scheme
    int marksObtained = 0;

    // Start the Exam
    printf("-------------------------------------------------------------------\n");
    printf("Welcome to the Online Examination System!\n");
    printf("-------------------------------------------------------------------\n");

    // Get Student Information
    printf("Enter your name:");
    scanf("%s", name);

    printf("Enter your roll number:");
    scanf("%d", &rollNo);

    printf("Enter your marks:");
    scanf("%f", &marks);

    // Set Exam Duration
    printf("Enter the number of hours you want to spend on the exam:");
    scanf("%d", &hours);

    printf("Enter the number of minutes you want to spend on the exam:");
    scanf("%d", &minutes);

    // Calculate Time Left
    timeLeft = hours * 60 + minutes;

    // Start the Timer
    // (Timer Code Here)

    // Write Questions
    for (int i = 0; i < questionNo; i++)
    {
        printf("%s", questions[i]);
    }

    // Mark Answers
    marksObtained = marksObtained + /* Logic to calculate marks based on answers */

    // Display Results
    printf("-------------------------------------------------------------------\n");
    printf("Your Name:");
    printf("%s", name);

    printf("\nYour Roll Number:");
    printf("%d", rollNo);

    printf("\nYour Marks:");
    printf("%f", marks);

    printf("\nYour Marks Obtained:");
    printf("%d", marksObtained);

    printf("\nCongratulations! You have completed the exam.\n");
    printf("-------------------------------------------------------------------\n");

    return 0;
}