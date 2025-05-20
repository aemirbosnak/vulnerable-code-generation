//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: futuristic
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NUMBERS 100
#define MIN_VALUE -100
#define MAX_VALUE 100

int main()
{
    srand(time(NULL));
    int num_of_numbers = rand() % MAX_NUMBERS + 1;
    int numbers[MAX_NUMBERS];
    for(int i=0;i<num_of_numbers;i++)
    {
        numbers[i] = rand() % MAX_VALUE - MIN_VALUE;
    }
    int choice;
    printf("\nWelcome to the Future Math Exercise Program\n");
    printf("Choose your exercise:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d",&choice);
    int result = 0;
    switch(choice)
    {
        case 1:
            for(int i=0;i<num_of_numbers;i++)
            {
                result += numbers[i];
            }
            printf("\nThe sum of %d numbers is: %d",num_of_numbers,result);
            break;
        case 2:
            for(int i=0;i<num_of_numbers;i++)
            {
                result -= numbers[i];
            }
            printf("\nThe difference of %d numbers is: %d",num_of_numbers,result);
            break;
        case 3:
            result = 1;
            for(int i=0;i<num_of_numbers;i++)
            {
                result *= numbers[i];
            }
            printf("\nThe product of %d numbers is: %d",num_of_numbers,result);
            break;
        case 4:
            result = 1;
            for(int i=0;i<num_of_numbers;i++)
            {
                result /= numbers[i];
            }
            printf("\nThe quotient of %d numbers is: %d",num_of_numbers,result);
            break;
        default:
            printf("\nInvalid choice!");
    }
    return 0;
}