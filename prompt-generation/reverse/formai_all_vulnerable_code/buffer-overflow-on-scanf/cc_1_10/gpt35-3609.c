//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <time.h>

int main() {
    int num;
    double time_taken;
    printf("Welcome to the funniest Benchmarking program ever!\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("You have entered %d. Let's see how fast your computer is!\n", num);
    
    clock_t t1 = clock();
    for(int i=0; i<num; i++){
        printf("Oops! ");
    }
    clock_t t2 = clock();
    time_taken = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    
    printf("\nThe loop ran %d times and it took %f milliseconds to execute.\n", num, time_taken);
    
    printf("\nNow, let's do something even funnier. Enter another number: ");
    scanf("%d", &num);
    int sum = 0;
    t1 = clock();
    for(int i=1; i<=num; i++){
        sum += i;
    }
    t2 = clock();
    time_taken = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    
    printf("\nWow, you entered %d! Let's see how fast your computer can add all numbers from 1 to %d.\n", num, num);
    printf("It took %f milliseconds to add all numbers from 1 to %d. Your computer is amazing!\n", time_taken, num);
    
    printf("\nBut wait, we're not done yet! Let's find out the largest prime number smaller than %d. Enter your number now: ", num);
    scanf("%d", &num);
    int max_prime = 2;
    t1 = clock();
    for(int i=2; i<=num; i++){
        if(is_prime(i)){
            max_prime = i;
        }
    }
    t2 = clock();
    time_taken = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    
    printf("\nThe largest prime number smaller than %d is %d. It only took %f milliseconds to find it!\n", num, max_prime, time_taken);
    
    printf("\nThanks for using this program. Your computer is officially the funniest computer ever!\n");
    return 0;
}

int is_prime(int num){
    for(int i=2; i<num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}