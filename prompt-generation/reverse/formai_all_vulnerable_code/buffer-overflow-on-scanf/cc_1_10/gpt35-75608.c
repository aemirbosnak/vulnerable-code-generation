//FormAI DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int input, answer, correct = 0, total = 0;
    char name[20];
    printf("Greetings traveler! What is thy name?\n");
    scanf("%s", name);
    printf("Welcome, %s! Prepare ye for some mathematical challenges!\n\n", name);
    srand(time(NULL));

    while(1) {
        int num1 = (rand() % 50) + 1;
        int num2 = (rand() % 50) + 1;
        int operator = rand() % 3;
        
        if(operator == 0) {
            printf("What is %d + %d?\n", num1, num2);
            answer = num1 + num2;
        }
        else if(operator == 1) {
            printf("What is %d - %d?\n", num1, num2);
            answer = num1 - num2;
        }
        else {
            printf("What is %d * %d?\n", num1, num2);
            answer = num1 * num2;
        }

        total++;
        scanf("%d", &input);
        if(input == answer) {
            printf("Well done, %s! Thou art correct!\n\n", name);
            correct++;
        }
        else {
            printf("Alas, %s! Thou hast been bested! The answer is %d.\n\n", name, answer);
        }

        // Ask if user wants to continue
        char response;
        printf("Wouldst thou like to continue? [Y/N]\n");
        scanf(" %c", &response);
        if(response == 'N' || response == 'n') break;

    }

    printf("Well played, %s! Thou hast answered %d out of %d correctly!\n", name, correct, total);

    return 0;
}