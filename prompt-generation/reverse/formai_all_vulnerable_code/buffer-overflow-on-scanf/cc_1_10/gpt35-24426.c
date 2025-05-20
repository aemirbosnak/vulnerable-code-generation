//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complex
#include<stdio.h>

int main()
{
    int x = 1;
    char name[20],choice;
    int wifi_strength = 0;
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");
    printf("Please enter your name: ");
    scanf("%s", &name);
    printf("\nHello, %s! \n\n", name);
    while(x == 1)
    {
        printf("Please select an option:\n");
        printf("A. Measure the Wi-Fi signal strength\n");
        printf("B. Analyze the Wi-Fi signal strength\n");
        printf("C. Exit the program\n");
        printf("Choice: ");
        scanf("%c", &choice);
        switch(choice)
        {
            case 'A':
                printf("Measuring Wi-Fi signal strength...\n\n");
                // Code to measure Wi-Fi signal strength
                wifi_strength = (rand() % 100) + 1; // Random value between 1 to 100
                printf("Wi-Fi signal strength: %d\n\n", wifi_strength);
                break;
            case 'B':
                printf("Analyzing Wi-Fi signal strength...\n\n");
                if(wifi_strength < 50)
                {
                    printf("Poor Wi-Fi signal strength\n\n");
                }
                else if(wifi_strength >= 50 && wifi_strength < 80)
                {
                    printf("Average Wi-Fi signal strength\n\n");
                }
                else
                {
                    printf("Good Wi-Fi signal strength\n\n");
                }
                break;
            case 'C':
                printf("Exiting program...\n\n");
                x = 0;
                break;
            default:
                printf("Invalid choice\n\n");
                break;
        }
    }
    return 0;
}