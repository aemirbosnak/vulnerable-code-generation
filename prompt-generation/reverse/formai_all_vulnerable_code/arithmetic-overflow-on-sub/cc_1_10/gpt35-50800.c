//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char input_char;
    int i = 0, correct_answers = 0, incorrect_answers = 0;
    clock_t start_time, end_time;
    double elapsed_time;
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a random letter from the alphabet to type.\n");
    printf("To exit the program, simply type 'q'\n\n");
    
    while (input_char != 'q')
    {
        srand(time(0));
        int rand_index = rand() % 26;
        char rand_char = alphabet[rand_index];
        printf("Type the letter: %c\n", rand_char);
        
        start_time = clock();
        scanf(" %c", &input_char);
        end_time = clock();
        
        if (input_char == rand_char)
        {
            printf("Correct!\n");
            correct_answers++;
        }
        else if (input_char == 'q')
        {
            continue;
        }
        else
        {
            printf("Incorrect.\n");
            incorrect_answers++;
        }
        i++;
        
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Time elapsed: %.2f seconds\n", elapsed_time);
        printf("Accuracy: %.2f%%\n\n", ((double)correct_answers / i) * 100);
    }
    
    printf("Thank you for taking the Typing Speed Test!\n");
    printf("Here are your results:\n");
    printf("Correct Answers: %d\n", correct_answers);
    printf("Incorrect Answers: %d\n", incorrect_answers);
    printf("Accuracy: %.2f%%\n", ((double)correct_answers / (correct_answers + incorrect_answers)) * 100);
    
    return 0;
}