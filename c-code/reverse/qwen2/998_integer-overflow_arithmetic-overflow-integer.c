#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_LEN 256

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_LEN];
};

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg_buffer buf;

    while (1) {
        sleep(1);
        buf.msg_type = 1;
        sprintf(buf.msg_text, "Traffic Light: Red");
        msgsnd(msgid, &buf, sizeof(buf), 0);
        sleep(rand() % 3 + 2);

        buf.msg_type = 1;
        sprintf(buf.msg_text, "Traffic Light: Green");
        msgsnd(msgid, &buf, sizeof(buf), 0);
        sleep(rand() % 4 + 3);

        buf.msg_type = 1;
        sprintf(buf.msg_text, "Traffic Light: Yellow");
        msgsnd(msgid, &buf, sizeof(buf), 0);
        sleep(rand() % 2 + 1);
    }

    return 0;
}
