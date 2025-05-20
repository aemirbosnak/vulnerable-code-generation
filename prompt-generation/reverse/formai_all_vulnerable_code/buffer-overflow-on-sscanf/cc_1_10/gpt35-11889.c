//FormAI DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_MESSAGES 100

struct email
{
    char sender[100];
    char receiver[100];
    char subject[100];
    char message[BUFFER_SIZE];
};

int main()
{
    struct email messages[MAX_MESSAGES];
    int message_count = 0;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    while (1)
    {
        printf("Email Client> ");
        fgets(buffer, BUFFER_SIZE, stdin);
        sscanf(buffer, "%s", command);

        if (strcmp(command, "compose") == 0)
        {
            struct email em;
            printf("Sender: ");
            fgets(em.sender, 100, stdin);
            printf("Receiver: ");
            fgets(em.receiver, 100, stdin);
            printf("Subject: ");
            fgets(em.subject, 100, stdin);
            printf("Message: ");
            fgets(em.message, BUFFER_SIZE, stdin);
            printf("Email sent!\n");
            messages[message_count++] = em;
        }
        else if (strcmp(command, "inbox") == 0)
        {
            if (message_count == 0)
            {
                printf("Inbox is empty.\n");
            }
            else
            {
                for (int i = 0; i < message_count; i++)
                {
                    printf("From: %s\n", messages[i].sender);
                    printf("To: %s\n", messages[i].receiver);
                    printf("Subject: %s\n", messages[i].subject);
                    printf("Message: %s\n", messages[i].message);
                }
            }
        }
        else if (strcmp(command, "quit") == 0)
        {
            break;
        }
        else
        {
            printf("Unknown command.\n");
        }
    }

    return 0;
}