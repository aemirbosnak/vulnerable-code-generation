//FormAI DATASET v1.0 Category: QR code generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the QR code generator!\n");
    printf("Please enter your message: ");

    char message[100];
    scanf("%s", &message);

    printf("Generating code...\n");

    // Let's convert the message to QR code format
    char code[256] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i] % 2 == 0)
        {
            strcat(code, "111");
        }
        else
        {
            strcat(code, "000");
        }
    }

    printf("Code generated!\n");

    // Let's print the code
    printf("Your QR code is:\n\n");

    for (int i = 0; i < strlen(code); i++)
    {
        if (code[i] == '0')
        {
            printf("*");
        }
        else
        {
            printf("#");
        }

        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
    }

    printf("\nThank you for using our QR code generator!\n");

    return 0;
}