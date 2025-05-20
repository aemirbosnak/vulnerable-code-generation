//Gemma-7B DATASET v1.0 Category: System administration ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main()
{
    char username[20];
    char password[20];

    printf("Enter username:");
    scanf("%s", username);

    printf("Enter password:");
    scanf("%s", password);

    if (strcmp(username, "CyberAdmin") == 0 && strcmp(password, "BlackOps") == 0)
    {
        printf("Access granted. You are now in the System Administrator Interface.\n");
        printf("Please select an option:\n");
        printf("1. View System Stats\n");
        printf("2. Modify User Accounts\n");
        printf("3. Deploy Security Patches\n");
        printf("4. Run System Diagnostics\n");

        int selection;
        scanf("%d", &selection);

        switch (selection)
        {
            case 1:
                printf("System status:\n");
                printf("CPU usage: %f%%\n", 80.5);
                printf("Memory usage: %f%%\n", 65.2);
                printf("Network traffic: %f MB/s\n", 2.1);
                break;
            case 2:
                printf("Enter new username:");
                scanf("%s", username);
                printf("Enter new password:");
                scanf("%s", password);
                printf("User account modified.\n");
                break;
            case 3:
                printf("Enter patch name:");
                scanf("%s", password);
                printf("Patch deployed.\n");
                break;
            case 4:
                printf("Running diagnostics...\n");
                printf("System report:\n");
                printf("No errors found.\n");
                break;
            default:
                printf("Invalid selection.\n");
                break;
        }
    }
    else
    {
        printf("Access denied. Unauthorized user.\n");
    }

    return 0;
}