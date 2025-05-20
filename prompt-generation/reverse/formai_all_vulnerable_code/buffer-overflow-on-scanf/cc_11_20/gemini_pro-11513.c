//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define the message structure
struct message {
    long mtype;
    char mtext[100];
};

// Define the message types
#define TEXT_MSG 1
#define MORSE_MSG 2

// Define the shared memory key
#define KEY 12345

int main() {
    // Create the message queue
    int msqid = msgget(KEY, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        return 1;
    }

    // Create the shared memory segment
    int shmid = shmget(KEY, 100, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory segment to the address space of the process
    char *shmptr = (char *) shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        perror("shmat");
        return 1;
    }

    // Fork the process
    int pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    // Parent process
    if (pid > 0) {
        // Send the text message to the message queue
        struct message msg;
        msg.mtype = TEXT_MSG;
        printf("Enter a text message: ");
        scanf("%s", msg.mtext);
        msgsnd(msqid, &msg, sizeof(msg.mtext), 0);

        // Wait for the child process to finish
        wait(NULL);

        // Detach the shared memory segment from the address space of the process
        shmdt(shmptr);

        // Print the Morse code message
        printf("Morse code message: %s\n", shmptr);

        // Remove the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);

        // Remove the message queue
        msgctl(msqid, IPC_RMID, NULL);
    }

    // Child process
    else {
        // Receive the text message from the message queue
        struct message msg;
        msgrcv(msqid, &msg, sizeof(msg.mtext), TEXT_MSG, 0);

        // Convert the text message to Morse code
        char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-", "--..--"};
        int i, j, len = strlen(msg.mtext);
        for (i = 0; i < len; i++) {
            for (j = 0; j < 26; j++) {
                if (msg.mtext[i] == 'a' + j || msg.mtext[i] == 'A' + j) {
                    strcat(shmptr, morse_code[j]);
                    break;
                }
            }
            if (msg.mtext[i] == ' ') {
                strcat(shmptr, " ");
            }
        }

        // Detach the shared memory segment from the address space of the process
        shmdt(shmptr);

        // Exit the child process
        exit(0);
    }

    return 0;
}