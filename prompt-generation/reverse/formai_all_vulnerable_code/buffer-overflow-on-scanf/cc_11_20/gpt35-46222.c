//FormAI DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){

    int choice, num1, num2, answer, response;
    float floatAnswer;

    srand(time(NULL));

    do {
        system("clear");

        printf("Welcome to Math Exercise!\n");
        printf("Please select an operation to practice:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square root\n");
        scanf("%d", &choice);

        switch (choice){

            case 1:
                num1 = rand() % 100;
                num2 = rand() % 100;
                printf("What is %d + %d?\n", num1, num2);
                scanf("%d", &answer);
                if (answer == (num1 + num2)){
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %d.\n", num1 + num2);
                }
                break;

            case 2:
                num1 = rand() % 100;
                num2 = rand() % 100;
                printf("What is %d - %d?\n", num1, num2);
                scanf("%d", &answer);
                if (answer == (num1 - num2)){
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %d.\n", num1 - num2);
                }
                break;

            case 3:
                num1 = rand() % 20;
                num2 = rand() % 20;
                printf("What is %d * %d?\n", num1, num2);
                scanf("%d", &answer);
                if (answer == (num1 * num2)){
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %d.\n", num1 * num2);
                }
                break;

            case 4:
                num1 = rand() % 20;
                num2 = rand() % 20;
                printf("What is %d / %d?\n", num1, num2);
                scanf("%f", &floatAnswer);
                if (floatAnswer == (float)num1 / (float)num2){
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %.2f.\n", (float)num1 / (float)num2);
                }
                break;

            case 5:
                num1 = rand() % 100;
                printf("What is the square root of %d?\n", num1*num1);
                scanf("%f", &floatAnswer);
                if (floatAnswer == sqrt((float)num1*num1)){
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %.2f.\n", sqrt((float)num1*num1));
                }
                break;

            default:
                printf("Invalid choice.\n");

        }

        printf("Do you want to continue? (1 for Yes, 0 for No)\n");
        scanf("%d", &response);

    } while (response == 1);

    return 0;
}