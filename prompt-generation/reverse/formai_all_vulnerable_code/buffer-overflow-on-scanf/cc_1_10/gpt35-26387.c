//FormAI DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[50], id[10], password[20], option[2];
    int score = 0, ans;
    
    printf("Welcome to the C Online Examination System. Please enter your name: ");
    scanf("%[^\n]%*c", name);
    
    printf("Please enter your ID number: ");
    scanf("%s", id);
    
    printf("Please enter your password: ");
    scanf("%s", password);
    
    // Authenticate user
    if (strcmp(password, "cpassword123") == 0) {
        printf("Welcome, %s! You may now take the exam.\n", name);
        printf("Press enter to begin.");
        getchar();
        
        // Question 1
        printf("Question 1: What is the value of pi up to two decimal places?\n");
        printf("A) 3.11    B) 3.14    C) 3.16    D) 3.21\n");
        printf("Enter your answer (A, B, C or D): ");
        scanf("%s", option);
        
        if (strcmp(option, "B") == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
        
        // Question 2
        printf("Question 2: What keyword is used in C to exit a loop?\n");
        printf("A) break    B) exit    C) return    D) stop\n");
        printf("Enter your answer (A, B, C or D): ");
        scanf("%s", option);
        
        if (strcmp(option, "A") == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
        
        // Question 3
        printf("Question 3: Which operator is used to access a member of a struct?\n");
        printf("A) ->    B) .    C) ::    D) \\n");
        printf("Enter your answer (A, B, C or D): ");
        scanf("%s", option);
        
        if (strcmp(option, "B") == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
        
        // Question 4
        printf("Question 4: What does the 'malloc' function do?\n");
        printf("A) Allocates memory    B) Frees memory    C) Changes memory address    D) Swaps memory values\n");
        printf("Enter your answer (A, B, C or D): ");
        scanf("%s", option);
        
        if (strcmp(option, "A") == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
        
        // Question 5
        printf("Question 5: What is the difference between ++i and i++?\n");
        printf("A) ++i increments before evaluation, i++ increments after evaluation\n");
        printf("B) ++i increments after evaluation, i++ increments before evaluation\n");
        printf("C) There is no difference, they are interchangeable\n");
        printf("D) ++i and i++ are not valid syntax\n");
        printf("Enter your answer (A, B, C or D): ");
        scanf("%s", option);
        
        if (strcmp(option, "A") == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
        
        // Display score
        printf("Congratulations, %s! You have completed the exam.\n", name);
        printf("Your final score is %d out of 5.\n", score);
    } else {
        printf("Access denied. Incorrect password.\n");
    }
    
    return 0;
}