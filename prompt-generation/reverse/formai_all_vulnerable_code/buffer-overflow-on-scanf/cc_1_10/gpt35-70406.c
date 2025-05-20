//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Interactive Math Exercise Program\n");
    printf("Here, we will test your knowledge of trigonometry and calculus\n");

    // Trigonometry problems
    double angle_degrees = 45;
    double angle_radians = angle_degrees * M_PI / 180;
    double sin_result = sin(angle_radians);
    double cos_result = cos(angle_radians);
    double tan_result = tan(angle_radians);
    printf("\nTrigonometry Problems:\n");
    printf("What is the sin(%f) in radians? ", angle_degrees);
    double user_sin_answer;
    scanf("%lf", &user_sin_answer);
    if(fabs(user_sin_answer-sin_result) < 0.0001) {
        printf("Correct! The answer is %f\n", sin_result);
    } else {
        printf("Incorrect. The correct answer is %f\n", sin_result);
    }

    printf("What is the cos(%f) in radians? ", angle_degrees);
    double user_cos_answer;
    scanf("%lf", &user_cos_answer);
    if(fabs(user_cos_answer-cos_result) < 0.0001) {
        printf("Correct! The answer is %f\n", cos_result);
    } else {
        printf("Incorrect. The correct answer is %f\n", cos_result);
    }

    printf("What is the tan(%f) in radians? ", angle_degrees);
    double user_tan_answer;
    scanf("%lf", &user_tan_answer);
    if(fabs(user_tan_answer-tan_result) < 0.0001) {
        printf("Correct! The answer is %f\n", tan_result);
    } else {
        printf("Incorrect. The correct answer is %f\n", tan_result);
    }

    // Calculus problems
    double x = 2;
    double derivative_result = 3*pow(x, 2) + 4*x + 5;
    printf("\nCalculus Problems:\n");
    printf("What is the derivative of f(x) = 3x^2 + 4x + 5 at x = %f? ", x);
    double user_derivative_answer;
    scanf("%lf", &user_derivative_answer);
    if(fabs(user_derivative_answer-derivative_result) < 0.0001) {
        printf("Correct! The answer is %f\n", derivative_result);
    } else {
        printf("Incorrect. The correct answer is %f\n", derivative_result);
    }

    printf("Thank you for participating in this exercise program!\n");

    return 0;
}