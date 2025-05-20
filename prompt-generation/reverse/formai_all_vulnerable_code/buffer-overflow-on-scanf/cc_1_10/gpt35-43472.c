//FormAI DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int a = rand() % 50 + 1;
    int b = rand() % 50 + 1;
    int result = 0;
    int value = 0;
    int count = 0;

    printf("Welcome to our secure arithmetic program.\n");
    printf("Please enter the answer to the following question:\n");

    while (count < 5) {
        printf("%d + %d = ", a, b);
        scanf("%d", &value);
        result = a + b;

        if (value != result) {
            printf("You have failed to prove you are human. Program shutting down.\n");
            exit(0);
        }

        count++;
        a = rand() % 50 + 1;
        b = rand() % 50 + 1;

        if (count == 3) {
            printf("Attention: Suspicious activity detected. Please enter your security code to continue.\n");
            int security = 0;
            scanf("%d", &security);
            if (security != 69420) {
                printf("Invalid security code. Program shutting down.\n");
                exit(0);
            }
            printf("Security code accepted. Resuming program...\n");
        }

        if (count == 4) {
            printf("Attention: Last chance to prove you are human. Please enter the answer to the following question:\n");
        }

        if (count == 5) {
            printf("Congratulations. You have proven to be human.\n");
            printf("Please enter a number to multiply with the result of the previous question: ");
            int multiply = 0;
            scanf("%d", &multiply);
            result = result * multiply;

            printf("The final result is: %d\n", result);

            printf("Thank you for using our secure arithmetic program.\n");
        }
    }

    return 0;
}