//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <signal.h>

#define MSGFLAG 0600
#define SHMFLAG 0600
#define KEY 5

struct message {
    long mtype;
    int score;
};

struct shared_memory {
    int id;
    char name[50];
    int score;
};

int main() {
    // Initialize variables
    int msgid, shmid;
    key_t key;
    struct message message;
    struct shared_memory *shared_memory;
    int id, score;
    char name[50];

    // Create message queue
    key = ftok(getenv("HOME"), KEY);
    msgid = msgget(key, MSGFLAG | IPC_CREAT);
    if (msgid == -1) {
        perror("Error creating message queue");
        exit(EXIT_FAILURE);
    }

    // Create shared memory
    shmid = shmget(key, sizeof(struct shared_memory), SHMFLAG | IPC_CREAT);
    if (shmid == -1) {
        perror("Error creating shared memory");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory
    shared_memory = (struct shared_memory *)shmat(shmid, NULL, 0);
    if (shared_memory == NULL) {
        perror("Error attaching shared memory");
        exit(EXIT_FAILURE);
    }

    // Get user input
    printf("Enter your ID: ");
    scanf("%d", &id);
    printf("Enter your name: ");
    scanf("%s", name);

    // Start timer
    time_t start_time = time(NULL);

    // Generate questions
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int a = rand() % 100;
        int b = rand() % 100;
        int c = a + b;

        // Send question to message queue
        message.mtype = id;
        message.score = c;
        if (msgsnd(msgid, &message, sizeof(message), 0) == -1) {
            perror("Error sending message");
            exit(EXIT_FAILURE);
        }
    }

    // Stop timer
    time_t end_time = time(NULL);

    // Get score from shared memory
    score = shared_memory->score;

    // Print results
    printf("Your score is: %d\n", score);
    printf("Your time is: %ld seconds\n", end_time - start_time);

    // Detach shared memory
    if (shmdt(shared_memory) == -1) {
        perror("Error detaching shared memory");
        exit(EXIT_FAILURE);
    }

    // Destroy shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Error destroying shared memory");
        exit(EXIT_FAILURE);
    }

    // Destroy message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("Error destroying message queue");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}