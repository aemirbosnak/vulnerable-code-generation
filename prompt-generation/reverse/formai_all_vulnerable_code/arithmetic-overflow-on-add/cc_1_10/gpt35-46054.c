//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int number_of_seconds) //function to create delay
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main()
{
    char para[1000] = "In a futuristic world, typing speed is the most valuable asset one can possess. Those who can type faster are eligible for higher paying jobs, better technology, and even a chance to enter elite schools. It is a world where typing is not a skill, but a necessity. Thus, a typing speed test is of utmost importance in this world where speed is everything. ";
    printf("Welcome to the Typing Speed Test!\n\n");
    delay(2);
    printf("You will be presented with a paragraph to type out.\n\n");
    delay(2);
    printf("Type the paragraph as quickly and accurately as you can.\n\n");
    delay(2);
    printf("Press Enter to Begin...");
    getchar();

    printf("\n\n%s\n\n", para);

    clock_t start_time, end_time;
    double time;
    int words_typed = 0, correct_words = 0, incorrect_words = 0, i = 0;
    char user_input[1000];
    start_time = clock();

    while (para[i] != '\0') 
    {
        if (para[i] == ' ') // for word count
            words_typed++;
        i++;
    }
    words_typed++;

    fgets(user_input, 1000, stdin); // taking input

    end_time = clock();
    time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    delay(2);
    printf("\n\nTime Taken: %.2f seconds\n", time);
    printf("Total Words Typed: %d\n", words_typed);

    // for comparing the input with the paragraph
    char *token;
    char para_copy[1000];
    strcpy(para_copy, para);
    token = strtok(para_copy, " ");
    while (token != NULL)
    {
        if (strstr(user_input, token) != NULL)
            correct_words++;
        else
            incorrect_words++;
        token = strtok(NULL, " ");
    }

    printf("Words Correctly Typed: %d\n", correct_words);
    printf("Words Incorrectly Typed: %d\n", incorrect_words);

    // Calculate wpm
    double wpm = (words_typed / time) * 60;
    printf("Speed: %.0f WPM\n\n", wpm);

    // The faster you type the better the reward
    if (wpm > 80)
    {
        delay(2);
        printf("Congratulations! You have a chance to enter an elite school.\n");
    }
    else if (wpm > 60 && wpm <= 80)
    {
        delay(2);
        printf("Good job! Advanced technology is now available to you.\n");
    }
    else if (wpm > 40 && wpm <= 60)
    {
        delay(2);
        printf("Not bad. You may be eligible for a higher paying job.\n");
    }
    else
    {
        delay(2);
        printf("You need to improve your speed to survive in this world. \n");
    }

    return 0;
}