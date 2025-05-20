//FormAI DATASET v1.0 Category: System boot optimizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the C System Boot Optimizer!\n\n");
    printf("This program will help you improve the boot time of your system by optimizing the startup process.\n");
    printf("Are you ready to get started? (Y/N)\n");
    
    char answer;
    scanf("%c", &answer);
    
    if(answer == 'Y' || answer == 'y')
    {
        printf("\nGreat! Let's get to work.\n");
        
        printf("\nFirst, let's remove any unnecessary startup programs.\n");
        printf("Here are the current startup programs:\n");
        system("sudo systemctl list-unit-files --state=enabled");
        printf("\nEnter the name of the program you want to disable: ");
        
        char program[100];
        scanf("%s", program);
        char command[150] = "sudo systemctl disable ";
        strcat(command, program);
        system(command);
        
        printf("\nNext, let's check for any services that are slowing down the boot process.\n");
        system("systemd-analyze blame");
        printf("\nDo you want to disable any of the services? (Y/N)\n");
        
        scanf(" %c", &answer);
        
        if(answer == 'Y' || answer == 'y')
        {
            printf("\nWhich service do you want to disable? (Enter the name of the service)\n");
            char service[100];
            scanf("%s", service);
            char service_cmd[150] = "sudo systemctl disable ";
            strcat(service_cmd, service);
            system(service_cmd);
        }
        
        printf("\nLastly, let's clear the cache and swap space to improve system performance.\n");
        system("sudo sync && sudo sysctl -w vm.drop_caches=3");
        system("sudo swapoff -a && sudo swapon -a");
        
        printf("\nExcellent work! Your system boot time should be faster now.\n");
        
    }
    else
    {
        printf("\nThat's okay, come back any time when you're ready to optimize your system boot time!\n");
    }
    
    return 0;
}