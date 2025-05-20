//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(unsigned int mseconds) //function for delay
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main()
{
    int i,j;
    float size;
    clock_t start, end;
    double time_taken;
    
    printf("\nEnter the size of file to be downloaded in MB: ");
    scanf("%f", &size);  //User input of file size
    
    int speed[10]; //Array to store speed values for 10 trials
    
    printf("\nPlease wait while running the test...\n\n"); 
    
    for(i=0;i<10;i++) //Loop for 10 trials
    {
        start = clock(); //Start time for trial
                
        //Simulating download process using delay function
        for(j=0;j<size*1024*1024/10;j++)
        {
            delay(1);
        }
        
        end = clock(); //End time for trial 
        time_taken = (double)(end-start)/CLOCKS_PER_SEC; //Calculating time taken for trial in seconds
        speed[i] = size/time_taken*8; //Calculating speed in Mbps and storing in array
        
        printf("Trial %d: %d Mbps\n", i+1, speed[i]); //Displaying speed for each trial
    }
    
    int sum=0, avg;
    
    for(i=0;i<10;i++) //Calculating average of speeds from all trials
    {
        sum += speed[i];
    }
    
    avg = sum/10;
    
    printf("\nAverage speed: %d Mbps\n", avg); //Displaying average speed
    
    return 0;
}