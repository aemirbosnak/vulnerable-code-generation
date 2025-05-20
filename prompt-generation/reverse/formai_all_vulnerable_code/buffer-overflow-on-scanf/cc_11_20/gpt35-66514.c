//FormAI DATASET v1.0 Category: System administration ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    
    // Welcome message
    printf("Welcome to the System Administration Program!\n");
    printf("---------------------------------------------\n\n");
    
    // Main menu
    char choice;
    do{
        printf("Please select an option:\n");
        printf("1. Check system status\n");
        printf("2. Manage users\n");
        printf("3. Manage services\n");
        printf("4. Exit program\n\n");
        printf("Choice: ");
        scanf(" %c", &choice);
        
        // System status option
        if(choice == '1'){
            printf("\nSystem Status\n");
            printf("--------------\n\n");
            system("top");
            
        // User management option
        }else if(choice == '2'){
            char sub_choice;
            printf("\nUser Management\n");
            printf("----------------\n\n");
            do{
                printf("Please select an option:\n");
                printf("a. Create user\n");
                printf("b. Delete user\n");
                printf("c. View all users\n");
                printf("d. Return to main menu\n\n");
                printf("Choice: ");
                scanf(" %c", &sub_choice);
                
                // Create user option
                if(sub_choice == 'a'){
                    char username[30];
                    printf("\nEnter a username: ");
                    scanf(" %s", username);
                    char command[50];
                    sprintf(command, "sudo useradd -m %s", username);
                    system(command);
                // Delete user option
                }else if(sub_choice == 'b'){
                    char username[30];
                    printf("\nEnter a username: ");
                    scanf(" %s", username);
                    char command[50];
                    sprintf(command, "sudo userdel %s", username);
                    system(command);
                // View all users option
                }else if(sub_choice == 'c'){
                    system("cat /etc/passwd | cut -d ':' -f 1");
                // Return to main menu option
                }else if(sub_choice == 'd'){
                    printf("\nReturning to main menu...\n\n");
                // Invalid sub-choice
                }else{
                    printf("\nInvalid choice, please try again.\n\n");
                }
            }while(sub_choice != 'd');
        
        // Service management option
        }else if(choice == '3'){
            char sub_choice;
            printf("\nService Management\n");
            printf("------------------\n\n");
            do{
                printf("Please select an option:\n");
                printf("a. Start service\n");
                printf("b. Stop service\n");
                printf("c. Restart service\n");
                printf("d. Check service status\n");
                printf("e. Return to main menu\n\n");
                printf("Choice: ");
                scanf(" %c", &sub_choice);
                
                // Start service option
                if(sub_choice == 'a'){
                    char service[30];
                    printf("\nEnter a service name: ");
                    scanf(" %s", service);
                    char command[50];
                    sprintf(command, "sudo systemctl start %s", service);
                    system(command);
                // Stop service option
                }else if(sub_choice == 'b'){
                    char service[30];
                    printf("\nEnter a service name: ");
                    scanf(" %s", service);
                    char command[50];
                    sprintf(command, "sudo systemctl stop %s", service);
                    system(command);
                // Restart service option
                }else if(sub_choice == 'c'){
                    char service[30];
                    printf("\nEnter a service name: ");
                    scanf(" %s", service);
                    char command[50];
                    sprintf(command, "sudo systemctl restart %s", service);
                    system(command);
                // Check service status option
                }else if(sub_choice == 'd'){
                    char service[30];
                    printf("\nEnter a service name: ");
                    scanf(" %s", service);
                    char command[50];
                    sprintf(command, "sudo systemctl status %s", service);
                    system(command);
                // Return to main menu option
                }else if(sub_choice == 'e'){
                    printf("\nReturning to main menu...\n\n");
                // Invalid sub-choice
                }else{
                    printf("\nInvalid choice, please try again.\n\n");
                }
            }while(sub_choice != 'e');
        
        // Exit program option
        }else if(choice == '4'){
            printf("\nExiting program...\n");
            exit(0);
        // Invalid choice
        }else{
            printf("\nInvalid choice, please try again.\n\n");
        }
    }while(1);
    
    return 0;
}