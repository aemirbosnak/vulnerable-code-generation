//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to shuffle a string
void shuffle(char *str)
{
    int n = strlen(str);
    srand(time(NULL));
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
}

// Function to calculate time elapsed
double elapsed_time(struct timespec start, struct timespec end)
{
    return (double)(end.tv_sec - start.tv_sec) + ((double)(end.tv_nsec - start.tv_nsec)) / (double)1000000000;
}

int main()
{
    char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen(str);
    shuffle(str); // Shuffle the string
    printf("Type the above characters as fast as you can:\n");
    printf("%s\n", str);

    // Get user input
    char input[100];
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    scanf("%s", input);
    clock_gettime(CLOCK_REALTIME, &end);

    double time_elapsed = elapsed_time(start, end);
    int correct = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == input[i])
        {
            correct++;
        }
    }

    printf("You typed %d out of %d characters correctly in %.2f seconds.\n", correct, len, time_elapsed);
    printf("Your typing speed is %.2f characters per second.\n", (double)correct / time_elapsed);

    return 0;
}