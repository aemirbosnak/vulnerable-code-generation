//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define COMMAND_SIZE 256

void clear_screen()
{
    system("clear");
    printf("\n\n\n\n******************** WELCOME TO THE CIRCUS *********************\n\n");
}

void error_message()
{
    printf("\n\nOops! Something went wrong. Please try again.\n\n");
}

void run_command(char *command)
{
    int status;

    if(fork() == 0)
    {
        if(system(command) != 0)
        {
            error_message();
            exit(1);
        }
        exit(0);
    }

    waitpid(-1, &status, 0);

    if(WIFEXITED(status) && WEXITSTATUS(status) != 0)
    {
        error_message();
    }
}

void display_menu()
{
    printf("\n\n\n******************** MENU *********************\n");
    printf("1. List all users\n");
    printf("2. List all running processes\n");
    printf("3. Modify network configuration\n");
    printf("4. Schedule Shutdown\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void list_all_users()
{
    clear_screen();
    run_command("cut -d: -f1 /etc/passwd");
    printf("\n\n\nPress any key to go back to menu.\n");
    getchar();
}

void list_all_processes()
{
    clear_screen();
    run_command("ps -e");
    printf("\n\n\nPress any key to go back to menu.\n");
    getchar();
}

void modify_network_configuration()
{
    char command[COMMAND_SIZE];
    clear_screen();
    printf("Enter new IP address: ");
    fgets(command, COMMAND_SIZE, stdin);
    command[strcspn(command, "\n")] = 0;
    sprintf(command, "ifconfig eth0 %s netmask 255.255.255.0", command);
    run_command(command);
    printf("\n\n\nNew IP address set successfully!\n\n");
    printf("Press any key to go back to menu.\n");
    getchar();
}

void schedule_shutdown()
{
    char command[COMMAND_SIZE];
    clear_screen();
    printf("Enter amount of time to shut down (in seconds): ");
    fgets(command, COMMAND_SIZE, stdin);
    command[strcspn(command, "\n")] = 0;

    if(atoi(command) <= 0)
    {
        printf("Invalid input!\n\n");
        printf("Press any key to go back to menu.\n");
        getchar();
        return;
    }

    sprintf(command, "shutdown -h +%s", command);
    run_command(command);
    printf("\n\n\nShutdown scheduled successfully!\n\n");
    printf("Press any key to go back to menu.\n");
    getchar();
}

int main()
{
    int choice;

    while(1)
    {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character left over by scanf

        switch(choice)
        {
            case 1:
                list_all_users();
                break;

            case 2:
                list_all_processes();
                break;

            case 3:
                modify_network_configuration();
                break;

            case 4:
                schedule_shutdown();
                break;

            case 5:
                printf("\n\n\n******************** BYE BYE! *********************\n");
                exit(0);

            default:
                clear_screen();
                printf("Invalid choice! Please try again.\n\n");
        }

    }

    return 0;
}