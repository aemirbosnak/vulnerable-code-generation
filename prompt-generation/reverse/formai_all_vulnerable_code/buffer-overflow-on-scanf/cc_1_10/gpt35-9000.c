//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
int main() {
    // Welcome message
    printf("Welcome to the Online Examination System\n\n");
    
    // Get student details
    char name[30], rollNo[10], branch[50];
    printf("Please enter your name: ");
    scanf("%[^\n]s", name);
    printf("Please enter your roll number: ");
    scanf(" %[^\n]s", rollNo);
    printf("Please enter your branch: ");
    scanf(" %[^\n]s", branch);
    
    // Instructions
    printf("\nInstructions:\n");
    printf("- There are 5 multiple choice questions in this exam.\n");
    printf("- Each question carries 10 marks.\n");
    printf("- For each incorrect answer, 2 marks will be deducted.\n");
    printf("- You have 10 minutes to complete the exam.\n\n");
    
    // Start exam
    char answers[5];
    int marks = 0;
    printf("Start Exam:\n");
    
    // Question 1
    printf("\n1. What is the capital city of India?\n");
    printf("A. Mumbai\n");
    printf("B. New Delhi\n");
    printf("C. Bangalore\n");
    printf("D. Kolkata\n");
    printf("Answer: ");
    scanf(" %c", &answers[0]);
    if (answers[0] == 'B') {
        marks += 10;
        printf("Correct! You have gained 10 marks.\n\n");
    } else {
        marks -= 2;
        printf("Incorrect! You have lost 2 marks.\n\n");
    }
    
    // Question 2
    printf("2. Who is the CEO of Tesla?\n");
    printf("A. Mark Zuckerberg\n");
    printf("B. Jeff Bezos\n");
    printf("C. Tim Cook\n");
    printf("D. Elon Musk\n");
    printf("Answer: ");
    scanf(" %c", &answers[1]);
    if (answers[1] == 'D') {
        marks += 10;
        printf("Correct! You have gained 10 marks.\n\n");
    } else {
        marks -= 2;
        printf("Incorrect! You have lost 2 marks.\n\n");
    }
    
    // Question 3
    printf("3. Who wrote the book 'To Kill a Mockingbird'?\n");
    printf("A. Harper Lee\n");
    printf("B. Ernest Hemingway\n");
    printf("C. F. Scott Fitzgerald\n");
    printf("D. William Faulkner\n");
    printf("Answer: ");
    scanf(" %c", &answers[2]);
    if (answers[2] == 'A') {
        marks += 10;
        printf("Correct! You have gained 10 marks.\n\n");
    } else {
        marks -= 2;
        printf("Incorrect! You have lost 2 marks.\n\n");
    }
    
    // Question 4
    printf("4. Who won the 2019 NBA finals MVP trophy?\n");
    printf("A. Steph Curry\n");
    printf("B. Kevin Durant\n");
    printf("C. Kawhi Leonard\n");
    printf("D. LeBron James\n");
    printf("Answer: ");
    scanf(" %c", &answers[3]);
    if (answers[3] == 'C') {
        marks += 10;
        printf("Correct! You have gained 10 marks.\n\n");
    } else {
        marks -= 2;
        printf("Incorrect! You have lost 2 marks.\n\n");
    }
    
    // Question 5
    printf("5. What is the chemical symbol for gold?\n");
    printf("A. Au\n");
    printf("B. Ag\n");
    printf("C. Pt\n");
    printf("D. Cu\n");
    printf("Answer: ");
    scanf(" %c", &answers[4]);
    if (answers[4] == 'A') {
        marks += 10;
        printf("Correct! You have gained 10 marks.\n\n");
    } else {
        marks -= 2;
        printf("Incorrect! You have lost 2 marks.\n\n");
    }
    
    // Print result
    printf("Exam Over!\n");
    printf("Name: %s\n", name);
    printf("Roll Number: %s\n", rollNo);
    printf("Branch: %s\n", branch);
    printf("Total Marks: %d/50\n", marks);
    
    // End program
    return 0;
}