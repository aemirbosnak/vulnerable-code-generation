//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_ACCESS_COUNT 3

typedef struct {
    char username[20];
    char password[20];
} LoginCredential;

void systemError(int error_code);
void reportIntrusionAttempt();
void notifyAdministrator();

int main() {
    FILE* access_file;
    LoginCredential saved_credentials;
    LoginCredential entered_credentials;
    int access_count = 0;

    // Open the access file and read the saved login credentials
    if((access_file = fopen("access.dat", "rb")) == NULL) {
        systemError(1);
    }

    fread(&saved_credentials, sizeof(LoginCredential), 1, access_file);
    fclose(access_file);

    // Prompt the user to enter their login credentials
    printf("Enter your username and password:\n");
    scanf("%s %s", entered_credentials.username, entered_credentials.password);

    // Check if the entered credentials match the saved credentials
    if(strcmp(entered_credentials.username, saved_credentials.username) == 0 &&
       strcmp(entered_credentials.password, saved_credentials.password) == 0) {
        printf("Login successful.\n");
    } else {
        access_count++;
        reportIntrusionAttempt();

        if(access_count == MAX_ACCESS_COUNT) {
            notifyAdministrator();
        }

        printf("Invalid login attempt. You have %d login attempts left.\n", MAX_ACCESS_COUNT - access_count);
    }

    return 0;
}

void systemError(int error_code) {
    printf("An error occurred while accessing the system.\n");
    exit(error_code);
}

void reportIntrusionAttempt() {
    FILE* intrusion_file;
    char buffer[MAX_BUFFER_SIZE];

    if((intrusion_file = fopen("intrusions.dat", "a+")) == NULL) {
        systemError(2);
    }

    sprintf(buffer, "Intrusion attempt detected on %s", __DATE__);
    fwrite(buffer, strlen(buffer), 1, intrusion_file);
    fclose(intrusion_file);
}

void notifyAdministrator() {
    FILE* admin_file;
    char buffer[MAX_BUFFER_SIZE];

    if((admin_file = fopen("admin.dat", "rb")) == NULL) {
        systemError(3);
    }

    fread(buffer, MAX_BUFFER_SIZE, 1, admin_file);
    printf("Notifying System Administrator: %s\n", buffer);
    fclose(admin_file);
}