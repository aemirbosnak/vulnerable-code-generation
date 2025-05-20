//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *decimal_to_binary(void *arg);
void *binary_to_decimal(void *arg);

int main()
{
    int decimal_number,binary_number;
    pthread_t t1,t2;

    //getting decimal input from user
    printf("Enter decimal number: ");
    scanf("%d",&decimal_number);

    //creating thread for decimal to binary conversion
    pthread_create(&t1,NULL,decimal_to_binary,&decimal_number);
    //joining thread
    pthread_join(t1,NULL);

    //getting binary input from user
    printf("\nEnter binary number: ");
    scanf("%d",&binary_number);

    //creating thread for binary to decimal conversion
    pthread_create(&t2,NULL,binary_to_decimal,&binary_number);
    //joining thread
    pthread_join(t2,NULL);

    return 0;
}

void *decimal_to_binary(void *arg)
{
    int decimal_number = *(int*)arg;
    int binary_number[32],i=0;

    //converting decimal to binary
    while(decimal_number>0)
    {
        binary_number[i] = decimal_number%2;
        decimal_number /= 2;
        i++;
    }

    //displaying binary output
    printf("\nBinary Output: ");
    for(int j=i-1;j>=0;j--)
        printf("%d",binary_number[j]);

    pthread_exit(NULL);
}

void *binary_to_decimal(void *arg)
{
    int binary_number = *(int*)arg;
    int decimal_number=0,base=1;

    //converting binary to decimal
    while(binary_number>0)
    {
        int rem = binary_number % 10;
        decimal_number += rem * base;
        binary_number /= 10;
        base *= 2;
    }

    //displaying decimal output
    printf("\nDecimal Output: %d",decimal_number);

    pthread_exit(NULL);
}