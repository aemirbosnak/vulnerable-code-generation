//FormAI DATASET v1.0 Category: Scientific ; Style: surprised
#include<stdio.h>
#include<math.h>

int main(){
    int num1, num2;
    printf("Enter two numbers to find their prime factors: ");
    scanf("%d %d", &num1, &num2);

    //check if the input numbers are prime or not
    int isPrime1 = 1, isPrime2 = 1;
    for(int i=2;i<=sqrt(num1);i++){
        if(num1%i==0){
            isPrime1 = 0;
            break;
        }
    }
    for(int i=2;i<=sqrt(num2);i++){
        if(num2%i==0){
            isPrime2 = 0;
            break;
        }
    }

    printf("\n");

    if(isPrime1 && isPrime2){
        printf("Both numbers are prime!\n");
        printf("Calculating their prime factors...\n");

        int factor1[100], factor2[100];
        int count1 = 0, count2 = 0;
        for(int i=2;i<=sqrt(num1);i++){
            if(num1%i==0){
                factor1[count1] = i;
                count1++;
            }
        }
        for(int i=2;i<=sqrt(num2);i++){
            if(num2%i==0){
                factor2[count2] = i;
                count2++;
            }
        }

        printf("Prime factors of %d: ", num1);
        for(int i=0;i<count1;i++){
            printf("%d ", factor1[i]);
        }

        printf("\nPrime factors of %d: ", num2);
        for(int i=0;i<count2;i++){
            printf("%d ", factor2[i]);
        }

        printf("\n");

        int gcd = 1;
        for(int i=0;i<count1;i++){
            for(int j=0;j<count2;j++){
                if(factor1[i] == factor2[j]){
                    gcd *= factor1[i];
                    break;
                }
            }
        }

        printf("The GCD of %d and %d is %d\n", num1, num2, gcd);
    }
    else{
        printf("At least one of the numbers is not prime!\n");
        printf("Please enter two prime numbers to find their prime factors.\n");
    }

    return 0;
}