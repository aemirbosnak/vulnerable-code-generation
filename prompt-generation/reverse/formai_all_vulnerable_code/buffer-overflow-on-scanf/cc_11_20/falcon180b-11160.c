//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, sum = 0;
    int arr[100];
    int choice;

    srand(time(0));

    printf("Welcome to the C Math Exercise Program!\n");
    printf("Please choose a difficulty level:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have chosen Easy mode.\n");
            for(i = 0; i < 10; i++) {
                arr[i] = rand() % 100;
            }
            break;
        case 2:
            printf("You have chosen Medium mode.\n");
            for(i = 0; i < 20; i++) {
                arr[i] = rand() % 200;
            }
            break;
        case 3:
            printf("You have chosen Hard mode.\n");
            for(i = 0; i < 30; i++) {
                arr[i] = rand() % 300;
            }
            break;
        default:
            printf("Invalid choice, exiting program.\n");
            return 0;
    }

    printf("The array of integers is:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNow, please enter the sum of all the elements in the array:");
    scanf("%d", &sum);

    if(sum == 0) {
        printf("You have not entered any valid input. Exiting program.\n");
        return 0;
    }

    for(i = 0; i < 10; i++) {
        for(j = i + 1; j < 10; j++) {
            if(arr[i] + arr[j] == sum) {
                printf("The two integers are %d and %d\n", arr[i], arr[j]);
                return 0;
            }
        }
    }

    printf("No two integers in the array add up to %d. Exiting program.\n", sum);

    return 0;
}