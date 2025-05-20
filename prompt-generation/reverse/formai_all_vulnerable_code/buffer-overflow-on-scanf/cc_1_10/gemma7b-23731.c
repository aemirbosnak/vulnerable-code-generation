//Gemma-7B DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char email[100] = "your_email@gmail.com";
    char password[100] = "your_password";
    char subject[100] = "Subject";
    char message[1000] = "Message";

    system("clear");
    printf("           /\n");
    printf("          |||||\n");
    printf("           \__) |\n");
    printf("   _||_||_||_||_||_||_||_||_|   \n");
    printf("  / |__\__\__\__\__\__\__\__\__| |  \n");
    printf("  | |__\__\__\__\__\__\__\__\__| |  \n");
    printf("  | |__\__\__\__\__\__\__\__\__| |  \n");
    printf("  _||_||_||_||_||_||_||_||_|_||_|   \n");

    printf("Enter email address: ");
    scanf("%s", email);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter message: ");
    scanf("%s", message);

    FILE *fp = fopen("email.txt", "w");
    fprintf(fp, "From: %s\n", email);
    fprintf(fp, "To: %s\n", email);
    fprintf(fp, "Subject: %s\n", subject);
    fprintf(fp, "Message: %s\n", message);
    fclose(fp);

    system("mail -s \"Subject\" your_email@gmail.com < email.txt");

    system("clear");
    printf("           /\n");
    printf("          |||||\n");
    printf("           \__) |\n");
    printf("   _||_||_||_||_||_||_||_||_|   \n");
    printf("  / |__\__\__\__\__\__\__\__\__| |  \n");
    printf("  | |__\__\__\__\__\__\__\__\__| |  \n");
    printf("  | |__\__\__\__\__\__\__\__\__| |  \n");
    printf("  _||_||_||_||_||_||_||_||_|_||_|   \n");

    return 0;
}