//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SERVER "speedtest.cloudflare.com"

int main()
{
    int i, n, t, download_size, upload_size;
    float download_speed, upload_speed, average_speed;

    system("clear");

    printf("---------------------------------------------------------\n");
    printf("   Speedtest Application - Version 1.0\n");
    printf("---------------------------------------------------------\n");

    printf("Please wait for the test to complete...\n");

    n = 0;
    while (n < 3)
    {
        t = time(NULL);
        system("ping -c 1 " SERVER);
        t = time(NULL) - t;
        download_size = system("wget -O /dev/null " SERVER "/download") / 1024;
        upload_size = system("wget -O /dev/null -T 0 -c 1 " SERVER "/upload") / 1024;

        download_speed = (download_size * 8) / t;
        upload_speed = (upload_size * 8) / t;

        average_speed = (download_speed + upload_speed) / 2;

        printf("Test Number: %d\n", n + 1);
        printf("Download Speed: %.2f Mbps\n", download_speed);
        printf("Upload Speed: %.2f Mbps\n", upload_speed);
        printf("Average Speed: %.2f Mbps\n", average_speed);
        printf("\n");

        n++;
    }

    system("clear");

    printf("---------------------------------------------------------\n");
    printf("Thank you for using Speedtest Application - Version 1.0\n");
    printf("---------------------------------------------------------\n");

    return 0;
}