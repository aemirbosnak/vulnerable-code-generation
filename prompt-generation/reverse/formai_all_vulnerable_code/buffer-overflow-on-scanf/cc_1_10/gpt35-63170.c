//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to simulate internet speed Test
void simulateInternetSpeedTest()
{
    // generate random download speed and upload speed
    srand(time(NULL));
    int downloadSpeed = rand() % 100 + 1;
    int uploadSpeed = rand() % 100 + 1;

    printf("Performing Internet Speed Test. Please wait...\n\n");

    printf("Download Speed: %d Mbps\n", downloadSpeed);
    printf("Upload Speed: %d Mbps\n\n", uploadSpeed);

    // check if the internet speed is slow or fast
    if(downloadSpeed < 50 || uploadSpeed < 50)
    {
        printf("Your internet speed seems to be slow. We recommend you to upgrade your connection.\n");
    }
    else
    {
        printf("Your internet speed is satisfactory. You can continue browsing without any issues.\n");
    }
}

int main()
{
    printf("Welcome to the Medieval Internet Speed Test!\n");
    printf("We will simulate the internet speed test using our magical stones\n");
    printf("And let you know if your internet speed is fast or slow!\n");

    // ask the user if they want to perform the internet speed test
    char response;
    printf("Do you want to perform the internet speed test? (Y/N): ");
    scanf(" %c", &response);

    if(response == 'Y' || response == 'y')
    {
        // simulate the internet speed test
        simulateInternetSpeedTest();
    }
    else
    {
        printf("As you wish, my lord!\n");
    }

    return 0;
}