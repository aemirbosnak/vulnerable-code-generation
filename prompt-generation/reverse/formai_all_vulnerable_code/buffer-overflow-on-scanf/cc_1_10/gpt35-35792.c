//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_even(int n)
{
   return (n % 2) == 0;
}

char* obfuscate(char* message)
{
    int length = strlen(message);
    char* result = malloc(sizeof(char) * length);

    for(int i = 0; i < length; i++) {
        if (is_even(i)) {
            result[i] = message[i] + 1;
        } else {
            result[i] = message[i] - 1;
        }
    }

    return result;
}

void send_mail(char* sender, char* recipient, char* message)
{
    char* obfuscated_message = obfuscate(message);

    printf("To: %s\n", recipient);
    printf("From: %s\n", sender);
    printf("Message: %s\n", obfuscated_message);

    free(obfuscated_message);
}

int main()
{
    char sender[255];
    char recipient[255];
    char message[255];

    printf("Please enter sender email address:\n");
    scanf("%s", sender);

    printf("Please enter recipient email address:\n");
    scanf("%s", recipient);

    printf("Please enter message:\n");
    scanf("%s", message);

    send_mail(sender, recipient, message);

    return 0;
}