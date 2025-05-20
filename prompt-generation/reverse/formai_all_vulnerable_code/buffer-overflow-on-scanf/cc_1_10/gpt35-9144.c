//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

//function declaration
void startTest();
int generateRandomNumber(int rangeLow, int rangeHigh);
bool checkAnswer(char userChar, char correctChar);
void showResult(int correctCount, int wrongCount, float typingSpeed);

int main()
{
    char choice;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Do you want to take the typing test? (Y/N)\n");
    scanf("%c", &choice);

    if(choice == 'Y' || choice == 'y')
    {
        startTest();
    }
    else
    {
        printf("Thank you for considering the Typing Speed Test. Have a nice day!\n");
    }

    return 0;
}

//function to start the typing test
void startTest()
{
    char userInput, answer;
    int correctCount = 0, wrongCount = 0;
    float typingSpeed;
    int startTime, endTime;
    int i;

    printf("Get Ready to take the Typing Test..\n");
    printf("You will be given 10 random characters to type as fast as you can.\n");
    printf("Press ENTER to start the test:\n");
    fflush(stdin);
    getchar();

    //start time
    startTime = clock();

    //game loop
    for(i=1;i<=10;i++)
    {   
        fflush(stdin);
        //random character generation
        answer = (char)generateRandomNumber(97, 122);
        printf("\nCharacter %d: %c\n", i, answer);

        //user input
        scanf("%c", &userInput);
        //checking the user input
        bool result = checkAnswer(userInput, answer);
        if(result == true)
        {
            correctCount++;
            printf("Correct!");
        }
        else
        {
            wrongCount++;
            printf("Wrong! The correct character was '%c'", answer);
        }
    }
    //end time
    endTime = clock();

    //calculating typing speed
    typingSpeed = ((float)correctCount/((float)(endTime - startTime)/CLOCKS_PER_SEC))*60;

    //displaying results
    showResult(correctCount, wrongCount, typingSpeed);
}

//function to generate random numbers
int generateRandomNumber(int rangeLow, int rangeHigh)
{
    int randomNum = rand() % (rangeHigh-rangeLow+1) + rangeLow;
    return randomNum;
}

//function to check the user answer
bool checkAnswer(char userChar, char correctChar)
{
    if(userChar == correctChar)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function to show the result of the test
void showResult(int correctCount, int wrongCount, float typingSpeed)
{
    printf("\n\nTyping Speed Test Results:\n");
    printf("----------------------------\n");
    printf("Correct Characters Typed Successfully: %d\n", correctCount);
    printf("Incorrect Characters Typed: %d\n", wrongCount);
    printf("Typing Speed: %.2f characters per minute\n\n", typingSpeed);
    printf("Thank you for taking the test. Have a nice day!\n");
}