//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    printf("Are you ready for a unique C Math exercise example program? Let's go!\n");

    // Generating a random number between 1 and 100
    srand(time(NULL));
    int number = rand() % 100 + 1;

    printf("I have generated a random number between 1 and 100, can you guess what it is?\n");

    int guess;
    int tries = 0;

    while(1){
        printf("\nEnter your guess: ");
        scanf("%d",&guess);
        tries++;

        if(guess == number){
            printf("Congratulations! You have guessed the number in %d tries!\n\n",tries);
            printf("Let's move on to some more exciting mathematical exercises now.\n");

            // Finding square root of a number
            printf("I have a number for you! Can you find its square root?\nEnter the number: ");
            float num;
            scanf("%f",&num);
            printf("The square root of %f is %f.\n\n",num,sqrt(num));

            // Calculating the area of a circle
            printf("Let's try something else now. Can you calculate the area of a circle?\n");
            float radius;
            printf("Enter the radius of the circle: ");
            scanf("%f",&radius);
            printf("The area of the circle with radius %f is %f\n\n",radius,M_PI*radius*radius);

            // Generating two random numbers and finding the average
            printf("Finally, can you find the average of two randomly generated numbers?\n");
            int num1 = rand() % 50 + 1;
            int num2 = rand() % 50 + 1;
            printf("The two numbers are %d and %d. Their average is %f.\n\n",num1,num2,((float)num1+num2)/2);
            
            // Exiting the program
            printf("Thanks for playing! I hope you had fun with these exciting mathematical exercises. Goodbye!\n");
            exit(0);
        }
        else if(guess < number)
            printf("The number is higher than %d.\n",guess);
        else
            printf("The number is lower than %d.\n",guess);
    }
}