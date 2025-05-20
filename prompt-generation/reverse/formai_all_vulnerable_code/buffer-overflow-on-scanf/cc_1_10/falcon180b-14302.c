//Falcon-180B DATASET v1.0 Category: Educational ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int main() {
    int numbers[MAX_NUMBERS];
    int num_elements = 0;
    int choice;
    int sum = 0;
    int product = 1;
    int min_num = MIN_NUMBER;
    int max_num = MAX_NUMBER;
    int avg;
    int i;

    srand(time(NULL));

    do {
        printf("Welcome to the Number Game!\n");
        printf("Please choose an option:\n");
        printf("1. Generate a random number between %d and %d\n", min_num, max_num);
        printf("2. Calculate the sum of all generated numbers\n");
        printf("3. Calculate the product of all generated numbers\n");
        printf("4. Calculate the average of all generated numbers\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Generating a random number...\n");
                numbers[num_elements] = rand() % (max_num - min_num + 1) + min_num;
                printf("Generated number: %d\n", numbers[num_elements]);
                num_elements++;
                break;
            case 2:
                for(i=0; i<num_elements; i++) {
                    sum += numbers[i];
                }
                printf("The sum of all generated numbers is: %d\n", sum);
                break;
            case 3:
                for(i=0; i<num_elements; i++) {
                    product *= numbers[i];
                }
                printf("The product of all generated numbers is: %d\n", product);
                break;
            case 4:
                avg = sum / num_elements;
                printf("The average of all generated numbers is: %.2f\n", (float)avg / 100);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= 5);

    return 0;
}