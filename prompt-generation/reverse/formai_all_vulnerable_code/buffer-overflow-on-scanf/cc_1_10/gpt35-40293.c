//FormAI DATASET v1.0 Category: QR code reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    printf("Welcome to our unique C QR Code Reader program!");
    printf("\nWe hope you enjoy using our program to scan those romantic QR codes!");
    printf("\n\nPlease enter your QR code to scan it:\n");

    char qrCode[100];
    scanf("%s", qrCode);

    bool isValid = false;

    if (strlen(qrCode) == 14)
    {
        char begin[5];
        strncpy(begin, qrCode, 4);
        begin[4] = '\0';

        char middle[6];
        strncpy(middle, qrCode + 4, 5);
        middle[5] = '\0';

        char end[5];
        strncpy(end, qrCode + 9, 4);
        end[4] = '\0';

        if (strcmp(begin, "ILUV") == 0 && strcmp(end, "UTWO") == 0)
        {
            int year = 0;
            sscanf(middle, "%d", &year);

            if (year >= 2000 && year <= 2022)
            {
                isValid = true;
            }
        }
    }

    if (isValid)
    {
        printf("Congratulations! You have successfully scanned a romantic QR code!\n");
        printf("Your QR code reads: '%s'\n", qrCode);
        printf("This QR code shows the year you fell in love with your significant other.\n");
        printf("We hope this brought back some lovely memories for you!\n");
    }
    else
    {
        printf("Sorry, the QR code you scanned is not a valid romantic QR code.\n");
        printf("Please try scanning another QR code!\n");
    }

    return 0;
}