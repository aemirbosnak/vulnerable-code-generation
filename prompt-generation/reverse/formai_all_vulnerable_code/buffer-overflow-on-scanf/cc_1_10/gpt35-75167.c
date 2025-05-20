//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    // welcome message
    printf("Welcome to the Curious Internet Speed Test Application!\n\n");

    // user's name input
    printf("May I know your name? ");
    char user_name[50];
    scanf("%s", user_name);
    printf("\nHi, %s! Let's get started.\n", user_name);

    // random server selection
    char servers[5][20] = {"New York", "London", "Tokyo", "Sydney", "Moscow"};
    srand(time(0));
    int server_index = rand() % 5;
    char selected_server[20];
    strcpy(selected_server, servers[server_index]);

    // display selected server
    printf("\nThe closest server to you is located in %s.\n", selected_server);

    // emulate internet speed test
    int test_duration = rand() % 10 + 5;
    printf("\nWe will now emulate an internet speed test for %d seconds.\n", test_duration);
    int test_progress = 0;
    while (test_progress < test_duration)
    {
        printf("\nTesting internet speed...");
        int speed = rand() % 100 + 1;
        printf(" %d Mbps\n", speed);
        test_progress++;
    }

    // display results
    printf("\n\nThank you, %s! Here are your results for the speed test on %s:\n", user_name, selected_server);
    int download_speed = rand() % 100 + 1;
    int upload_speed = rand() % 100 + 1;
    printf("\nDownload Speed: %d Mbps", download_speed);
    printf("\nUpload Speed: %d Mbps", upload_speed);

    // suggestions for user
    if (download_speed < 10 || upload_speed < 10)
    {
        printf("\n\nYour internet speed seems to be slow. You may want to contact your service provider for assistance.");
    }
    else if (download_speed < 50 || upload_speed < 50)
    {
        printf("\n\nYour internet speed is decent, but there is room for improvement. You may want to consider upgrading your internet plan.");
    }
    else
    {
        printf("\n\nCongratulations, %s! Your internet speed is great!", user_name);
    }

    return 0;
}