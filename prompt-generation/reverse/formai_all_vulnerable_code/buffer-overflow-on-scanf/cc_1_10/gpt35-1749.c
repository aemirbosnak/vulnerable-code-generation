//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include<stdio.h>
#include<string.h>

int main(){
    // Welcome message
    printf("Hello happy people! Let's build an Intrusion Detection System in C.\n");

    // Taking user input for login
    char username[20], password[20];
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);

    // Validating user login credentials
    int valid_login = 0;
    if(strcmp(username, "HappyUser") == 0 && strcmp(password, "happy123") == 0){
        printf("\nCongratulations! You have successfully logged in.\n");
        valid_login = 1;
    }
    else{
        printf("\nSorry, your login credentials are invalid. Please try again.\n");
        return 0;
    }

    // Initializing the IDS
    printf("\nInitializing the Intrusion Detection System (IDS)...\n");

    // Reading from a log file
    FILE *fp = fopen("activity_log.txt", "r");
    char log[100];
    while(fgets(log, 100, fp)){
        printf("Analyzing log: %s", log);

        // Checking for suspicious activity
        if(strstr(log, "ssh")){
            printf("Detected SSH activity!\n");
        }
        else if(strstr(log, "sudo")){
            printf("Detected Sudo activity!\n");
        }
        else if(strstr(log, "wget")){
            printf("Detected Wget activity!\n");
        }
        else{
            printf("No suspicious activity detected.\n");
        }
    }

    // Closing the IDS
    printf("Closing the Intrusion Detection System (IDS)...\n");

    // Goodbye message
    printf("Thanks for using the IDS! Stay happy and stay safe!\n");

    return 0;
}