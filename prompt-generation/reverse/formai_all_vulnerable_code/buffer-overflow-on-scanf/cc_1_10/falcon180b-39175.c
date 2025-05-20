//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define USERNAME "knight"
#define PASSWORD "password"

typedef struct {
    char *command;
    void (*callback)(char *response);
} Command;

void login_callback(char *response) {
    char *token = strtok(response, " ");
    if (strcmp(token, "230") == 0) {
        printf("Login successful!\n");
    } else {
        printf("Login failed: %s\n", response);
    }
}

void ls_callback(char *response) {
    printf("Directory listing:\n%s\n", response);
}

void download_callback(char *response) {
    if (strcmp(response, "226") == 0) {
        printf("Download successful!\n");
    } else {
        printf("Download failed: %s\n", response);
    }
}

void upload_callback(char *response) {
    if (strcmp(response, "226") == 0) {
        printf("Upload successful!\n");
    } else {
        printf("Upload failed: %s\n", response);
    }
}

void send_command(char *command, void (*callback)(char *response)) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s\r\n", command);
    write(fileno(stdout), buffer, strlen(buffer));
    fflush(stdout);
}

int main() {
    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(USERNAME, username)!= 0 || strcmp(PASSWORD, password)!= 0) {
        printf("Incorrect credentials\n");
        return 1;
    }

    send_command("USER " USERNAME, NULL);
    send_command("PASS " PASSWORD, login_callback);
    send_command("LS", ls_callback);
    send_command("RETR /README.txt", download_callback);
    send_command("STOR /README.txt", upload_callback);

    return 0;
}