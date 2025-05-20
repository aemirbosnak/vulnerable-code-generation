//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <string.h>

// Function to print the exam details
void printExamDetails() {
    printf("Exam Name: C Online Examination System\n");
    printf("Subjects: 1. Introduction to C\n");
    printf("2. Data Types and Variables\n");
    printf("3. Control Structures\n");
    printf("4. Functions and Pointers\n");
    printf("5. Arrays and Strings\n");
    printf("6. File Handling\n");
    printf("7. Structures and Unions\n");
    printf("8. Recursion\n");
    printf("9. Linked Lists\n");
    printf("10. Stacks and Queues\n");
    printf("11. Trees and Graphs\n");
    printf("12. Sorting and Searching\n");
}

// Function to display the score
void displayScore(int score) {
    printf("Score: %d\n", score);
}

// Function to calculate the total score
int calculateTotalScore(int marks[]) {
    int totalScore = 0;
    for (int i = 0; i < 12; i++) {
        totalScore += marks[i];
    }
    return totalScore;
}

// Function to check the pass criteria
int checkPassCriteria(int totalScore, int passingScore) {
    if (totalScore >= passingScore) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    int marks[12];
    int i, j, totalScore = 0;

    // Print the exam details
    printExamDetails();

    // Input the marks
    printf("Enter the marks for each subject:\n");
    for (i = 0; i < 12; i++) {
        printf("%d. ", i + 1);
        scanf("%d", &marks[i]);
    }

    // Calculate the total score
    for (i = 0; i < 12; i++) {
        totalScore += marks[i];
    }

    // Display the score
    displayScore(totalScore);

    // Check the pass criteria
    int passingScore = 300;
    int passCriteria = checkPassCriteria(totalScore, passingScore);

    // Output the result
    if (passCriteria) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("Sorry, you have failed the exam.\n");
    }

    return 0;
}