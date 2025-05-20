//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define SECRET_KEY "SUPERSECRETKEY"
#define ALLOWED_USER " authorized_user"

char *logfile = "/tmp/intrusion_log.txt";

int main()
{
    char username[20];
    char password[20];
    char key[20];

    // Read username and password
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Check if user is authorized
    if (strcmp(username, ALLOWED_USER) != 0)
    {
        printf("Error: Unauthorized user.\n");
        return 1;
    }

    // Read the secret key
    printf("Enter the secret key: ");
    scanf("%s", key);

    // Compare the secret key with the stored key
    if (strcmp(key, SECRET_KEY) != 0)
    {
        printf("Error: Invalid secret key.\n");
        return 1;
    }

    // Log the intrusion
    FILE *log = fopen(logfile, "a");
    fprintf(log, "%s %s %s\n", username, key, "Intrusion detected!");
    fclose(log);

    // Notify administrator
    system("mail -r administrator@example.com -s 'Intrusion Detection' < /tmp/intrusion_log.txt");

    // Lock down the system
    system("shutdown -h now");

    return 0;
}