//FormAI DATASET v1.0 Category: Online Examination System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
    int total_questions = 5;
    int marks_per_correct_ans = 2;
    int negative_marks_per_wrong_ans = 1;
    int total_marks = total_questions * marks_per_correct_ans;
    int obtained_marks = 0;
    int questions_attempted = 0;
    float percentage;
    
    printf("============= Welcome to the Online Examination System =============\n\n");
    printf("Rules:\n");
    printf("1. Total questions: %d\n", total_questions);
    printf("2. Each correct answer carries %d marks\n", marks_per_correct_ans);
    printf("3. Each wrong answer results in a deduction of %d marks\n", negative_marks_per_wrong_ans);
    printf("4. There is no mark awarded or deducted for unanswered questions\n\n");
    
    printf("Please begin the examination:\n");
    
    for(int i=1; i<=total_questions; i++) {
        printf("\nQuestion %d:\n", i);
        printf("What is the capital of Japan?\n");
        printf("A. Tokyo\nB. Seoul\nC. Beijing\nD. Bangkok\n");
        char answer;
        printf("Your Answer: ");
        scanf(" %c", &answer);
        if(answer == 'A' || answer == 'a') {
            obtained_marks += marks_per_correct_ans;
            questions_attempted++;
        } else if(answer == 'B' || answer == 'C' || answer == 'D' || answer == 'b' || answer == 'c' || answer == 'd') {
            obtained_marks -= negative_marks_per_wrong_ans;
            questions_attempted++;
        } else {
            printf("Question skipped.\n");
        }
    }
    
    percentage = ((float)obtained_marks / (float)total_marks) * 100.0;
    
    printf("\nTotal Questions Attempted: %d\n", questions_attempted);
    printf("Total Marks obtained: %d\n", obtained_marks);
    printf("Percentage: %.2f%%\n\n", percentage);
    
    if(percentage >= 60.0) {
        printf("Congratulations! You have passed this examination.\n");
    } else {
        printf("Sorry, you have failed this examination. Better luck next time.\n");
    }
    
    return 0;
}