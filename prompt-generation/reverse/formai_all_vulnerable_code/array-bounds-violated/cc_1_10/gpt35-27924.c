//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define ERROR_THRESHOLD 5

int main()
{
    char buffer[BUFFER_SIZE];
    int error_count = 0;
    
    // Seed random number generator
    srand(time(NULL));
    
    // Loop to continuously read input until too many errors are encountered
    while (error_count < ERROR_THRESHOLD)
    {
        // Read input from user and store it in buffer
        printf("Enter some text: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        // Perform operation on buffer
        int length = 0;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            length++;
        }
        printf("The length of the input is: %d\n", length);
        
        // Add random error to buffer
        int random_error = rand() % length;
        buffer[random_error] = buffer[random_error] + 1;
        printf("An error has been added to the input.\n");
        
        // Check if error has been detected by program
        bool error_detected = false;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (buffer[i] < 'a' || buffer[i] > 'z')
            {
                error_detected = true;
                break;
            }
        }
        if (error_detected)
        {
            printf("Error detected in input!\n");
            error_count++;
        }
        else
        {
            printf("Input is valid.\n");
        }
    }
    
    // Print final error count
    printf("Too many errors have been detected (%d). Program will terminate.\n", error_count);
    
    return 0;
}