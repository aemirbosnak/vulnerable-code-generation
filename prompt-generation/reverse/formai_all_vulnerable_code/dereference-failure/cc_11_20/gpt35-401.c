//FormAI DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SEM_KEY 5678
#define SHM_KEY 3456

union semun { int val; struct semid_ds *buf; ushort *array; };

int main() {

   int sem_id, shm_id;
   pid_t pid;
   char *shm_addr;
   union semun sem_un;
   struct sembuf sem_buf;
   int status;

   /* create a semaphore */
   sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
   if(sem_id == -1) {
      perror("semget");
      exit(1);
   }

   /* initialize the semaphore */
   sem_un.val = 0;
   if(semctl(sem_id, 0, SETVAL, sem_un) == -1) {
      perror("semctl");
      exit(1);
   }

   /* create a shared memory segment */
   shm_id = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666);
   if(shm_id == -1) {
      perror("shmget");
      exit(1);
   }

   /* attach the shared memory segment */
   shm_addr = (char *) shmat(shm_id, NULL, 0);
   if(shm_addr == (char *) -1) {
      perror("shmat");
      exit(1);
   }

   /* fork a child process */
   pid = fork();
   if(pid == -1) {
      perror("fork");
      exit(1);
   }

   if(pid == 0) { /* child process */

      /* decrement the semaphore */
      sem_buf.sem_num = 0;
      sem_buf.sem_op = -1;
      sem_buf.sem_flg = 0;
      if(semop(sem_id, &sem_buf, 1) == -1) {
         perror("semop");
         exit(1);
      }

      /* read the value from the shared memory segment */
      printf("Child read: %d\n", *shm_addr);

      /* exit */
      exit(0);

   } else { /* parent process */

      /* write a value to the shared memory segment */
      *shm_addr = 123;

      /* increment the semaphore */
      sem_buf.sem_num = 0;
      sem_buf.sem_op = 1;
      sem_buf.sem_flg = 0;
      if(semop(sem_id, &sem_buf, 1) == -1) {
         perror("semop");
         exit(1);
      }

      /* wait for the child to exit */
      wait(&status);

   }

   /* detach the shared memory segment and delete it */
   if(shmdt(shm_addr) == -1) {
      perror("shmdt");
      exit(1);
   }
   if(shmctl(shm_id, IPC_RMID, 0) == -1) {
      perror("shmctl");
      exit(1);
   }

   /* delete the semaphore */
   if(semctl(sem_id, 0, IPC_RMID, sem_un) == -1) {
      perror("semctl");
      exit(1);
   }

   /* exit */
   exit(0);

}