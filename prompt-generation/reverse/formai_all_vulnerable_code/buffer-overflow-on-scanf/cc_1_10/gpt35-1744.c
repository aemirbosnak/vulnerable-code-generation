//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
/* Romeo and Juliet Intrusion Detection System */
/* Verona Cyber Security Team */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3
#define MAX_PASSWORD_LENGTH 12

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int attempts = 0;
    int intrusion_detected = 0;

    printf("Oh Romeo, where art thou? \n");
    printf("I am Juliet, and I shall protect our system from intrusion. \n");

    while (attempts < MAX_ATTEMPTS && intrusion_detected == 0)
    {
        printf("\nSpeak, password, and enter. \n");
        scanf("%s", password);

        if (strcmp(password, "rosaline") == 0)
        {
            printf("Alack, the password was correct. \n");
            intrusion_detected = 1;
            break;
        }
        else
        {
            printf("Not lik'd, password is incorrect. \n");
            attempts++;
        }
    }

    if (intrusion_detected == 1)
    {
        printf("\nOh woe, an intrusion has been detected! \n");
        printf("Notify the watchmen, and bring the battle to him! \n");
    }
    else
    {
        printf("\nThy three attempts are over, and thou art locked out. \n");
        printf("Farewell, goest hence from our system. \n");
    }

    return 0;
}