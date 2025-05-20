//FormAI DATASET v1.0 Category: QR code reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 256

bool isValidQRCode(char code[])
{
    int length = strlen(code);
    
    if(length != 10)
    {
        return false;
    }
    
    for(int i=0; i<length; i++)
    {
        if(!isdigit(code[i]))
        {
            return false;
        }
    }
    
    return true;
}

void readQRCode()
{
    char code[MAX_LENGTH];
    
    printf("Scan the QR Code: ");
    scanf("%s", code);
    
    if(isValidQRCode(code))
    {
        printf("Valid QR Code!\n");
        printf("Access granted!\n");
        //Code to grant access
    }
    else
    {
        printf("Invalid QR Code!\n");
        printf("Access denied!\n");
    }
}

int main()
{
    printf("*** QR Code Reader Application ***\n\n");
    
    while(true)
    {
        readQRCode();
    }
    
    return 0;
}