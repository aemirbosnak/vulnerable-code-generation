//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char email_address[255];
    char subject[255];
    char message[255];

    printf("Good evening, Mr. Holmes. Please provide me with the email address you wish to check:");
    scanf("%s", email_address);

    printf("Excellent. Now, what is the subject of the email:");
    scanf("%s", subject);

    printf("Very well. Please provide me with the message you want me to read:");
    scanf("%s", message);

    // Begin by analyzing the email address
    if (strstr(email_address, "@bakerstreet.com") != NULL)
    {
        printf("My dear Watson, the email address appears to be from Baker Street.");
    }
    else
    {
        printf("The email address does not match Baker Street.");
    }

    // Now, let's examine the subject
    if (strcmp(subject, "Urgent") == 0)
    {
        printf("The subject is urgent, Mr. Holmes.");
    }
    else if (strcmp(subject, "Important") == 0)
    {
        printf("The subject is important, but not urgent.");
    }
    else
    {
        printf("The subject is not urgent or important.");
    }

    // Finally, let's analyze the message
    if (strstr(message, "Murder") != NULL)
    {
        printf("There is a possibility of murder, Mr. Holmes.");
    }
    else if (strstr(message, "Fraud") != NULL)
    {
        printf("There is evidence of fraud, Mr. Holmes.");
    }
    else
    {
        printf("There is no evidence of murder or fraud.");
    }

    printf("Well done, Mr. Holmes. You have successfully analyzed the email.");

    return 0;
}