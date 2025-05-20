//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include<stdio.h>
#include<time.h>

int main()
{
    char ch, text[100];
    double time_taken, wpm, accuracy;
    int i, correct_chars, errors, total_chars;
    time_t start, end;
    
    printf("Welcome to the Typing Speed Test.\n\n");
    printf("You will be given a piece of text to type and your typing speed and accuracy will be evaluated.\n\n");
    printf("Press Enter to start the test...");
    getchar(); //waits for user to press Enter to start the test
    
    //Text for the typing test
    printf("Type the following text exactly as it is given:\n\n");
    printf("The quick brown fox jumps over the lazy dog.\n\n");
    printf("Press Enter to start typing the text...");
    getchar(); //waits for user to press Enter to start typing the test
    
    time(&start); //registers the start time of the test
    
    //Reads user input and calculates their typing speed and accuracy
    i = 0;
    correct_chars = 0;
    errors = 0;
    while((ch = getchar()) != '\n')
    {
        if(ch == text[i])
        {
            correct_chars++;
        }
        else
        {
            errors++;
        }
        
        i++;
    }
    
    time(&end); //registers the end time of the test
    time_taken = difftime(end, start); //calculates the time taken for the test in seconds
    total_chars = correct_chars + errors; //calculates the total characters typed
    
    //Calculates typing speed and accuracy
    wpm = (total_chars / 5.0) / (time_taken / 60.0);
    accuracy = (correct_chars / (double)total_chars) * 100.0;
    
    //Displays the results of the test
    printf("\n\nTest Results:\n");
    printf("Time taken: %.2lf seconds\n", time_taken);
    printf("Total characters typed: %d\n", total_chars);
    printf("Correct characters: %d\n", correct_chars);
    printf("Errors: %d\n", errors);
    printf("Typing speed: %.2lf words per minute\n", wpm);
    printf("Accuracy: %.2lf%%\n", accuracy);
    
    printf("\n\nThank you for taking the Typing Speed Test!\n");
    
    return 0;
}