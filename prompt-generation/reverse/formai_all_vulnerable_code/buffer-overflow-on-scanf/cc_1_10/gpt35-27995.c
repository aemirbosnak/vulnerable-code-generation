//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// Thread function to display even numbers
void *display_even(void *num)
{
    int i;
    int max_num = *((int*) num); // Converting argument void pointer to integer
    printf("Even numbers: ");
    for(i = 1; i <= max_num; i++)
    {
        if(i % 2 == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Thread function to display odd numbers
void *display_odd(void *num)
{
    int i;
    int max_num = *((int*) num); // Converting argument void pointer to integer
    printf("Odd numbers: ");
    for(i = 1; i <= max_num; i++)
    {
        if(i % 2 != 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    pthread_t even_thread, odd_thread; // Thread holding variables
    int max_num;

    printf("Enter the maximum positive integer: ");
    scanf("%d", &max_num);

    // Creating even thread
    if(pthread_create(&even_thread, NULL, display_even, (void*) &max_num))
    {
        printf("Error in creating even thread.\n");
        exit(1);
    }

    // Creating odd thread
    if(pthread_create(&odd_thread, NULL, display_odd, (void*) &max_num))
    {
        printf("Error in creating odd thread.\n");
        exit(1);
    }

    // Waiting for both threads to finish
    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    printf("All threads have finished.\n");
    return 0;
}