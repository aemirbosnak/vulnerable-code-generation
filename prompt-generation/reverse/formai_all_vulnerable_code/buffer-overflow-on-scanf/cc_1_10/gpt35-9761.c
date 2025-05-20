//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    printf("Welcome to the Brave Speed Test App!\n");

    int download_speed, upload_speed;
    char input;

    do
    {
        srand(time(NULL));

        int random_num = (rand() % 30) + 10;

        printf("Testing your download speed...\n");
        printf("Please wait for %d seconds...\n", random_num);

        sleep(random_num);

        download_speed = rand() % 101;

        printf("Your download speed is %d mbps.\n", download_speed);

        printf("Testing your upload speed...\n");
        printf("Please wait for %d seconds...\n", random_num);

        sleep(random_num);

        upload_speed = rand() % 101;

        printf("Your upload speed is %d mbps.\n", upload_speed);

        if (download_speed > 50 && upload_speed > 50)
        {
            printf("You have incredibly fast internet speed!\n");
        }
        else if ((download_speed > 20 && download_speed <= 50) && (upload_speed > 20 && upload_speed <= 50))
        {
            printf("You have decent internet speed!\n");
        }
        else
        {
            printf("Your internet speed needs improvement!\n");
        }

        printf("Do you want to perform the speed test again? (y/n):\n");
        scanf(" %c", &input);
    }
    while (input == 'y' || input == 'Y');

    printf("Thank you for using the Brave Speed Test App!\n");

    return 0;
}