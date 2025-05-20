//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_MSG_SIZE 100
#define MAX_QUEUE_SIZE 10

typedef struct {
    char msg[MAX_MSG_SIZE];
    int sender_pid;
} msg_t;

typedef struct {
    msg_t messages[MAX_QUEUE_SIZE];
    int front, rear, count;
} queue_t;

int create_queue(char* path, int mode) {
    int fd = open(path, mode);
    if (fd == -1) {
        printf("Error: Failed to create queue %s\n", path);
        return -1;
    }
    return fd;
}

int send_message(int qid, char* msg) {
    msg_t message = {.msg = msg,.sender_pid = getpid() };
    int ret = write(qid, &message, sizeof(message));
    if (ret!= sizeof(message)) {
        printf("Error: Failed to send message\n");
        return -1;
    }
    return 0;
}

int receive_message(int qid, char* msg) {
    msg_t message;
    int ret = read(qid, &message, sizeof(message));
    if (ret!= sizeof(message)) {
        printf("Error: Failed to receive message\n");
        return -1;
    }
    strcpy(msg, message.msg);
    return 0;
}

int main() {
    int qid = create_queue("my_queue", O_CREAT | O_RDWR);
    if (qid == -1) {
        return -1;
    }

    char msg[MAX_MSG_SIZE];
    while (1) {
        printf("Enter a message to send: ");
        scanf("%s", msg);
        send_message(qid, msg);
    }

    return 0;
}