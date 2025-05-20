//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int i, j, k, min, sec, total_time, typing_time, accuracy;
    char passage[200];
    char input_str[200];

    // Cyberpunk style UI
    printf("--------------------------------------\n");
    printf("    CYBERPUNK TYPING SPEED TEST\n");
    printf("--------------------------------------\n\n");

    // Generates a random passage for the test
    srand(time(0));
    char passages[][200] = {"The quick brown fox jumps over the lazy dog",
                            "Fear is the mind killer",
                            "Give me Liberty or Give me Death",
                            "We are what we repeatedly do",
                            "The future is already here, it's just not very evenly distributed"};
    strcpy(passage, passages[rand() % 5]);
    printf("Type the following passage:\n\n%s\n\n", passage);

    // Starts the timer
    printf("Press Enter to start the timer...");
    getchar();
    time_t start = time(NULL);

    // User types the passage
    printf("\nStart Typing here...\n\n");
    fgets(input_str, sizeof(input_str), stdin);

    // Ends the timer
    time_t end = time(NULL);
    total_time = end - start;
    min = total_time / 60;
    sec = total_time % 60;
    typing_time = strlen(input_str) / 5; // 5 characters per second typing speed
    accuracy = ((strlen(passage) - abs((int)strlen(passage) - (int)strlen(input_str))) / strlen(passage)) * 100;

    // Results
    printf("\n\n--------------------------------------\n");
    printf("TYPING SPEED TEST RESULTS\n");
    printf("--------------------------------------\n");
    printf("Passage: %s\n", passage);
    printf("You typed: %s\n", input_str);
    printf("Time Taken: %d minutes and %d seconds\n", min, sec);
    printf("Typing Time: %d seconds\n", typing_time);
    printf("Accuracy: %d%%\n", accuracy);

    return 0;
}