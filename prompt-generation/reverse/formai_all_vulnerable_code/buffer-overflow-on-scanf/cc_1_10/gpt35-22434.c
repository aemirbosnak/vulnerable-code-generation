//FormAI DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int marks = 0;
    
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your answers in capital letters.\n");
    
    printf("Q1. What is the capital of India?\n");
    printf("A. Mumbai\nB. Delhi\nC. Kolkata\nD. Chennai\n");
    char ans1;
    scanf("%c", &ans1);
    if(ans1 == 'B') {
        marks += 10;
    }
    
    printf("Q2. Who is the CEO of Google?\n");
    printf("A. Sundar Pichai\nB. Mark Zuckerberg\nC. Jeff Bezos\nD. Tim Cook\n");
    char ans2;
    scanf("%c", &ans2);
    if(ans2 == 'A') {
        marks += 10;
    }
    
    printf("Q3. What is the full form of HTML?\n");
    printf("A. High Text Markup Language\nB. Hyperlinks and Text Markup Language\nC. Hyper Text Markup Language\nD. None of the above\n");
    char ans3;
    scanf("%c", &ans3);
    if(ans3 == 'C') {
        marks += 10;
    }
    
    printf("Q4. Who is the author of the novel 'To Kill a Mockingbird'?\n");
    printf("A. Harper Lee\nB. Jane Austen\nC. Charles Dickens\nD. William Shakespeare\n");
    char ans4;
    scanf("%c", &ans4);
    if(ans4 == 'A') {
        marks += 10;
    }
    
    printf("Q5. Which is the largest planet in our solar system?\n");
    printf("A. Earth\nB. Mars\nC. Jupiter\nD. Saturn\n");
    char ans5;
    scanf("%c", &ans5);
    if(ans5 == 'C') {
        marks += 10;
    }
    
    printf("\nThank you for taking this online examination.\n");
    printf("Your total marks: %d\n", marks);
    
    return 0;
}