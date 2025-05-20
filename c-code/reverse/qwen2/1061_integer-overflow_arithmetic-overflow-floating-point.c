#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 27

void draw_shape(int temp) {
    if (temp >= 40 || temp <= -40) printf("####\n");
    else if (temp >= 30 || temp <= -30) printf("###\n");
    else if (temp >= 20 || temp <= -20) printf("##\n");
    else if (temp >= 10 || temp <= -10) printf("#\n");
    else printf("\n");
}

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    char *str = (char*) shmat(shmid, NULL, 0);

    srand(time(0));
    while (1) {
        int temp = rand() % 101 - 50;
        sprintf(str, "Temp: %d°C\nShape:\n", temp);
        draw_shape(temp);
        sleep(1);
    }

    shmdt(str);
    return 0;
}
