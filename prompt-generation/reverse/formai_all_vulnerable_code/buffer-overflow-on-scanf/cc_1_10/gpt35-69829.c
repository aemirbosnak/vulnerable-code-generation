//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototype
void generateRandomString(char [], int);
int typingTest(char [], int, int);

int main()
{
    int stringLength, delay;
    char testString[100];

    printf("Enter the length of the test string: ");
    scanf("%d", &stringLength);

    printf("Enter the delay between characters (in ms): ");
    scanf("%d", &delay);

    generateRandomString(testString, stringLength);
    printf("Type the following string as fast as possible: %s\n", testString);

    int timeTaken = typingTest(testString, 0, delay);

    printf("\nCongratulations! You completed the typing test in %d seconds.\n", timeTaken);

    return 0;
}

// function to generate random string
void generateRandomString(char str[], int length)
{
    srand(time(NULL)); // seed rand with current time

    for (int i = 0; i < length; i++)
    {
        int charCode = rand() % 26 + 97; // randomly generate ascii code for lowercase letter
        str[i] = (char)charCode;
    }
    str[length] = '\0'; // add null terminator at end of string
}

// function to handle typing test
int typingTest(char str[], int idx, int delay)
{
    char c = getchar(); // wait for user to press enter to start test

    time_t startTime = time(NULL); // get current time

    if (idx == 0) // if first character, don't delay
    {
        putchar(str[idx]);
        return typingTest(str, idx + 1, delay);
    }
    else if (idx == strlen(str)) // finished typing string, return time taken
    {
        return time(NULL) - startTime;
    }
    else // type next character after delay
    {
        usleep(delay * 1000); // delay specified number of ms
        putchar(str[idx]);
        fflush(stdout); // flush output buffer
        return typingTest(str, idx + 1, delay);
    }
}