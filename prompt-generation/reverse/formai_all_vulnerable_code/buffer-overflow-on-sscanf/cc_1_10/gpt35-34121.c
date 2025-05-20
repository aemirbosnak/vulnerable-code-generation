//FormAI DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define BUFFER_SIZE 1024
#define CONFIG_FILE "config.txt"

typedef struct msg_buffer{
    long msg_type;
    char msg_text[BUFFER_SIZE];
}msg_buffer;

int main(){
    key_t key;
    int msg_id;
    msg_buffer buf;
    char send_msg[BUFFER_SIZE], channel[BUFFER_SIZE], temp[BUFFER_SIZE];
    FILE* config_file;
    int is_valid = 0;

    // Reading the config file
    config_file = fopen(CONFIG_FILE, "r");
    if(config_file == NULL) {
        printf("Error: Could not open the config file.\n");
        exit(1);
    }
    while(fgets(temp, BUFFER_SIZE, config_file)){
        sscanf(temp, "%s", channel);
        if(strcmp(channel, "channel1") == 0){
            sscanf(temp, "%s%s", channel, send_msg);
            is_valid = 1;
            break;
        }
    }
    fclose(config_file);
    if(is_valid == 0) {
        printf("Error: Invalid parameters in config file.\n");
        exit(1);
    }

    // Creating a unique key
    key = ftok("progfile", 65);
    // Creating a message queue
    msg_id = msgget(key, 0666 | IPC_CREAT);
    buf.msg_type = 1;
    strcpy(buf.msg_text, send_msg);
    // Sending a message
    msgsnd(msg_id, &buf, sizeof(buf), 0);
    // Receiving a message
    msgrcv(msg_id, &buf, sizeof(buf), 1, 0);
    printf("Message received: %s", buf.msg_text);
    // Destroying the message queue
    msgctl(msg_id, IPC_RMID, NULL);

    return 0;
}