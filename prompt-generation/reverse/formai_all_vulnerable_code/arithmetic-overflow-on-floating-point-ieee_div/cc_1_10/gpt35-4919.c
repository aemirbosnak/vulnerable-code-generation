//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Function to calculate typing speed */
float typing_speed(int characters, float elapsed_time)
{
    float speed = 0.0;
    if(elapsed_time > 0.0)
    {
        speed = ((float)characters / elapsed_time) * 60.0;
    }
    return speed;
}

int main()
{
    int i, j, num_characters, correct_characters;
    char user_input[200];
    char generated_text[] = "The quick brown fox jumps over the lazy dog";
    float elapsed_time, typing_speed_result;

    printf("Welcome to the Typing Speed Test Program!\n");
    printf("You will be given a sentence to type, and your typing speed will be measured in words per minute.\n\n");

    printf("Please type the following sentence and press Enter:\n");
    printf("%s\n", generated_text);

    time_t start_time = time(NULL);
    fgets(user_input, sizeof(user_input), stdin);
    time_t end_time = time(NULL);

    elapsed_time = difftime(end_time, start_time);

    num_characters = strlen(generated_text);
    correct_characters = 0;

    /* count correct characters */
    for(i = 0; i < num_characters; i++)
    {
        if(generated_text[i] == user_input[i])
        {
            correct_characters++;
        }
    }

    typing_speed_result = typing_speed(correct_characters, elapsed_time);

    printf("\nYou typed \"%s\"\n\n", user_input);
    printf("Your typing speed is %.2f words per minute.\n", typing_speed_result);

    return 0;
}