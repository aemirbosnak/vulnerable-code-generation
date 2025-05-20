//FormAI DATASET v1.0 Category: System administration ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    //Declaring Variables
    int i, j, k, key;
    char op = 'y';
    while(op == 'y' || op == 'Y'){
        system("clear"); //Clearing the screen
        printf("Choose an option:\n");
        printf("1. Check System Information\n");
        printf("2. Modify System Information\n");
        scanf("%d",&key);
        switch(key){
            case 1:{
                printf("Hostname:\n");
                system("hostname");
                printf("\n");
                printf("IP Address:\n");
                system("ifconfig | grep 'inet ' | grep -v 127.0.0.1 | awk '{print $2}'");
                printf("\n");
                printf("Memory Information:\n");
                system("free -h");
                printf("\n");
                break;
            }
            case 2:{
                printf("What would you like to do?\n");
                printf("1. Modify hostname\n");
                printf("2. Restart Network Interface\n");
                printf("3. Check Current Open Ports\n");
                scanf("%d",&k);
                switch(k){
                    case 1:{
                        char hostname[30];
                        printf("Please enter a hostname:\n");
                        scanf("%s",hostname);
                        char command[60];
                        sprintf(command,"sudo hostnamectl set-hostname %s",hostname);
                        system(command);
                        printf("Hostname changed successfully.\n");
                        break;
                    }
                    case 2:{
                        system("sudo ifdown ens33");
                        sleep(5);
                        system("sudo ifup ens33");
                        printf("Network Interface has been restarted successfully.\n");
                        break;
                    }
                    case 3:{
                        system("netstat -tln");
                        break;
                    }
                    default:{
                        printf("Invalid Choice. Please choose a valid option.");
                        break;
                    }
                }
                break;
            }
            default:{
                printf("Invalid Option. Please choose a valid option.\n");
                break;
            }
        }
        printf("Would you like to continue?(y/n)\n");
        scanf(" %c",&op);
    }
    return 0;
}