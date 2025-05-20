//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int);
void print_line();

int main()
{
    printf("Welcome to the Internet Speed Test Application\n\n");
    printf("Please wait while we check your internet speed...\n\n");
    delay(3000); // Pausing program for 3 seconds to mimic internet speed check
    
    printf("Test complete!\n\n");
    printf("Here are your results:\n\n");
    
    int download_speed = rand() % 101; // Generating a random download speed from 0 to 100
    int upload_speed = rand() % 101; // Generating a random upload speed from 0 to 100
    
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n\n", upload_speed);
    
    if(download_speed < 10 || upload_speed < 10)
    {
        printf("Uh oh, looks like your internet speed is very slow!\n");
        printf("Please contact your service provider to improve your connection.\n\n");
    }
    else if(download_speed >= 10 && download_speed < 50 || upload_speed >= 10 && upload_speed < 50)
    {
        printf("Your internet speed is average, but it could be better.\n");
        printf("Consider upgrading your service plan or contacting your provider for assistance.\n\n");
    }
    else
    {
        printf("Congratulations! Your internet speed is excellent.\n");
        printf("You can enjoy fast internet browsing and downloads.\n\n");
    }
    
    printf("Thank you for using the Internet Speed Test Application!");
    return 0;
}

void delay(int milliseconds)
{
    clock_t start_time = clock(); // Get starting clock time
    while(clock() < start_time + milliseconds);
}

void print_line()
{
    for(int i=0; i<80; i++)
        printf("-");
    printf("\n");
}