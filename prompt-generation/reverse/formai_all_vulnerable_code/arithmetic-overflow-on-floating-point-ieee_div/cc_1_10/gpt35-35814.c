//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog";
    int len = sizeof(text)/sizeof(text[0]) - 1; //exclude null terminator
    int i, j, errors = 0, time_taken;
    time_t start, end;

    srand(time(NULL)); //seed random number generator

    //shuffle letters in text randomly
    for (i = len-1; i > 0; i--) {
        j = rand() % (i+1);
        char temp = text[i];
        text[i] = text[j];
        text[j] = temp;
    }

    //display text to user
    printf("Type the following text as fast and as accurately as possible:\n%s\n", text);

    //start timer
    printf("Press any key to begin.\n");
    getchar();
    start = time(NULL);

    //prompt user for input and check for errors
    i = 0;
    while (i < len) {
        char input = getchar();
        if (input != text[i]) {
            errors++;
        }
        i++;
    }

    //end timer and calculate time taken
    end = time(NULL);
    time_taken = (int) difftime(end, start);

    //output results
    printf("Your typing speed results:\n");
    printf("Text length: %d characters\n", len);
    printf("Number of errors: %d\n", errors);
    printf("Time taken: %d seconds\n", time_taken);
    printf("Typing speed: %.2f characters per minute\n", (float) len/time_taken*60);

    return 0;
}