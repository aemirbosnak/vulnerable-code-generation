//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, i, j, k, flag = 0, count = 0;
    char name[20], surname[20], message[200];

    // Scene 1: Choosing sides
    printf("Enter 'R' for the Red family or 'B' for the Brown family: ");
    scanf("%c", &choice);

    // Scene 2: Registering participants
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your surname: ");
    scanf("%s", surname);

    // Scene 3: Sending a message
    printf("Enter your message: ");
    scanf("%s", message);

    // Scene 4: Sending the message
    if (choice == 'R')
    {
        for (i = 0; i < 10; i++)
        {
            printf("Sending message to the Red family...\n");
            printf("To: %s %s\n", name, surname);
            printf("Message: %s\n", message);
            count++;
        }
    }
    else if (choice == 'B')
    {
        for (j = 0; j < 10; j++)
        {
            printf("Sending message to the Brown family...\n");
            printf("To: %s %s\n", name, surname);
            printf("Message: %s\n", message);
            count++;
        }
    }
    else
    {
        flag = 1;
        printf("Invalid input. Please try again.\n");
    }

    // Scene 5: Checking for success
    if (flag == 0 && count >= 10)
    {
        printf("Message sent successfully!\n");
        printf("Total number of messages sent: %d\n", count);
    }

    return 0;
}