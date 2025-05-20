//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to connect to the FTP server
int connectToFTP(char* hostname, char* username, char* password) {
    FILE* fp;
    int result;
    char buffer[256];

    // Connect to the FTP server
    sprintf(buffer, "USER %s\r\n", username);
    fputs(buffer, fp);
    fgets(buffer, 256, fp);

    sprintf(buffer, "PASS %s\r\n", password);
    fputs(buffer, fp);
    fgets(buffer, 256, fp);

    sprintf(buffer, "PWD\r\n");
    fputs(buffer, fp);
    fgets(buffer, 256, fp);

    // Read the directory listing
    sprintf(buffer, "NLST\r\n");
    fputs(buffer, fp);
    fgets(buffer, 256, fp);

    result = fscanf(fp, "%s", buffer);
    if (result == EOF) {
        printf("Error connecting to FTP server\n");
        return -1;
    }
    else {
        printf("Connected to FTP server %s\n", buffer);
        return 0;
    }
}

// Function to download a file from the FTP server
int downloadFile(char* hostname, char* username, char* password, char* filename) {
    FILE* fp;
    int result;
    char buffer[256];

    // Connect to the FTP server
    result = connectToFTP(hostname, username, password);
    if (result!= 0) {
        return -1;
    }

    // Change to the directory containing the file
    sprintf(buffer, "CD %s\r\n", filename);
    fputs(buffer, fp);
    fgets(buffer, 256, fp);

    // Download the file
    sprintf(buffer, "RETR %s\r\n", filename);
    fputs(buffer, fp);
    fgets(buffer, 256, fp);

    result = fscanf(fp, "%s", buffer);
    if (result == EOF) {
        printf("Error downloading file %s\n", filename);
        return -1;
    }
    else {
        printf("Downloaded file %s successfully\n", filename);
        return 0;
    }
}

int main() {
    char* hostname = "ftp.example.com";
    char* username = "myusername";
    char* password = "mypassword";
    char* filename = "example.txt";

    int result = downloadFile(hostname, username, password, filename);
    if (result == 0) {
        printf("File downloaded successfully\n");
    }
    else {
        printf("Error downloading file\n");
    }

    return 0;
}