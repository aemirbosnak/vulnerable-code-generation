//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(unsigned int milliseconds) //function used to introduce delay in milliseconds
{
    clock_t goal = milliseconds + clock();
    while (goal > clock());
}

int main()
{
    char input, currentChar;
    int count = 0, correctCount = 0, wrongCount = 0, totalTime = 0, totalChars = 0;
    time_t startTime, endTime;
    double timeTaken;

    printf("Welcome to the ultimate typing test!\n\n");
    printf("You will have to type as many characters accurately and as fast as you can within a given time limit.\n\n");
    
    while(1) //infinite loop
    {
        printf("Please enter the time limit (in seconds) for the typing test (minimum 10 seconds): ");
        int timeLimit;
        scanf("%d", &timeLimit);
        if(timeLimit < 10)
        {
            printf("\nPlease enter a value greater than or equal to 10 seconds.\n\n");
            continue;
        }
        printf("\nPress enter to start the typing test...\n\n");
        getchar();
        getchar(); //to clear out the newline character left in the input buffer
        
        srand(time(NULL)); //to set the random seed based on current time
        
        startTime = time(NULL); //get current time as start time
        
        while(difftime(time(NULL), startTime) < timeLimit)
        {
            currentChar = rand() % 93 + 33; //generate a random character between ASCII 33 (!) and 126 (~)
            printf("%c", currentChar); //print the character
            
            input = getchar(); //get the user input
            
            if(input == currentChar) //if input matches the current character
            {
                printf("\033[0;32m"); //set text color to green to indicate correct input
                correctCount++; //increment correct count
            }
            else //if input doesn't match
            {
                printf("\033[0;31m"); //set text color to red to indicate wrong input
                wrongCount++; //increment wrong count
            }
            
            printf("%c", input); //print the input character in the corresponding color
            printf("\033[0m"); //reset text color
            
            if(input == '\n') //if user presses enter key
            {
                printf("\n"); //move to next line
            }
            
            count++; //increment total count
            totalChars++; //increment total chars count
        }
        
        endTime = time(NULL); //get current time as end time
        timeTaken = difftime(endTime, startTime); //calculate time taken for the typing test in seconds
        
        totalTime += timeTaken; //add the time taken for this test to the total time
        
        printf("\n\nTime taken: %.2f seconds.\n\n", timeTaken);
        printf("Total characters typed: %d\n", totalChars);
        printf("Correct characters typed: %d\n", correctCount);
        printf("Wrong characters typed: %d\n", wrongCount);
        printf("Accuracy: %.2f %%\n", ((float)correctCount/totalChars)*100); //calculate and print accuracy percentage
        printf("Typing speed: %.2f characters per minute.\n\n", ((float)count/timeTaken)*60); //calculate and print typing speed in characters per minute
        
        printf("Would you like to try again? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        
        if(choice == 'y' || choice == 'Y')
        {
            continue; //continue to restart the typing test
        }
        else
        {
            break; //break out of the infinite loop to exit the program
        }
    }
    
    printf("\nThank you for using the ultimate typing test!\n\n");
    
    return 0;
}