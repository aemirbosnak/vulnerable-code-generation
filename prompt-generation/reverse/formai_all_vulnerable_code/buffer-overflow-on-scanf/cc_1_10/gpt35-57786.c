//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

int generate_random_number(int min, int max){
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int gcd(int a, int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    int numbers[MAX_NUMBERS];
    int count, i, j, k, num1, num2, common_divisor;

    printf("Enter the number of integers to be generated (between 5-100): ");
    scanf("%d", &count);
    if(count<5 || count>MAX_NUMBERS){
        printf("Invalid number of integers.\n");
        return -1;
    }

    for(i=0; i<count; i++){
        numbers[i] = generate_random_number(1, 100);
        printf("%d ", numbers[i]);
    }
    printf("\n");

    for(i=0; i<count-1; i++){
        for(j=i+1; j<count; j++){
            num1 = numbers[i];
            num2 = numbers[j];
            common_divisor = gcd(num1, num2);

            if(common_divisor == 1)
                continue;

            printf("%d and %d have a common divisor of %d. Remove one of them (c) or both (b)? ", num1, num2, common_divisor);

            char choice;
            scanf(" %c", &choice);

            switch(choice){
                case 'b':
                case 'B':
                    numbers[i] = 0;
                    numbers[j] = 0;
                    break;
                case 'c':
                case 'C':
                    if(num1 == common_divisor)
                        numbers[i] = 0;
                    else
                        numbers[j] = 0;
                    break;
                default:
                    printf("Invalid choice. Choosing to remove both.\n");
                    numbers[i] = 0;
                    numbers[j] = 0;
            }
        }
    }

    printf("Remaining numbers: ");
    k=0;
    for(i=0; i<count; i++){
        if(numbers[i]!=0){
            printf("%d ", numbers[i]);
            k++;
        }
    }

    if(k < 2){
        printf("\nNot enough numbers remaining to perform operation.");
        return -1;
    }

    num1 = numbers[0];
    for(i=1; i<k; i++){
        num2 = numbers[i];
        num1 = gcd(num1, num2);
    }

    printf("\nGCD of remaining numbers: %d", num1);
    return 0;
}