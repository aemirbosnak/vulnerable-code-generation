//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double principal;
double interestRate;
double monthlyPayment;
int numMonths;

void* calculateInterest(void* threadID) {
    double* interest = malloc(sizeof(double));
    long tid;
    tid = (long)threadID;
    printf("Thread %ld is calculating interest.\n", tid);
    *interest = principal * (interestRate / 12);
    pthread_exit(interest);
}

int main() {
    printf("Welcome to the Mortgage Calculator.\n");
    printf("Please enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Please enter the interest rate (in percentage): ");
    scanf("%lf", &interestRate);
    printf("Please enter the monthly payment: ");
    scanf("%lf", &monthlyPayment);
    printf("Please enter the number of months: ");
    scanf("%d", &numMonths);
    
    double balance = principal;
    pthread_t threads[numMonths];
    int rc;
    long t;
    
    for (t = 0; t < numMonths; t++) {
        rc = pthread_create(&threads[t], NULL, calculateInterest, (void*)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
        double* interest;
        pthread_join(threads[t], (void**)&interest);
        balance += *interest;
        balance -= monthlyPayment;
        if (balance <= 0) {
            printf("Congratulations! You have paid off your mortgage in %ld months.\n", t+1);
            pthread_exit(NULL);
        }
    }
    printf("You were not able to pay off your mortgage in %d months.\n", numMonths);
    pthread_exit(NULL);
}