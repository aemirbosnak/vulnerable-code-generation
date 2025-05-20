//Falcon-180B DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MIN_VALUE 1
#define MAX_VALUE 100

int main() {
    int numbers[MAX_NUMBERS];
    int num_elements = 0;
    int choice;
    int value;

    srand(time(0));

    do {
        printf("Welcome to the Number Generator!\n");
        printf("Please choose an option:\n");
        printf("1. Generate a random number between %d and %d\n", MIN_VALUE, MAX_VALUE);
        printf("2. Add a number to the list\n");
        printf("3. Remove a number from the list\n");
        printf("4. Display the current list of numbers\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number of random numbers you want to generate: ");
                scanf("%d", &value);

                for(int i = 0; i < value; i++) {
                    int random_num = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
                    printf("%d ", random_num);
                }

                printf("\n");
                break;

            case 2:
                printf("Enter the number you want to add: ");
                scanf("%d", &value);

                if(num_elements >= MAX_NUMBERS) {
                    printf("Sorry, the list is full!\n");
                } else {
                    numbers[num_elements] = value;
                    num_elements++;
                }

                break;

            case 3:
                printf("Enter the number you want to remove: ");
                scanf("%d", &value);

                for(int i = 0; i < num_elements; i++) {
                    if(numbers[i] == value) {
                        for(int j = i; j < num_elements - 1; j++) {
                            numbers[j] = numbers[j + 1];
                        }

                        num_elements--;
                        break;
                    }
                }

                break;

            case 4:
                printf("Current list of numbers:\n");

                for(int i = 0; i < num_elements; i++) {
                    printf("%d ", numbers[i]);
                }

                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= 5);

    return 0;
}