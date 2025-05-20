//FormAI DATASET v1.0 Category: System administration ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char user_choice;
    while(1)
    {
        printf("\nWelcome to the System Administration Program\n");
        printf("1. Display System Information\n");
        printf("2. Shutdown the System\n");
        printf("3. Restart the System\n");
        printf("4. Quit the Program\n");
        printf("Enter your choice: ");
        scanf(" %c", &user_choice);

        switch(user_choice)
        {
            case '1':
                system("uname -a");
                system("lsb_release -a");
                printf("\n");
                break;

            case '2':
                printf("Are you sure you want to shutdown the system (y/n)? ");
                scanf(" %c", &user_choice);
                if(user_choice == 'y')
                {
                    system("sudo shutdown -h now");
                }
                break;

            case '3':
                printf("Are you sure you want to restart the system (y/n)? ");
                scanf(" %c", &user_choice);
                if(user_choice == 'y')
                {
                    system("sudo reboot");
                }
                break;

            case '4':
                printf("Thank you for using the System Administration Program\n");
                exit(0);

            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }
    return 0;
}