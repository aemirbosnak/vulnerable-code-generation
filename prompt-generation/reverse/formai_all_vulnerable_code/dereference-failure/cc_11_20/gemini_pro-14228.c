//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SEM_KEY 0x12345678
#define SEM_NUM 2
#define MSG_KEY 0x12345679
#define SHM_KEY 0x12345679
#define SHM_SIZE 1024

int main() {
  int sem_id = semget(SEM_KEY, SEM_NUM, IPC_CREAT | 0666);
  if (sem_id == -1) {
    perror("semget");
    exit(EXIT_FAILURE);
  }

  int msg_id = msgget(MSG_KEY, IPC_CREAT | 0666);
  if (msg_id == -1) {
    perror("msgget");
    exit(EXIT_FAILURE);
  }

  int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  char *shm_ptr = shmat(shm_id, NULL, 0);
  if (shm_ptr == (void *)-1) {
    perror("shmat");
    exit(EXIT_FAILURE);
  }

  struct sembuf sem_buf[2];
  sem_buf[0].sem_num = 0;
  sem_buf[0].sem_op = -1;
  sem_buf[0].sem_flg = 0;

  sem_buf[1].sem_num = 1;
  sem_buf[1].sem_op = -1;
  sem_buf[1].sem_flg = 0;

  if (semop(sem_id, sem_buf, 2) == -1) {
    perror("semop");
    exit(EXIT_FAILURE);
  }

  strcpy(shm_ptr, "Hello");

  sem_buf[0].sem_op = 1;
  sem_buf[1].sem_op = 1;

  if (semop(sem_id, sem_buf, 2) == -1) {
    perror("semop");
    exit(EXIT_FAILURE);
  }

  msgsnd(msg_id, &shm_ptr, sizeof(shm_ptr), 0);

  sem_buf[0].sem_op = -1;
  sem_buf[1].sem_op = -1;

  if (semop(sem_id, sem_buf, 2) == -1) {
    perror("semop");
    exit(EXIT_FAILURE);
  }

  if (shmdt(shm_ptr) == -1) {
    perror("shmdt");
    exit(EXIT_FAILURE);
  }

  if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    exit(EXIT_FAILURE);
  }

  if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
    perror("msgctl");
    exit(EXIT_FAILURE);
  }

  if (semctl(sem_id, 0, IPC_RMID) == -1) {
    perror("semctl");
    exit(EXIT_FAILURE);
  }

  return 0;
}