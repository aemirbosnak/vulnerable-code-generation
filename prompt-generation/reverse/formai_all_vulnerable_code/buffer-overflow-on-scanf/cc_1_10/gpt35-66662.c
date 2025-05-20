//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: distributed
// This is a distributed C Cat Language Translator 
// The program is designed to translate human language into the language of cats through multiple servers running in parallel

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_MSG_LENGTH 1000
#define SERVERS_COUNT 10
#define SERVER_PORT 8080

void translate_to_cat_language(char *human_input, char *cat_output);
void fetch_translation_from_server(char *human_input, char *cat_output);
void send_message_to_server(char *message, char *server_ip);

int main(int argc, char *argv[]) {
    char human_input[MAX_MSG_LENGTH], cat_output[MAX_MSG_LENGTH];
    
    printf("Enter your message: ");
    scanf("%s", human_input);
    
    translate_to_cat_language(human_input, cat_output);
    
    printf("Your message in cat language: %s\n", cat_output);
    
    return 0;
}

void translate_to_cat_language(char *human_input, char *cat_output) {
    // divide the message between servers
    int length = strlen(human_input);
    int server_range = length / SERVERS_COUNT;
    int mod = length % SERVERS_COUNT;
    
    char servers_ip[SERVERS_COUNT][16] = {
        "192.168.1.1",
        "192.168.1.2",
        "192.168.1.3",
        "192.168.1.4",
        "192.168.1.5",
        "192.168.1.6",
        "192.168.1.7",
        "192.168.1.8",
        "192.168.1.9",
        "192.168.1.10"
    };
    
    int server_start = 0;
    int server_end = server_range;
    for(int i = 0; i < SERVERS_COUNT; i++) {
        if(i < mod) server_end++;
        char message_part[server_range + 1];
        strncpy(message_part, human_input + server_start, server_end - server_start);
        message_part[server_end - server_start] = '\0';
        server_start = server_end;
        server_end += server_range;
        send_message_to_server(message_part, servers_ip[i]);
    }
    
    // receive translation from servers
    strcpy(cat_output, "");
    char server_reply[MAX_MSG_LENGTH];
    for(int i = 0; i < SERVERS_COUNT; i++) {
        fetch_translation_from_server(human_input, server_reply);
        strcat(cat_output, server_reply);
    }
}

void send_message_to_server(char *message, char *server_ip) {
    int socket_desc;
    struct sockaddr_in server;
    char server_reply[MAX_MSG_LENGTH];
    
    // create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        printf("Error: Could not create socket.");
        exit(1);
    }
    
    // setup server address
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    
    // connect to server
    if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Could not connect to server.");
        exit(1);
    }
    
    // send message to server
    if(send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Error: Could not send message to server.");
        exit(1);
    }
    
    // receive server reply
    if(recv(socket_desc, server_reply, MAX_MSG_LENGTH, 0) < 0) {
        printf("Error: Could not receive server reply.");
        exit(1);
    }
    
    // close socket
    close(socket_desc);
}

void fetch_translation_from_server(char *human_input, char *cat_output) {
    // create socket
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;
    char client_message[MAX_MSG_LENGTH];
    
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        printf("Error: Could not create socket.");
        exit(1);
    }
    
    // setup server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);
    
    // bind socket to address
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Could not bind socket to port.");
        exit(1);
    }
    
    // listen for incoming connections
    listen(socket_desc, 3);
    
    // accept incoming connection
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if(client_sock < 0) {
        printf("Error: Could not accept incoming connection.");
        exit(1);
    }
    
    // receive message from client
    if(recv(client_sock, client_message, MAX_MSG_LENGTH, 0) < 0) {
        printf("Error: Could not receive message from client.");
        exit(1);
    }
    
    // translate message to cat language
    strcpy(cat_output, "");
    for(int i = 0; i < strlen(client_message); i++) {
        if(client_message[i] == ' ') {
            strcat(cat_output, "meow ");
        } else {
            strcat(cat_output, "meow");
        }
    }
    
    // send translation to client
    if(send(client_sock, cat_output, strlen(cat_output), 0) < 0) {
        printf("Error: Could not send translation to client.");
        exit(1);
    }
    
    // close socket
    close(client_sock);
    close(socket_desc);
}