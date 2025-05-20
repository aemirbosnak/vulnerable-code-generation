//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: visionary
/* 
   This is a FTP client program created by a visionary programmer who envisions a world where file transfer is seamless and efficient. 
   This program is written in C language and has a user-friendly interface. 
   It can connect to any FTP server and download or upload files with ease.

   To use this program, simply provide the server name, port number, username, and password. 
   The program will establish a connection and show all the available files on the server. 
   
   You can then select the file you want to download or upload and specify the destination location on your local machine.

   Let's see the code below:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXSIZE 1024

int ftp_download(int sockfd,char* filename,char* destpath){
    char buff[MAXSIZE];
    int filehandle, n;
    long int filesize = 0, total_size = 0;

    // Send DOWNLOAD command and filename to server
    sprintf(buff, "RETR %s\n", filename);
    send(sockfd, buff, strlen(buff), 0);

    // Open file, create file if not exists
    filehandle = open(destpath, O_CREAT | O_WRONLY, S_IRWXU);

    // Wait for server response
    recv(sockfd, buff, MAXSIZE, 0);

    // Check if file is available and proceed to download
    if(buff[0] == '1') {
        // Get the file size
        sscanf(buff, "%*d %*d %*d %ld", &filesize);
        printf("Downloading %ld bytes\n", filesize);

        // Start the download process
        while(1) {
            // Receive data from server
            n = recv(sockfd, buff, MAXSIZE, 0);
            if(n == 0) {
                // Download complete
                printf("Download complete!\n");
                close(filehandle);
                break;    
            }
            else {
                // Write data to file
                write(filehandle, buff, n);
                total_size += n;
                printf("%ld of %ld bytes downloaded (%0.2f%%)\r", total_size, filesize, ((float)total_size/filesize)*100);
                fflush(stdout);
            }
        }
        return 1;
    }
    else {
        printf("Error downloading file\n");
        return 0;
    }
}

int ftp_upload(int sockfd,char* filename,char* filepath){
    char buff[MAXSIZE], filename2[MAXSIZE];
    int filehandle, n;
    long int filesize;

    // Extract filename from path
    char *p = strrchr(filepath, '/');
    if(p == NULL) {
        strcpy(filename2, filepath);
    }
    else {
        strcpy(filename2, p+1);
    }

    // Open file for reading
    filehandle = open(filepath, O_RDONLY);
    if(filehandle == -1) {
        printf("Couldn't open file\n");
        return 0;
    }

    // Get file size and send upload command to server
    filesize = lseek(filehandle, 0, SEEK_END);
    lseek(filehandle, 0, SEEK_SET);
    sprintf(buff, "STOR %s\n", filename);
    send(sockfd, buff, strlen(buff), 0);

    // Wait for server response
    recv(sockfd, buff, MAXSIZE, 0);

    // Check if file is available and proceed to upload
    if(buff[0] == '1') {
        printf("Uploading %ld bytes\n", filesize);

        // Start the upload process
        while(1) {
            // Read data from file
            n = read(filehandle, buff, MAXSIZE);
            if(n == 0) {
                // Upload complete
                printf("Upload complete!\n");
                close(filehandle);
                break;
            }
            else {
                // Send data to server
                send(sockfd, buff, n, 0);
            }
        }
        return 1;
    }
    else {
        printf("Error uploading file\n");
        return 0;
    }
}

int ftp_connect(char* host,int port,char* username,char* password){
    struct sockaddr_in servaddr;
    int sockfd;
    char buff[MAXSIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Initialize server address structure
    

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(host);
    servaddr.sin_port = htons(port);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(2);
    }
    else {
        // Wait for server response and enter username
        recv(sockfd, buff, MAXSIZE, 0);
        printf("%s", buff);
        sprintf(buff, "%s\n", username);
        send(sockfd, buff, strlen(buff), 0);

        // Wait for server response and enter password
        recv(sockfd, buff, MAXSIZE, 0);
        printf("%s", buff);
        sprintf(buff, "%s\n", password);
        send(sockfd, buff, strlen(buff), 0);

        // Wait for server response and proceed to list files
        recv(sockfd, buff, MAXSIZE, 0);
        printf("%s", buff);
        if(buff[0] == '2') {
            return sockfd;
        }
        else {
            printf("Error logging in to FTP server\n");
            return -1;
        }
    }
}

int main() {
    char host[MAXSIZE], username[MAXSIZE], password[MAXSIZE], filename[MAXSIZE], destpath[MAXSIZE], input[MAXSIZE], command[MAXSIZE];
    int port, sockfd, status;
    char* token;

    // Get server details from user
    printf("Enter FTP server details:\n");
    printf("Host: ");
    scanf("%s", host);
    printf("Port: ");
    scanf("%d", &port);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Connect to server
    sockfd = ftp_connect(host, port, username, password);

    // Show available commands to user
    printf("\nAvailable commands:\n");
    printf("LIST - List all files on server\n");
    printf("DOWNLOAD - Download a file from server\n");
    printf("UPLOAD - Upload a file to server\n");
    printf("QUIT - Terminate connection to server\n\n");

    while(1) {
        // Get user command
        printf("> ");
        fgets(input, MAXSIZE, stdin);
        sscanf(input, "%s", command);

        if(strcmp(command, "LIST") == 0) {
            // Send LIST command to server
            send(sockfd, "LIST\n", 5, 0);

            // Wait for server response and print all files
            recv(sockfd, input, MAXSIZE, 0);
            while(strncmp(input, "226", 3) != 0) {
                printf("%s", input);
                recv(sockfd, input, MAXSIZE, 0);
            }
        }
        else if(strcmp(command, "DOWNLOAD") == 0) {
            // Get filename and destination path from user
            printf("Filename: ");
            fgets(filename, MAXSIZE, stdin);
            strtok(filename, "\n");
            printf("Destination path: ");
            fgets(destpath, MAXSIZE, stdin);
            strtok(destpath, "\n");

            // Download file and check for errors
            status = ftp_download(sockfd, filename, destpath);
            if(status == 0) {
                printf("Error downloading file %s\n", filename);
            }
        }
        else if(strcmp(command, "UPLOAD") == 0) {
            // Get filename and source path from user
            printf("Filename: ");
            fgets(filename, MAXSIZE, stdin);
            strtok(filename, "\n");
            printf("Source path: ");
            fgets(destpath, MAXSIZE, stdin);
            strtok(destpath, "\n");

            // Upload file and check for errors
            status = ftp_upload(sockfd, filename, destpath);
            if(status == 0) {
                printf("Error uploading file %s\n", filename);
            }
        }
        else if(strcmp(command, "QUIT") == 0) {
            // Terminate connection and exit program
            send(sockfd, "QUIT\n", 5, 0);
            printf("Terminating connection\n");
            exit(0);
        }
        else {
            // Invalid command
            printf("Invalid command\n");
        }
    }
    return 0;
}