//FormAI DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <ctype.h>

#define MSG_SIZE 255

// Create a structure for the message
struct message {
    long type;
    char text[MSG_SIZE];
};

int main() {
    // Create a queue key
    key_t key = ftok("progfile", 65);
    
    // Create a message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);

    // Check if queue was created successfully
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    // Prompt user to enter message type
    long type;
    printf("Enter message type: ");
    scanf("%ld", &type);

    // Flush input buffer
    while (getchar() != '\n');

    // Prompt user to enter message
    char message_text[MSG_SIZE];
    printf("Enter message: ");
    fgets(message_text, MSG_SIZE, stdin);
    
    // Convert message to uppercase
    for (int i=0; message_text[i]; i++){
        message_text[i] = toupper(message_text[i]);
    }

    // Create a message object
    struct message msg;
    msg.type = type;
    strncpy(msg.text, message_text, MSG_SIZE);

    // Send the message to the queue
    if (msgsnd(msgid, &msg, sizeof(msg.text), 0) == -1) {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent successfully!\n");

    return 0;
}