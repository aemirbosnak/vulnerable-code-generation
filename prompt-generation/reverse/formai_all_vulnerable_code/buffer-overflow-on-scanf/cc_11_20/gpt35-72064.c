//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include<stdio.h>//Header file for standard input/output functions
#include<stdlib.h>//Header file for exit(0) function

int main()
{
    int i, j, k, l, count;//Creating integer variables
    char ch;//Creating character variable
    
    printf("Welcome to Bingo Simulator!\n");//Welcoming user to the program
    printf("********************************\n");
    
    printf("\nDo you want to play? (y/n)");//Asking user if they want to play
    scanf("%c", &ch);//Taking input from user
    
    while(ch=='y' || ch=='Y')//Loop to ask user repeatedly if they want to play
    {
        int arr[5][5], num[25];//Creating arrays for storing random numbers and the 5x5 bingo board
        
        for(i=0;i<25;i++)//Loop to store numbers 1-25 in an array
            num[i]=i+1;
      
        for(i=0;i<5;i++)//Loop to generate random bingo board
        {
            for(j=0;j<5;j++)
            {
               k=rand() % 25;
               arr[i][j]=num[k];
               num[k]=0;
            }
       }
        
        printf("\nYour Bingo Board:\n");//Displaying user's bingo board
        
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
                printf("%d\t", arr[i][j]);//Displaying each number of the board
            printf("\n");
        }
                
        printf("\nPress any key to start playing...\n");//Prompting user to start playing
        getchar();
          
        printf("\nPress 'Enter' if the number on your board matches the randomly generated number, or 'N' to exit the game.\n");//Explaining the game to user
                  
        i=0;
        count=0;
            
        while(i<25)//Loop to generate random numbers and compare with the numbers on user's board
        {
            l=rand() % 25+1;//Generating random number
            printf("\nRandom Number Generated: %d\n",l);//Displaying random number
            printf("\nEnter 'Enter' or 'N'");
            ch=getchar();//Taking input from user
            getchar();
                  
            if(ch=='N' || ch=='n')//Checking if user pressed N to exit game
            {
                printf("\nThank You for playing Bingo Simulator.\n");//Thanking user for playing
                printf("****************************\n");
                exit(0);//Exiting program
            }
            
            for(j=0;j<5;j++)
            {
                for(k=0;k<5;k++)
                {
                    if(arr[j][k]==l)//Checking if the randomly generated number is on the user's board
                    {
                        arr[j][k]=0;//Replacing the matched number with 0
                        count++;//Increasing count of matched numbers
                        
                        if(count==5)//Checking if user has matched all 5 numbers to win the game
                        {
                            printf("\nYou Win!!!\n");//Displaying win message
                            printf("\nPress 'Y' to play again.\n");//Prompting user to play again
                            printf("Press 'N' to exit the game.\n");
                            scanf("%c", &ch);
                                    
                            if(ch=='N' || ch=='n')//Checking if user pressed N to exit game
                            {
                                printf("\nThank You for playing Bingo Simulator.\n");//Thanking user for playing
                                printf("****************************\n");
                                exit(0);//Exiting program
                            }
                            else//If user pressed Y to play again
                            {
                                count=0;//Resetting count of matched numbers
                                break;//Breaking inner loop
                            }
                        }
                        break;//Breaking inner loop
                        }                   
                    }
                    if(count==5)//Checking if user has matched all 5 numbers to win the game
                    {
                        printf("\nYou Win!!!\n");//Displaying win message
                        printf("\nPress 'Y' to play again.\n");//Prompting user to play again
                        printf("Press 'N' to exit the game.\n");
                        scanf("%c", &ch);
                        
                        if(ch=='N' || ch=='n')//Checking if user pressed N to exit game
                        {
                            printf("\nThank You for playing Bingo Simulator.\n");//Thanking user for playing
                            printf("****************************\n");
                            exit(0);//Exiting program
                        }
                        else//If user pressed Y to play again
                        {
                            count=0;//Resetting count of matched numbers
                            break;//Breaking inner loop
                        }
                    }
             }
             i++;//Increasing counter for number of rounds played
        }
    }
    printf("\nThank You for playing Bingo Simulator.\n");//Thanking user for playing
    printf("****************************\n");
    
    return 0;//Returning value to the operating system
}