//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: beginner-friendly
#include <stdio.h>

int main()
{
    int redTime, yellowTime, greenTime, currentTime, signal;
    
    printf("Enter red signal time: ");
    scanf("%d", &redTime);
    
    printf("Enter yellow signal time: ");
    scanf("%d", &yellowTime);
    
    printf("Enter green signal time: ");
    scanf("%d", &greenTime);
    
    signal = 1;
    currentTime = redTime;
    
    while(1)
    {
        switch(signal)
        {
            case 1:
                printf("Red signal: %d seconds\n", currentTime);
                break;
            case 2:
                printf("Yellow signal: %d seconds\n", currentTime);
                break;
            case 3:
                printf("Green signal: %d seconds\n", currentTime);
                break;
        }
        
        if(currentTime == 0)
        {
            signal++;
            
            if(signal > 3)
            {
                signal = 1;
            }
            
            switch(signal)
            {
                case 1:
                    currentTime = redTime;
                    break;
                case 2:
                    currentTime = yellowTime;
                    break;
                case 3:
                    currentTime = greenTime;
                    break;
            }
        }
        
        currentTime--;
    }
    
    return 0;
}