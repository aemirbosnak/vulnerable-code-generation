//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
/* Interprocess communication example program */
/* Written by <Your Name> in a Donald Knuth Style */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(int argc, char *argv[])
{
    /* Create and initialize shared memory segment */
    int shmid;
    key_t key;
    char *shm,*s;
    int size = 27;
    key = 5678;

    if ((shmid = shmget(key, size, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    s = shm;
    *s++ = 'H';
    *s++ = 'e';
    *s++ = 'l';
    *s++ = 'l';
    *s++ = 'o';
    *s++ = ',';
    *s++ = ' ';
    *s++ = 'W';
    *s++ = 'o';
    *s++ = 'r';
    *s++ = 'l';
    *s++ = 'd';
    *s++ = '!';
    *s++ = '\n';
    *s = '\0';

    /* Fork the process into parent and child */
    pid_t pid;
    pid = fork();

    if(pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){
        /* Child process reads from shared memory */
        char *cshmptr;
        cshmptr = shm;
        while(*cshmptr == ' ');
        for(s = cshmptr; *s != '\0'; s++)
            putchar(*s);
        putchar('\n');

        /* Detach from shared memory and remove it */
        if (shmdt(cshmptr) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else{
        /* Parent process waits for child to finish */
        wait(NULL);

        /* Detach from shared memory and remove it */
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }

        /* Exit program */
        exit(EXIT_SUCCESS);
    }
}