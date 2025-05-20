//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
#define MAX_ATTEMPTS 3 
#define MAX_PASSWORD_LENGTH 15 
#define MAX_LOG_SIZE 50 
  
typedef struct Log { 
   char username[MAX_PASSWORD_LENGTH]; 
   char password[MAX_PASSWORD_LENGTH]; 
   char ip_address[16]; 
   char timestamp[20]; 
} Log; 
  
int main(int argc, char *argv[]) 
{ 
    // initialize variables
    int attempts = 0;
    char password[MAX_PASSWORD_LENGTH];  
    int logged_in = 0; 
    char username[MAX_PASSWORD_LENGTH];
    char ip_address[16];
    Log log[MAX_LOG_SIZE]; 
    int log_count = 0; 
  
    // get the user info
    printf("Enter your username: "); 
    scanf("%s", username);
    printf("Enter your password: "); 
    scanf("%s", password); 
    printf("Enter your IP address: ");
    scanf("%s", ip_address);

    // check the password and log the attempt
    while (!logged_in && attempts < MAX_ATTEMPTS) { 
        if (strcmp(password, "password123") == 0) { 
            logged_in = 1; 
            printf("Login successful!\n"); 
        } else { 
            printf("Login failed. Please try again.\n"); 
            attempts++; 
            // log the attempt
            Log current_log;
            strncpy(current_log.username, username, MAX_PASSWORD_LENGTH - 1);
            strncpy(current_log.password, password, MAX_PASSWORD_LENGTH - 1);
            strncpy(current_log.ip_address, ip_address, 15);
            // set the timestamp (not shown)
            strncpy(current_log.timestamp, "timestamp", 20);
            log[log_count] = current_log;
            log_count++;
            // get the password again
            printf("Enter your password:\n"); 
            scanf("%s", password); 
        } 
    } 

    // check if we exceeded the maximum number of attempts
    if (!logged_in) { 
        printf("Maximum login attempts reached.\n"); 
    } 

    // print the log
    printf("Login attempts:\n");
    for (int i = 0; i < log_count; i++) {
        printf("Username: %s, Password: %s, IP Address: %s, Timestamp: %s\n",
          log[i].username, log[i].password, log[i].ip_address, log[i].timestamp);
    }

    return 0; 
}