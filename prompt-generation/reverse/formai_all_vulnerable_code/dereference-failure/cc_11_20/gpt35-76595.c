//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234 // Shared Memory Key
#define SHM_SIZE 1024 // Shared Memory Size
#define MSG_SIZE 256 // Message Size

// Structure for the Message passing
typedef struct {
   char msg[MSG_SIZE];
   int msg_len;
   int msg_type;
} message;

int main() {
    // Declaring the Variables
    int shmid, ret;
    char *shm_ptr;
    message *msg_ptr;
    key_t key = SHM_KEY;

    // Creating Shared Memory Segment with Key and Size
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if(shmid < 0) {
        perror("shmget error");
        exit(1);
    }

    // Attaching Shared Memory Segment to Parent Process
    shm_ptr = shmat(shmid, NULL, 0);
    if(shm_ptr == (char *) -1) {
        perror("shmat error");
        exit(1);
    }

    // Initializing Shared Memory
    memset(shm_ptr, 0, SHM_SIZE);

    // Casting Shared Memory Pointer to Message Pointer
    msg_ptr = (message *) shm_ptr;

    // Reading Message from Shared Memory
    printf("Enter Message: ");
    fgets(msg_ptr->msg, MSG_SIZE, stdin);
    msg_ptr->msg_len = strlen(msg_ptr->msg);
    msg_ptr->msg_type = 1; // Type of Message

    // Detaching Shared Memory Segment from Parent Process
    ret = shmdt(shm_ptr);
    if(ret < 0) {
        perror("shmdt error");
        exit(1);
    }

    // Forking Child Process
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork error");
        exit(1);
    } else if(pid == 0) {
        // Attaching Shared Memory Segment to Child Process
        shm_ptr = shmat(shmid, NULL, 0);
        if(shm_ptr == (char *) -1) {
            perror("shmat error");
            exit(1);
        }

        // Casting Shared Memory Pointer to Message Pointer
        msg_ptr = (message *) shm_ptr;

        // Reading Message from Shared Memory
        printf("Message from Parent Process: [%s]\n", msg_ptr->msg);

        // Detaching Shared Memory Segment from Child Process
        ret = shmdt(shm_ptr);
        if(ret < 0) {
            perror("shmdt error");
            exit(1);
        }

        // Removing Shared Memory Segment
        ret = shmctl(shmid, IPC_RMID, NULL);
        if(ret < 0) {
            perror("shmctl error");
            exit(1);
        }

        // Exiting Child Process
        exit(0);
    } else {
        // Waiting for Child Process to complete
        wait(NULL);

        // Detaching Shared Memory Segment from Parent Process
        shm_ptr = shmat(shmid, NULL, 0);
        if(shm_ptr == (char *) -1) {
            perror("shmat error");
            exit(1);
        }

        // Casting Shared Memory Pointer to Message Pointer
        msg_ptr = (message *) shm_ptr;

        // Printing the Message
        printf("Message Sent Successfully: [%s]\n", msg_ptr->msg);

        // Detaching Shared Memory Segment from Parent Process
        ret = shmdt(shm_ptr);
        if(ret < 0) {
            perror("shmdt error");
            exit(1);
        }
    }

    return 0;
}