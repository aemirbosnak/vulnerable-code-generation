//FormAI DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    int magic_num = 3835;
    int input_num;
    char key[10];
    char flag[30] = "G00D_LUck_w1TH_th15_0Ne";
    
    printf("Enter the magic number to proceed with the system administration program : ");
    scanf("%d", &input_num);

    if (input_num == magic_num) {
        printf("\nCongrats! Now, enter the secret key to access the system:\n");
        scanf("%s", key);

        if (strcmp(key, flag) == 0) {
            printf("\nAccess Granted! Welcome to the System Administration program...\n\n");
            
            printf("Please select an option from below : \n\n");
            printf("1. View System Info.\n");
            printf("2. Modify System Settings.\n");
            printf("3. Perform System Maintenance.\n");
            
            int option;
            scanf("%d", &option);
            
            switch(option){
                case 1:
                    printf("\nChecking System Information...\n\n");
                    system("uname -a");
                    break;
                case 2:
                    printf("\nModifying System Settings...\n\n");
                    system("sudo nano /etc/systemd/system.conf");
                    break;
                case 3:
                    printf("\nPerforming System Maintenance...\n\n");
                    system("sudo apt update");
                    system("sudo apt upgrade");
                    break;
                default:
                    printf("\nInvalid option selected.\n");
            }
            printf("\nSystem administration tasks completed successfully. Have a nice day!\n");
            
        } else {
            printf("\nAccess Denied! Please enter the correct key.\n");
        }
    } else {
        printf("\nInvalid magic number entered. This incident will be reported...\n");
        system("echo 'Unauthorized access attempted' >> /var/log/auth.log");
    }

    return 0;
}