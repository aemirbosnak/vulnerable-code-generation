//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUM 1000000
#define TRUE 1
#define FALSE 0

int is_prime(int n) {
    int i, flag = TRUE;
    for(i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

void generate_primes(int start, int end) {
    FILE *fp;
    int num, count = 0;
    fp = fopen("primes.txt", "w");
    if(fp == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }
    for(num = start; num <= end; num++) {
        if(is_prime(num)) {
            fprintf(fp, "%d\n", num);
            count++;
        }
    }
    fclose(fp);
    printf("Total %d prime numbers generated and saved to primes.txt.\n", count);
}

int main() {
    int start, end;
    printf("Enter start and end numbers: ");
    scanf("%d%d", &start, &end);
    if(start < 2) {
        start = 2;
    }
    if(end > MAX_NUM) {
        end = MAX_NUM;
    }
    srand(time(NULL));
    generate_primes(start, end);
    return 0;
}