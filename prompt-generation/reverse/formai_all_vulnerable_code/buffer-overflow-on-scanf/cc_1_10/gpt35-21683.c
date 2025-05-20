//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define MAXSIZE 1024

struct Message {
    char* from;
    char* to;
    char* subject;
    char* body;
};

typedef struct Message Message;

void get_message(char* buffer, char** store) {
    int i = 0, j = 0, size = strlen(buffer);
    char temp[size];
    while(buffer[i] != ' ') {
        temp[j++] = buffer[i++];
    }
    temp[j] = '\0';
    *store = (char*) malloc((strlen(temp)+1) * sizeof(char));
    strcpy(*store, temp);
}

void parse_response(char* response, Message* message) {
    char* temp;
    get_message(response, &temp);
    if(strcmp(temp, "FROM") == 0) {
        get_message(response + strlen("FROM"), &(message->from));
    } else if(strcmp(temp, "TO") == 0) {
        get_message(response + strlen("TO"), &(message->to));
    } else if(strcmp(temp, "SUBJECT") == 0) {
        get_message(response + strlen("SUBJECT"), &(message->subject));
    } else if(strcmp(temp, "BODY") == 0) {
        get_message(response + strlen("BODY"), &(message->body));
    }
}

void print_message(Message* message) {
    printf("FROM: %s\n", message->from);
    printf("TO: %s\n", message->to);
    printf("SUBJECT: %s\n", message->subject);
    printf("BODY: %s\n", message->body);
}

int main() {
    printf("Enter your email ID: ");
    char email[MAXSIZE];
    scanf("%s", email);
    printf("Enter your password: ");
    char password[MAXSIZE];
    scanf("%s", password);
    printf("Connecting to IMAP server...\n");
    // simulate server response
    printf("A001 OK Logged in.\n");
    sleep(1);
    printf("A002 OK Select completed.\n");
    sleep(1);
    printf("A003 OK Fetch completed.\n");
    // parse messages
    Message messages[3];
    char buffer[MAXSIZE];
    char* token;
    int message_index = 0;
    while((fgets(buffer, MAXSIZE, stdin) != NULL) && (strstr(buffer, "LOGOUT") == NULL)) {
        token = strtok(buffer, "\r\n");
        while(token != NULL) {
            parse_response(token, &(messages[message_index]));
            token = strtok(NULL, "\r\n");
        }
        message_index++;
    }
    // print messages
    printf("You have %d new messages:\n", message_index);
    for(int i=0; i<message_index; i++) {
        print_message(&(messages[i]));
    }
    // logout
    printf("Logging out...\n");
    sleep(1);
    printf("A004 OK Logout completed.\n");
    return 0;
}