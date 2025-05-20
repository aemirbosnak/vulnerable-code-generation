//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//get current time
time_t start, end;

//initialize variables for tracking user input and progress
int correct_characters = 0;
int total_characters = 0;

void typing_speed_test() {

    char input;
    char target_text[] = "The quick brown fox jumps over the lazy dog";

    //start timer
    time(&start);

    //print target text for user to type
    printf("Type this text as quickly and accurately as possible: \n");
    printf("%s \n", target_text);

    //loop through each character in target text and prompt user for their input
    for (int i = 0; i < sizeof(target_text); i++) {
        scanf(" %c", &input); //space before %c is added to ignore whitespace characters
        if (input == target_text[i]) {
            //if user input matches target text, increment correct character count
            correct_characters++;
        }
        total_characters++;
    }

    //calculate typing speed in words per minute and print results
    time(&end);
    double time_taken = end - start;
    double words_per_minute = (correct_characters / 5.0) / (time_taken / 60.0);
    printf("You typed %d out of %d characters correctly. \n", correct_characters, total_characters);
    printf("Your typing speed is %.2f words per minute. \n", words_per_minute);

}

int main() {

    printf("Welcome to the Typing Speed Test! \n");
    printf("Press enter to begin. \n");
    getchar(); //wait for user input
    typing_speed_test();

    return 0;

}