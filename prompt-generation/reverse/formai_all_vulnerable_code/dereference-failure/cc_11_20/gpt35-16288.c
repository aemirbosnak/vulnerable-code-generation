//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
/* The following program demonstrates a simple interprocess communication between a parent process and its child process.
The communication method used is through shared memory, wherein the parent process writes to a shared memory segment and the child process reads from it.
The message sent by the parent process is encrypted using the XOR cipher, and the key is calculated using the Shannon entropy formula. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // size of shared memory in bytes

int main()
{
    pid_t pid;
    int shmid;
    char *shmaddr;
    key_t key;
    int i;

    // generate a unique key for shared memory
    key = ftok("ipcdemo.c", 1);

    // create a shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to the process's address space
    shmaddr = (char *) shmat(shmid, NULL, 0);

    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    pid = fork();  // fork a child process

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {  // child process
        printf("Child process is waiting for message from parent...\n");
        while (1) {
            if (shmaddr[0] != '\0') {
                printf("Received message: ");
                for (i = 0; shmaddr[i] != '\0'; i++) {
                    printf("%c", shmaddr[i] ^ 13);  // decrypt using key = Shannon entropy of message
                    usleep(50);  // add delay to simulate processing
                }
                printf("\n");
                shmaddr[0] = '\0';  // clear shared memory
            }
            usleep(1000);  // add delay to prevent busy waiting
        }
    } else {  // parent process
        printf("Parent process is sending message to child...\n");
        char *message = "This is a secret message!";  // message to be sent
        int key = 0;  // key to be used for encryption
        float entropy = 0, prob;  // variables for Shannon entropy calculation
        int freq[256] = { 0 };  // array to store frequency distribution of bytes in message
        for (i = 0; message[i] != '\0'; i++) {
            freq[(unsigned char) message[i]]++;  // count frequency of each byte
        }
        for (i = 0; i < 256; i++) {
            prob = (float) freq[i] / (float) i;  // calculate probability of each byte
            if (prob > 0) {
                entropy += prob * log2(prob);  // calculate Shannon entropy of message
            }
        }
        key = (int) entropy;  // round entropy to nearest integer to get key
        for (i = 0; message[i] != '\0'; i++) {
            shmaddr[i] = message[i] ^ key;  // encrypt message using XOR cipher and key=Shannon entropy
            usleep(50);  // add delay to simulate processing
        }
        printf("Message sent. Key used: %d\n", key);
        sleep(2);  // wait for child to read message
        shmdt(shmaddr);  // detach shared memory
        shmctl(shmid, IPC_RMID, NULL);  // delete shared memory segment
    }

    return 0;
}