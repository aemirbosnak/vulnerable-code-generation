//FormAI DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the menu options
void displayMenu(){
    printf("\n\n========= ONLINE EXAMINATION SYSTEM =========\n");
    printf("\nPlease select an option:");
    printf("\n1. Start Exam");
    printf("\n2. View Results");
    printf("\n3. Exit");
}

// Function to start and conduct the exam
void startExam(){
    char name[50];
    int age;
    char branch[20];
    int marks = 0;

    printf("\nWelcome to the Online Examination System!");
    printf("\nPlease enter your Name: ");
    scanf("%s", name);
    printf("\nEnter your Age: ");
    scanf("%d", &age);
    printf("\nEnter your Branch: ");
    scanf("%s", branch);
    
    // Conducting the exam
    printf("\nThe exam consists of 5 multiple choice questions.");
    printf("\nYou will be given 4 options for each question.");
    printf("\nPlease choose the correct option for each question.\n");

    // Question 1
    printf("\n1. What is the capital of India?");
    printf("\nA. Mumbai");
    printf("\nB. New Delhi");
    printf("\nC. Kolkata");
    printf("\nD. Chennai");
    char ans1;
    printf("\nAnswer: ");
    scanf(" %c", &ans1);
    if(ans1 == 'B' || ans1 == 'b'){
        marks++;
    }

    // Question 2
    printf("\n2. Which is the largest state in India?");
    printf("\nA. Rajasthan");
    printf("\nB. Madhya Pradesh");
    printf("\nC. Uttar Pradesh");
    printf("\nD. Jammu and Kashmir");
    char ans2;
    printf("\nAnswer: ");
    scanf(" %c", &ans2);
    if(ans2 == 'A' || ans2 == 'a'){
        marks++;
    }

    // Question 3
    printf("\n3. Who is the current President of USA?");
    printf("\nA. Barack Obama");
    printf("\nB. Donald Trump");
    printf("\nC. Joe Biden");
    printf("\nD. Bill Clinton");
    char ans3;
    printf("\nAnswer: ");
    scanf(" %c", &ans3);
    if(ans3 == 'C' || ans3 == 'c'){
        marks++;
    }

    // Question 4
    printf("\n4. Who wrote the book 'To Kill a Mockingbird'?");
    printf("\nA. Mark Twain");
    printf("\nB. Harper Lee");
    printf("\nC. JK Rowling");
    printf("\nD. Charles Dickens");
    char ans4;
    printf("\nAnswer: ");
    scanf(" %c", &ans4);
    if(ans4 == 'B' || ans4 == 'b'){
        marks++;
    }

    // Question 5
    printf("\n5. Which is the tallest building in the world?");
    printf("\nA. Burj Khalifa");
    printf("\nB. Willis Tower");
    printf("\nC. Shanghai Tower");
    printf("\nD. Taipei 101");
    char ans5;
    printf("\nAnswer: ");
    scanf(" %c", &ans5);
    if(ans5 == 'A' || ans5 == 'a'){
        marks++;
    }

    // Displaying the results
    printf("\n\n====================");
    printf("\nName: %s", name);
    printf("\nAge: %d", age);
    printf("\nBranch: %s", branch);
    printf("\nMarks: %d/5", marks);
    if(marks >= 3){
        printf("\nCongratulations! You have passed the exam.");
    }
    else{
        printf("\nSorry, you have failed the exam.");
    }
    printf("\n====================");
}

// Function to view the results of previous exams
void viewResults(){
    printf("\n\nSorry, no results available at this time!");
}

int main(){
    int choice;

    // Loop to display the menu and take user input
    do{
        displayMenu();
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // Starting the exam
                startExam();
                break;
            case 2:
                // Viewing results
                viewResults();
                break;
            case 3:
                // Exiting the program
                printf("\nThank you for using the Online Examination System!");
                exit(0);
                break;
            default:
                // Error message for incorrect input
                printf("\nInvalid choice! Please select again.");
                break;
        }
    }while(1);

    return 0;
}