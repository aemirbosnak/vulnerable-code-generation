//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: funny
// FTP Client Example Program in a Funny Style

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the FTP Client Program!\n");
    printf("Please enter the IP address of the FTP server: ");

    char ip_address[20];
    scanf("%s", ip_address);

    printf("Please enter the username: ");
    char username[20];
    scanf("%s", username);

    printf("Please enter the password: ");
    char password[20];
    scanf("%s", password);

    printf("Connecting to %s...\n", ip_address);
    printf("Connected to %s as %s\n", ip_address, username);
    printf("Authorized successfully, now connected to FTP server!\n\n");
    printf("What would you like to do today? Options:\n");
    printf("- Upload a file (type 'upload')\n");
    printf("- Download a file (type 'download')\n");
    printf("- Quit (type 'quit')\n");

    char option[10];
    scanf("%s", option);

    while(strcmp("quit", option) != 0)
    {
        if(strcmp("upload", option) == 0)
        {
            printf("Please enter the file name to upload: ");
            char filename[50];
            scanf("%s", filename);
            printf("Uploading %s to server...\n", filename);
            // Code to upload file to server
            printf("%s uploaded successfully!\n\n", filename);
        }
        else if(strcmp("download", option) == 0)
        {
            printf("Please enter the file name to download: ");
            char filename[50];
            scanf("%s", filename);
            printf("Downloading %s from server...\n", filename);
            // Code to download file from server
            printf("%s downloaded successfully!\n\n", filename);
        }
        else
        {
            printf("Invalid option! Please enter 'upload', 'download' or 'quit'\n");
        }

        printf("What would you like to do now? Options:\n");
        printf("- Upload a file (type 'upload')\n");
        printf("- Download a file (type 'download')\n");
        printf("- Quit (type 'quit')\n");
        scanf("%s", option);
    }

    printf("Thank you for using the FTP Client Program. Goodbye!\n");
    return 0;
}