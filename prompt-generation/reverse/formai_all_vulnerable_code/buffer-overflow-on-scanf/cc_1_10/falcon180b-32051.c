//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include<stdio.h>
#include<math.h>

void is_prime(int n) {
    if(n <= 1) {
        printf("%d is not a prime number.\n", n);
        return;
    }
    int i;
    for(i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            printf("%d is not a prime number.\n", n);
            return;
        }
    }
    printf("%d is a prime number.\n", n);
}

int main() {
    int num, choice, i;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Check if a single number is prime\n");
        printf("2. Generate prime numbers in a range\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                is_prime(num);
                break;
            case 2:
                printf("Enter the lower limit: ");
                scanf("%d", &num);
                printf("Enter the upper limit: ");
                scanf("%d", &i);

                while(num <= i) {
                    is_prime(num);
                    num++;
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}