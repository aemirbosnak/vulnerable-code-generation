//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void printHeader() {
    printf("###############################################\n");
    printf("##                                           ##\n");
    printf("##  CPU Usage Monitor - Elementary, my dear!  ##\n");
    printf("##                                           ##\n");
    printf("###############################################\n\n");
}

int main() {
    char topOutput[1024];
    float cpuUsage;
    int counter = 0;

    while (1) {
        system("top -b -n 1 | grep 'Cpu(s)' > topOutput.txt");
        FILE* fp = fopen("topOutput.txt", "r");
        fgets(topOutput, sizeof(topOutput), fp);
        char* token = strtok(topOutput, " ");
        int i = 0;
        while (token != NULL) {
            if (i == 1) {
                cpuUsage = atof(token);
            }
            i++;
            token = strtok(NULL, " ");
        }
        fclose(fp);

        printf("CPU Usage: %.2f%%\n", cpuUsage);
        if (cpuUsage >= 80.0) {
            printf("\nIt looks like the CPU is being heavily utilized. Let's investigate.\n\n");

            printf("Suspect #1: Google Chrome\n");
            printf("Suspect #2: Visual Studio Code\n");
            printf("Suspect #3: Spotify\n");
            printf("Suspect #4: Discord\n\n");

            printf("Who would you like to interrogate? ");

            char input[20];
            scanf("%s", input);

            if (strcmp(input, "Google Chrome") == 0 || strcmp(input, "chrome") == 0) {
                printf("\nGoogle Chrome has been put on trial for high CPU utilization.\n");
                printf("After investigating, it has been found that the suspect had multiple tabs with heavy media content which caused the CPU to run at high usage.\n");
                printf("Guilty as charged!\n\n");
            } else if (strcmp(input, "Visual Studio Code") == 0 || strcmp(input, "vs code") == 0) {
                printf("\nVisual Studio Code has been put on trial for high CPU utilization.\n");
                printf("After investigating, it has been found that the suspect had multiple extensions running which caused the CPU to run at high usage.\n");
                printf("Guilty as charged!\n\n");
            } else if (strcmp(input, "Spotify") == 0 || strcmp(input, "spotify") == 0) {
                printf("\nSpotify has been put on trial for high CPU utilization.\n");
                printf("After investigating, it has been found that the suspect was playing high definition music which caused the CPU to run at high usage.\n");
                printf("Not guilty!\n\n");
            } else if (strcmp(input, "Discord") == 0 || strcmp(input, "discord") == 0) {
                printf("\nDiscord has been put on trial for high CPU utilization.\n");
                printf("After investigating, it has been found that the suspect was running multiple servers which caused the CPU to run at high usage.\n");
                printf("Not guilty!\n\n");
            } else {
                printf("\nUnknown suspect! Let's continue to monitor the CPU usage.\n\n");
            }
        }

        counter++;
        sleep(1);
        if (counter >= 30) {
            printf("\nIt looks like the CPU usage monitor has been running for too long. Let's terminate the program.\n");
            break;
        }
    }
    return 0;
}