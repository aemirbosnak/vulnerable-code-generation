//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int number_of_seconds) { 

    // Converting time into milliseconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // Looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int main()
{
    int score=0;
    
    printf("Welcome to the Periodic Table Quiz. Let's get started!\n\n");
    delay(2);
    printf("Question 1:\nWhat is the symbol for Helium?\n");
    delay(1);
    printf("A. He\nB. Hl\nC. Hm\nD. Ho\nAnswer: ");
    char answer1=getchar();
    if(answer1=='A' || answer1=='a')
    {
        printf("\nCorrect! Helium's symbol is He.\n");
        score+=10;
    }
    else
    {
        printf("\nWrong! Helium's symbol is He.\n");
    }
    delay(2);
    
    printf("\nQuestion 2:\nWhat is the atomic number of Oxygen?\n");
    delay(1);
    printf("A. 16\nB. 6\nC. 8\nD. 12\nAnswer: ");
    char answer2=getchar();
    if(answer2=='C' || answer2=='c')
    {
        printf("\nCorrect! The atomic number of Oxygen is 8.\n");
        score+=10;
    }
    else
    {
        printf("\nWrong! The atomic number of Oxygen is 8.\n");
    }
    delay(2);
    
    printf("\nQuestion 3:\nWhich element has the symbol 'Pb'?\n");
    delay(1);
    printf("A. Potassium\nB. Lead\nC. Phosphorus\nD. Platinum\nAnswer: ");
    char answer3=getchar();
    if(answer3=='B' || answer3=='b')
    {
        printf("\nCorrect! Pb is the symbol for Lead.\n");
        score+=10;
    }
    else
    {
        printf("\nWrong! Pb is the symbol for Lead.\n");
    }
    delay(2);
    
    printf("\nQuestion 4:\nWhat is the element with atomic number 79?\n");
    delay(1);
    printf("A. Gold\nB. Silver\nC. Copper\nD. Iron\nAnswer: ");
    char answer4=getchar();
    if(answer4=='A' || answer4=='a')
    {
        printf("\nCorrect! 79 is the atomic number of Gold.\n");
        score+=10;
    }
    else
    {
        printf("\nWrong! 79 is the atomic number of Gold.\n");
    }
    delay(2);
    
    printf("\nQuestion 5:\nWhich of the following is a noble gas?\n");
    delay(1);
    printf("A. Carbon\nB. Nitrogen\nC. Oxygen\nD. Argon\nAnswer: ");
    char answer5=getchar();
    if(answer5=='D' || answer5=='d')
    {
        printf("\nCorrect! Argon is a noble gas.\n");
        score+=10;
    }
    else
    {
        printf("\nWrong! Argon is a noble gas.\n");
    }
    delay(2);
    
    printf("\n\nYour total score is: %d out of 50.\nThank you for playing!\n\n", score);
    return 0;
}