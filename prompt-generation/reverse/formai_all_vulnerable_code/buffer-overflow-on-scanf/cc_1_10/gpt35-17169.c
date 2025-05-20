//FormAI DATASET v1.0 Category: QR code reader ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char code[100];
    printf("Welcome to the Medieval QR Code Reader!\n");
    printf("Enter a QR code: ");
    scanf("%s", code);
    
    if (strlen(code) < 5 || strlen(code) > 30)
    {
        printf("Invalid QR code! Must be between 5 and 30 characters long.\n");
        return 0;
    }
    
    int i;
    int flag;
    for (i = 0; i < strlen(code); i++)
    {
        if (code[i] < 65 || code[i] > 90)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    
    if (flag == 1)
    {
        printf("Invalid QR code! Must contain only capital letters.\n");
        return 0;
    }
    
    printf("QR code successfully scanned! Your message is:\n");
    
    char message[100];
    for (i = 0; i < strlen(code); i++)
    {
        message[i] = code[i] + 4;
        if (message[i] > 90)
        {
            message[i] -= 26;
        }
    }
    message[i] = '\0';
    
    printf("%s\n", message);
    
    return 0;
}