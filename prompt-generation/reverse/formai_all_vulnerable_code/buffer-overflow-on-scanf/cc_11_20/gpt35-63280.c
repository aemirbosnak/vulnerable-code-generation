//FormAI DATASET v1.0 Category: Math exercise ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int option;
    printf("Let's do some Math exercises! Choose an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Sine\n");
    printf("7. Cosine\n");
    printf("8. Tangent\n");
    printf("9. Quit\n");

    srand(time(NULL));
    do {
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                int num1 = rand() % 101;
                int num2 = rand() % 101;
                int answer = num1 + num2;

                printf("\nWhat is %d + %d ?\n", num1, num2);
                printf("Answer: ");
                int user_answer;
                scanf("%d", &user_answer);
                if(user_answer == answer) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %d\n", answer);
                }
                break;
            }

            case 2: {
                int num1 = rand() % 101;
                int num2 = rand() % 101;
                int answer = num1 - num2;

                printf("\nWhat is %d - %d ?\n", num1, num2);
                printf("Answer: ");
                int user_answer;
                scanf("%d", &user_answer);
                if(user_answer == answer) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %d\n", answer);
                }
                break;
            }

            case 3: {
                int num1 = rand() % 21;
                int num2 = rand() % 21;
                int answer = num1 * num2;

                printf("\nWhat is %d * %d ?\n", num1, num2);
                printf("Answer: ");
                int user_answer;
                scanf("%d", &user_answer);
                if(user_answer == answer) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %d\n", answer);
                }
                break;
            }

            case 4: {
                int num1 = rand() % 101;
                int num2 = rand() % 21 + 1;
                float answer = num1 / (float)num2;

                printf("\nWhat is %d / %d ? (Round to two decimal points)\n", num1, num2);
                printf("Answer: ");
                float user_answer;
                scanf("%f", &user_answer);
                user_answer = roundf(user_answer * 100) / 100;
                if(user_answer == answer) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %.2f\n", answer);
                }
                break;
            }

            case 5: {
                int num = rand() % 101;
                float answer = sqrt(num);

                printf("\nWhat is the square root of %d ? (Round to two decimal points)\n", num);
                printf("Answer: ");
                float user_answer;
                scanf("%f", &user_answer);
                user_answer = roundf(user_answer * 100) / 100;
                if(user_answer == answer) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %.2f\n", answer);
                }
                break;
            }

            case 6: {
                float angle = (rand() % 181) - 90;
                float answer = sin(angle * M_PI / 180);

                printf("\nWhat is the sine of %.2f degrees ? (Round to two decimal points)\n", angle);
                printf("Answer: ");
                float user_answer;
                scanf("%f", &user_answer);
                user_answer = roundf(user_answer * 100) / 100;
                if(user_answer == answer) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %.2f\n", answer);
                }
                break;
            }

            case 7: {
                float angle = (rand() % 181) - 90;
                float answer = cos(angle * M_PI / 180);

                printf("\nWhat is the cosine of %.2f degrees ? (Round to two decimal points)\n", angle);
                printf("Answer: ");
                float user_answer;
                scanf("%f", &user_answer);
                user_answer = roundf(user_answer * 100) / 100;
                if(user_answer == answer) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %.2f\n", answer);
                }
                break;
            }

            case 8: {
                float angle = (rand() % 181) - 90;
                float answer = tan(angle * M_PI / 180);

                printf("\nWhat is the tangent of %.2f degrees ? (Round to two decimal points)\n", angle);
                printf("Answer: ");
                float user_answer;
                scanf("%f", &user_answer);
                user_answer = roundf(user_answer * 100) / 100;
                if(user_answer == answer) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %.2f\n", answer);
                }
                break;
            }

            case 9: {
                printf("Thank you for doing Math exercises with me!\n");
                break;
            }

            default: {
                printf("\nInvalid option! Please try again.\n");
                break;
            }
        }
    } while(option != 9);

    return 0;
}