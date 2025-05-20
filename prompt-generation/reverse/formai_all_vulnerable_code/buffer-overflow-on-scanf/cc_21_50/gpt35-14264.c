//FormAI DATASET v1.0 Category: Math exercise ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int num1, num2, operator1, operator2, answer, user_answer, correct_answers = 0, incorrect_answers = 0;
    char opera1, opera2;
    
    printf("###############################\n");
    printf("# C MATH EXERCISES GENERATOR #\n");
    printf("###############################\n\n");
    
    printf("HOW MANY EXERCISES DO YOU WANT TO GENERATE?\n");
    scanf("%d", &answer);
    printf("\n");

    srand(time(NULL));
    
    for (int i = 0; i < answer; i++) {
        
        num1 = rand() % 101;
        num2 = rand() % 101;
        operator1 = rand() % 4;
        operator2 = rand() % 4;
        
        switch (operator1) {
            case 0:
                opera1 = '+';
                break;
            case 1:
                opera1 = '-';
                break;
            case 2:
                opera1 = '*';
                break;
            default:
                opera1 = '/';
                break;
        }
        
        switch (operator2) {
            case 0:
                opera2 = '+';
                break;
            case 1:
                opera2 = '-';
                break;
            case 2:
                opera2 = '*';
                break;
            default:
                opera2 = '/';
                break;
        }
        
        if (opera1 == '/' && num2 == 0) {
            num2 = 1 + rand() % 100;
        }
        
        if (opera2 == '/' && (num2 == 0 || num1 % num2 != 0)) {
            if (num2 == 0) {
                num2 = 1 + rand() % 100;
            }
            int mult = num2 * (1 + rand() % 10);
            num1 = num2 * mult;
        }
        
        printf("EXERCISE %d: ", i + 1);
        printf("%d %c %d %c %d", num1, opera1, num2, opera2, num2);
        printf(" = ?\n");
        scanf("%d", &user_answer);
        
        if (opera1 == '/' && num2 == 0) {
            num2 = 1;
        }
        
        if (opera2 == '/' && (num2 == 0 || num1 % num2 != 0)) {
            if (num2 == 0) {
                num2 = 1;
            }
            int mult = num2 * (1 + rand() % 10);
            num1 = num2 * mult;
        }
        
        switch (opera1) {
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
            case '/':
                answer = num1 / num2;
                break;
        }

        switch (opera2) {
            case '+':
                answer += num2;
                break;
            case '-':
                answer -= num2;
                break;
            case '*':
                answer *= num2;
                break;
            case '/':
                answer /= num2;
                break;
        }
        
        if (user_answer == answer) {
            printf("CORRECT!\n");
            correct_answers++;
            printf("---------------------------------------------\n\n");
        } else {
            printf("SORRY, YOU ARE WRONG. THE CORRECT ANSWER WAS %d.\n", answer);
            incorrect_answers++;
            printf("---------------------------------------------\n\n");
        }
    }
    
    printf("\n################################\n");
    printf("# YOU ARE FINISHED!\n");
    printf("# YOU HAD %d CORRECT ANSWERS AND %d INCORRECT ANSWERS.\n", correct_answers, incorrect_answers);
    printf("################################\n");
    
    return 0;
}