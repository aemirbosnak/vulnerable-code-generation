//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// Macros
#define MAX_STR_LEN 1000
#define MIN_STR_LEN 100
#define MAX_NUM_CHARS 100000

// Function prototypes
char *generateString(int len);
double calculateSpeed(char *str, double time);
void printResults(char *str, double time, double speed);

// Main function
int main()
{
    // Initialize variables
    char *str;
    double time, speed;
    int len;

    // Get the length of the string from the user
    printf("Enter the length of the string (between %d and %d): ", MIN_STR_LEN, MAX_STR_LEN);
    scanf("%d", &len);

    // Check if the length is valid
    if (len < MIN_STR_LEN || len > MAX_STR_LEN)
    {
        printf("Invalid length. Please enter a value between %d and %d.", MIN_STR_LEN, MAX_STR_LEN);
        return 1;
    }

    // Generate a random string
    str = generateString(len);

    // Get the current time
    time = clock();

    // Ask the user to type the string
    printf("Type the following string as quickly as possible:\n%s\n", str);

    // Wait for the user to finish typing
    getchar();

    // Get the current time again
    time = clock() - time;

    // Calculate the speed
    speed = calculateSpeed(str, time);

    // Print the results
    printResults(str, time, speed);

    // Free the memory allocated for the string
    free(str);

    return 0;
}

// Function to generate a random string
char *generateString(int len)
{
    // Initialize variables
    char *str;
    int i;

    // Allocate memory for the string
    str = (char *)malloc(sizeof(char) * (len + 1));

    // Generate a random string
    for (i = 0; i < len; i++)
    {
        str[i] = (char)((rand() % 26) + 97); // Generate a random lowercase letter
    }

    // Add the null terminator
    str[len] = '\0';

    // Return the string
    return str;
}

// Function to calculate the speed
double calculateSpeed(char *str, double time)
{
    // Calculate the number of characters
    double num_chars = strlen(str);

    // Calculate the elapsed time in seconds
    double elapsed_time = time / CLOCKS_PER_SEC;

    // Calculate the speed in characters per second
    double speed = num_chars / elapsed_time;

    // Return the speed
    return speed;
}

// Function to print the results
void printResults(char *str, double time, double speed)
{
    // Calculate the elapsed time in minutes and seconds
    int minutes = (int)floor(time / 60);
    int seconds = (int)floor(time - minutes * 60);

    // Print the results
    printf("String: %s\n", str);
    printf("Time: %d minutes and %d seconds\n", minutes, seconds);
    printf("Speed: %.2f characters per second\n", speed);
}