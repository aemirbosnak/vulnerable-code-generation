//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input;
    int count = 0, correct = 0;
    double time_taken;
    time_t start, end;
    srand(time(0));
    printf("\n--- Typing Speed Test ---\n");
    printf("Type as many random mathematical expressions as you can in 30 seconds:\n");

    start = time(0); // start the timer

    while ((time(0) - start) <= 30) { // run the loop for 30 seconds
        int x = rand() % 11; // generate a random number between 0 and 10
        int y = rand() % 11;
        char operators[] = {'+', '-', '*', '/'};
        char op = operators[rand() % 4]; // pick a random operator
        printf("%d %c %d = ", x, op, y);
        scanf("%c", &input);
        if (input == '=') { // user has finished typing the expression
            count++;
            char dummy;
            scanf("%c", &dummy); // consume the newline character from input buffer
        }
        else {
            char expression[10];
            snprintf(expression, 10, "%d %c %d", x, op, y); // create the correct expression
            printf("Incorrect! The correct expression is %s\n", expression);
            char dummy;
            scanf("%c", &dummy); // consume the newline character from input buffer
        }
    }

    end = time(0); // stop the timer

    time_taken = difftime(end, start); // calculate the time taken
    printf("\nYou typed %d expressions in %.0lf seconds\n", count, time_taken);

    if (count > 0) { // avoid dividing by zero
        double accuracy = (double)correct / count * 100;
        double speed = (double)count / time_taken * 60;
        printf("Your accuracy: %.2lf%%\n", accuracy);
        printf("Your typing speed: %.2lf expressions per minute\n", speed);
    }

    return 0;
}