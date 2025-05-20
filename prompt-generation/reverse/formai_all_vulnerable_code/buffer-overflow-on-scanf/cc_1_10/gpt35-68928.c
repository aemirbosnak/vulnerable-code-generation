//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//Function to check website status
int check_url_status(char *url) 
{
    int status = system("ping -c 1 -w 2 google.com >/dev/null 2>&1");
    if(status == 0)
    {
        printf("%s is up and running!\n", url);
        return 1;
    }
    else
    {
        printf("%s is down.\n", url);
        return 0;
    }
}

//Recursive function to monitor website uptime
void monitor_website(char* url, int interval) 
{
    int status = check_url_status(url);
    if(status == 0)
    {
        printf("Trying to reconnect in %d seconds...\n", interval);
        sleep(interval);
        monitor_website(url, interval);
    }
    else
    {
        printf("Checking again in %d seconds...\n", interval);
        sleep(interval);
        monitor_website(url, interval);
    }
}

int main() 
{
    char url[100];
    int interval;

    printf("Enter the URL to monitor: ");
    scanf("%s", url);

    printf("Enter the polling interval (in seconds): ");
    scanf("%d", &interval);

    monitor_website(url, interval);

    return 0;
}