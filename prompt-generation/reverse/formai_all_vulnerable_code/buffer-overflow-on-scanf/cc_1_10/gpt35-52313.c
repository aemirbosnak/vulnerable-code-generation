//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: careful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_INPUT_SIZE 1000 //Maximum input size
#define MAX_MEMORY_SIZE 10000 //Maximum memory size
#define PATTERN_SIZE 4 //Pattern size

char input[MAX_INPUT_SIZE];
char memory[MAX_MEMORY_SIZE];
int pattern[PATTERN_SIZE];
int pos;

//Checking if the current input matches with previous M characters
int check(int m)
{
    for(int i=0;i<m;i++)
    {
        if(input[pos-i-1]!=memory[MAX_MEMORY_SIZE-m+i])
            return 0;
    }
    return 1;
}

int main()
{
    //Initializing all memory locations with -1
    memset(memory,-1,MAX_MEMORY_SIZE);

    //Reading pattern from the user
    printf("Enter pattern of size %d: ",PATTERN_SIZE);
    for(int i=0;i<PATTERN_SIZE;i++)
        scanf("%d",&pattern[i]);

    //Reading input from the user
    printf("Enter input: ");
    scanf("%s",input);

    //Iterating over each character in the input
    for(int i=0;i<strlen(input);i++)
    {
        int intrusion = 1; //Flag variable to determine intrusion

        //Storing current input character in memory
        memory[pos]=input[i];
        pos=(pos+1)%MAX_MEMORY_SIZE;

        if(i>=PATTERN_SIZE-1)
        {
            //Checking if the current input matches with the pattern
            for(int j=0;j<PATTERN_SIZE;j++)
            {
                if(memory[(pos-1-j+MAX_MEMORY_SIZE)%MAX_MEMORY_SIZE]!=pattern[j])
                {
                    intrusion = 0;
                    break;
                }
            }

            //Checking if the current input matches with the previous M characters
            if(check(PATTERN_SIZE) && intrusion)
            {
                printf("Intrusion detected at position %d\n",i-PATTERN_SIZE+1);
                break;
            }
        }
    }

    if(pos<MAX_MEMORY_SIZE-PATTERN_SIZE)
        printf("No intrusion detected\n");

    return 0;
}