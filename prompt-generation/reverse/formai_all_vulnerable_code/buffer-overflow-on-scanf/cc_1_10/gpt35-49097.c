//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIFI_STRENGTH 5  // Maximum Wi-Fi Signal Strength

int main()
{
    // Initialize an array to store Wi-Fi Signal Strengths
    int wifi_strength[MAX_WIFI_STRENGTH] = {0};
    
    // Get input from user for Wi-Fi Signal Strengths
    printf("Please enter the Wi-Fi Signal Strengths (between 1 and 5):\n");
    for (int i = 0; i < MAX_WIFI_STRENGTH; i++)
    {
        printf("Signal Strength %d: ", i+1);
        scanf("%d", &wifi_strength[i]);
    }
    
    // Calculate the average Wi-Fi Signal Strength
    float sum = 0;
    for (int i = 0; i < MAX_WIFI_STRENGTH; i++)
    {
        sum += wifi_strength[i];
    }
    float average = sum / MAX_WIFI_STRENGTH;
    
    // Print the Wi-Fi Signal Strength Analysis
    printf("\n");
    printf(">> Wi-Fi Signal Strength Analysis <<\n");
    printf("Average Signal Strength: %.2f\n", average);
    printf("Signal Strengths:\n");
    for (int i = 0; i < MAX_WIFI_STRENGTH; i++)
    {
        switch(wifi_strength[i])
      {
         case 1 :
            printf("%d. Poor Signal Strength\n", i+1);
            break;
         case 2 :
            printf("%d. Fair Signal Strength\n", i+1);
            break;
         case 3 :
            printf("%d. Good Signal Strength\n", i+1);
            break;
         case 4 :
            printf("%d. Very Good Signal Strength\n", i+1);
            break;
         case 5 :
            printf("%d. Excellent Signal Strength\n", i+1);
            break;
      }
    }
    
    return 0;
}