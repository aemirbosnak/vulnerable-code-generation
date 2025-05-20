//FormAI DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <signal.h>

#define MSG_MAX_LEN 1024
#define MSG_SENDER_ONE 1
#define MSG_SENDER_TWO 2
#define MSG_RECEIVER_ONE 3
#define MSG_RECEIVER_TWO 4

#define ERROR(fmt, ...) \
  do { \
      fprintf(stderr, "[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
      exit(1); \
  } while (0)

typedef struct {
    long msg_type;
    char msg_buff[MSG_MAX_LEN];
} Message;

int main() {
    int msg_id;
    pid_t sender1_pid, sender2_pid;
    pid_t receiver1_pid, receiver2_pid;

    if ((msg_id = msgget(IPC_PRIVATE, 0644)) == -1)
        ERROR("msgget failed with error: %d", errno);

    if ((sender1_pid = fork()) == -1)
        ERROR("fork for sender1 failed with error: %d", errno);
    else if (sender1_pid == 0) {
        // sender1
        Message msg1;
        msg1.msg_type = MSG_SENDER_ONE;
        strcpy(msg1.msg_buff, "This is sender1!");
        if (msgsnd(msg_id, &msg1, sizeof(msg1), 0) == -1)
            ERROR("msgsnd failed with error: %d", errno);
        exit(0);
    }

    if ((sender2_pid = fork()) == -1)
        ERROR("fork for sender2 failed with error: %d", errno);
    else if (sender2_pid == 0) {
        // sender2
        Message msg2;
        msg2.msg_type = MSG_SENDER_TWO;
        strcpy(msg2.msg_buff, "This is sender2!");
        if (msgsnd(msg_id, &msg2, sizeof(msg2), 0) == -1)
            ERROR("msgsnd failed with error: %d", errno);
        exit(0);
    }

    if ((receiver1_pid = fork()) == -1)
        ERROR("fork for receiver1 failed with error: %d", errno);
    else if (receiver1_pid == 0) {
        // receiver1
        Message msg_rcv1;
        if (msgrcv(msg_id, &msg_rcv1, sizeof(msg_rcv1), MSG_RECEIVER_ONE, 0) == -1)
            ERROR("msgrcv failed with error: %d", errno);
        printf("%s\n", msg_rcv1.msg_buff);
        exit(0);
    }

    if ((receiver2_pid = fork()) == -1)
        ERROR("fork for receiver2 failed with error: %d", errno);
    else if (receiver2_pid == 0) {
        // receiver2
        Message msg_rcv2;
        if (msgrcv(msg_id, &msg_rcv2, sizeof(msg_rcv2), MSG_RECEIVER_TWO, 0) == -1)
            ERROR("msgrcv failed with error: %d", errno);
        printf("%s\n", msg_rcv2.msg_buff);
        exit(0);
    }

    // Wait for child processes to complete
    waitpid(sender1_pid, NULL, 0);
    waitpid(sender2_pid, NULL, 0);
    waitpid(receiver1_pid, NULL, 0);
    waitpid(receiver2_pid, NULL, 0);

    // Destroy message queue
    if (msgctl(msg_id, IPC_RMID, NULL) != 0)
        ERROR("msgctrl failed with error: %d", errno);

    return 0;
}