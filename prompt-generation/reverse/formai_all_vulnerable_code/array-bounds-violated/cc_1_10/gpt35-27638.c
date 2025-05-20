//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_SIZE 100

char input_string[MAX_SIZE];
char reversed_string[MAX_SIZE];
bool string_reversed = false;
pthread_mutex_t lock;

void *reverse_string()
{
    pthread_mutex_lock(&lock);
    int length = strlen(input_string);
    for (int i = 0; i < length; i++)
    {
        reversed_string[i] = input_string[length - 1 - i];
    }
    reversed_string[length] = '\0';
    printf("Reversed String: %s\n", reversed_string);
    string_reversed = true;
    pthread_mutex_unlock(&lock);
}

void *replace_x_with_y()
{
    pthread_mutex_lock(&lock);
    while (!string_reversed);
    int length = strlen(reversed_string);
    for (int i = 0; i < length; i++)
    {
        if (reversed_string[i] == 'x')
        {
            reversed_string[i] = 'y';
        }
    }
    printf("String with x replaced with y: %s\n", reversed_string);
    pthread_mutex_unlock(&lock);
}

int main()
{
    printf("Enter a string: ");
    fgets(input_string, MAX_SIZE, stdin);
    input_string[strlen(input_string) - 1] = '\0';

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &reverse_string, NULL);
    pthread_create(&thread2, NULL, &replace_x_with_y, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}