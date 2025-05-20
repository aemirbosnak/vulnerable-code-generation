//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <math.h>

#define MAX_TEXT 128

// Message structure
struct message {
    long msg_type;
    char text[MAX_TEXT];
};

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

// Process A: Sends Fibonacci input to Process B
void processA(int msgid) {
    struct message msg;
    for (int i = 0; i <= 10; i++) {
        msg.msg_type = 1; // Arbitrary message type
        sprintf(msg.text, "Fibonacci(%d)", i);
        msgsnd(msgid, &msg, sizeof(msg.text), 0);
        printf("Process A sent: %s\n", msg.text);
        sleep(1); // Sleep to simulate processing time
    }
    msg.msg_type = 1;
    strcpy(msg.text, "END");
    msgsnd(msgid, &msg, sizeof(msg.text), 0);
}

// Process B: Receives input and calculates the Fibonacci number
void processB(int msgid) {
    struct message msg;
    while (1) {
        msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);
        if (strncmp(msg.text, "END", 3) == 0) {
            printf("Process B received: %s - Ending process.\n", msg.text);
            break;
        }
        
        int n;
        sscanf(msg.text, "Fibonacci(%d)", &n);
        int result = fibonacci(n);
        printf("Process B calculated: Fibonacci(%d) = %d\n", n, result);
    }
}

int main() {
    key_t key = ftok("fibonacci", 65); // Generate unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create message queue
    
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    // Fork to create processes
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process B
        processB(msgid);
    } else {
        // Parent process A
        processA(msgid);
        wait(NULL); // Wait for child process to finish
        msgctl(msgid, IPC_RMID, NULL); // Destroy message queue
        printf("Process A finished. Message queue destroyed.\n");
    }

    return 0;
}