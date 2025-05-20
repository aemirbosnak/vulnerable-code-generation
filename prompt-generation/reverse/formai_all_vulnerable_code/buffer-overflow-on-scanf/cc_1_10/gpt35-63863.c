//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define PORT 21 // FTP port for connection

// Function to connect to FTP server
int connectToServer(char *ipAddress, int port){

    int sockfd = -1;
    struct sockaddr_in serverAddr;
    struct in_addr ip;

    if(!inet_aton(ipAddress, &ip)){
        printf("Unable to parse IP address!");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        printf("Unable to create socket!");
        return -1;
    }
    memset(&serverAddr, 0, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress);
    serverAddr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0){
        printf("Unable to connect to server");
        return -1;
    }
    return sockfd;

}

// Function to login to FTP server
void login(int sockfd, char *username, char *password){

    char buffer[1024] = {0};
    memset(buffer, 0, sizeof(buffer));

    // Get response from the server and display it on console
    read(sockfd, buffer, sizeof(buffer));

    printf("%s\n", buffer);

    // Send username to the server
    sprintf(buffer, "USER %s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));

    // Get response from the server and display it on console
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    // Send password to the server
    sprintf(buffer, "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));

    // Get response from the server and display it on console
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

} 

// Function to download file from the FTP server
void downloadFile(int sockfd, char *filename){

    FILE *f; 
    int file_size;
    int bytes_received;
    char buffer[1024];

    // Open file in binary mode to write contents of downloaded file
    f = fopen(filename, "wb");

    // Send FTP command to server to enter passive mode
    write(sockfd, "PASV\r\n", strlen("PASV\r\n"));
    memset(buffer, 0, sizeof(buffer));

    // Get response from server for entered passive mode
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    // Extract port number and IP address from response recieved from server
    char *temp = strchr(buffer, '(');
    temp = strtok(temp + 1, ",");
    temp = strtok(NULL, ",");
    temp = strtok(NULL, ",");
    temp = strtok(NULL, ",");
    int port1 = atoi(temp);
    temp = strtok(NULL, ",");
    int port2 = atoi(temp);
    temp = strtok(NULL, ",");
    temp = strtok(NULL, ",");
    temp = strtok(NULL, ",");
    temp = strtok(NULL, ")");
    char server_ip[16];
    sprintf(server_ip, "%s.%s.%s.%s", temp, strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","));

    // Convert port numbers recieved from server to actual port number
    int port_num = port1 * 256 + port2;

    // Create a data socket to download the file
    int datasockfd;
    struct sockaddr_in serv_addr_data;
    datasockfd = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr_data, 0, sizeof(serv_addr_data));
    serv_addr_data.sin_family = AF_INET;
    serv_addr_data.sin_addr.s_addr = inet_addr(server_ip);
    serv_addr_data.sin_port = htons(port_num);
    if (connect(datasockfd, (struct sockaddr *)&serv_addr_data, sizeof(serv_addr_data))<0) {
        printf("Unable to connect to server\n");
        return ;
    }

    // Send FTP command to download the file
    char ftpcommand[1024];
    sprintf(ftpcommand, "RETR %s\r\n", filename);
    write(sockfd, ftpcommand, strlen(ftpcommand));
    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);
    read(datasockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    // Download and write file contents to specified file
    while ((bytes_received = read(datasockfd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, 1, bytes_received, f);
    }

    // Close the data socket and file
    fclose(f);
    close(datasockfd);

}

int main(){

    int sockfd = -1;
    char ipAddress[20];
    char username[20];
    char password[20];
    char filename[20];
    char choice[2];

    printf("Enter FTP server IP address : ");
    scanf("%s", ipAddress);

    //Create a socket and connect to the FTP server
    sockfd = connectToServer(ipAddress, PORT); 

    if(sockfd == -1){
        printf("Unable to connect to server!");
        return -1;
    }
    printf("Connected to FTP server successfully!\n");

    //Get username and password for logging into FTP server
    printf("Enter username : ");
    scanf("%s", username);
    printf("Enter password : ");
    scanf("%s", password);

    //Log into FTP server using username and password
    login(sockfd, username, password);

    //Download file from FTP server
    printf("Enter filename to download : ");
    scanf("%s", filename);
    downloadFile(sockfd, filename);

    //Close connection to FTP server
    close(sockfd);
      
    return 0;
}