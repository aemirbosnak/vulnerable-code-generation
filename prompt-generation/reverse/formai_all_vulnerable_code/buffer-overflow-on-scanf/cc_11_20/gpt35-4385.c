//FormAI DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, choice, answer;
    srand(time(NULL));
    printf("Welcome to the Math Exercise program!\n");
    
    do
    {
        printf("\nPlease select an option:\n"
               "1. Addition\n"
               "2. Subtraction\n"
               "3. Multiplication\n"
               "4. Division\n"
               "5. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                num1 = rand() % 100;
                num2 = rand() % 100;
                printf("\nWhat is the sum of %d and %d?\n", num1, num2);
                result = num1 + num2;
                scanf("%d", &answer);
                if (answer == result)
                    printf("Correct!\n");
                else
                    printf("Incorrect. The correct answer is %d\n", result);
                break;

            case 2:
                num1 = rand() % 100;
                num2 = rand() % 100;
                printf("\nWhat is %d minus %d?\n", num1, num2);
                result = num1 - num2;
                scanf("%d", &answer);
                if (answer == result)
                    printf("Correct!\n");
                else
                    printf("Incorrect. The correct answer is %d\n", result);
                break;

            case 3:
                num1 = rand() % 10;
                num2 = rand() % 10;
                printf("\nWhat is %d times %d?\n", num1, num2);
                result = num1 * num2;
                scanf("%d", &answer);
                if (answer == result)
                    printf("Correct!\n");
                else
                    printf("Incorrect. The correct answer is %d\n", result);
                break;

            case 4:
                num1 = rand() % 100;
                num2 = rand() % 10 + 1;
                printf("\nWhat is %d divided by %d (rounded to the nearest integer)?\n", num1, num2);
                result = num1 / num2;
                scanf("%d", &answer);
                if (answer == result)
                    printf("Correct!\n");
                else
                    printf("Incorrect. The correct answer is %d\n", result);
                break;

            case 5:
                printf("Thank you for using the Math Exercise program!\n");
                return 0;

            default:
                printf("Invalid input. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}