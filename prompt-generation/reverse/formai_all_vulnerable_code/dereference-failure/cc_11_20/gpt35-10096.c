//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMSZ 27  // size of shared memory segment

int main() {
   char c;
   int shmid;
   key_t key;
   char *shm, *s;
   pid_t pid;

   // generate a unique shared memory key
   key = ftok(".", 'a');

   // create a shared memory segment
   if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
      perror("shmget");
      exit(1);
   }

   // attach the shared memory segment to the address space of the calling process
   if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
      perror("shmat");
      exit(1);
   }

   // write a message to the shared memory segment
   s = shm;
   for (c = 'a'; c <= 'z'; c++)
      *s++ = c;
   *s = '\0';

   // fork a child process
   if ((pid = fork()) < 0) {
      perror("fork");
      exit(1);
   } else if (pid == 0) { /* child process */
      printf("Child process started...\n");

      // read the message from the shared memory segment
      s = shm;
      for (int i = 0; i < SHMSZ; i++)
         putchar(*s++);
      putchar('\n');

      // detach the shared memory segment from the address space of the calling process
      if (shmdt(shm) == -1) {
         perror("shmdt");
         exit(1);
      }

      printf("Child process completed.\n");
      exit(0);
   } else { /* parent process */
      printf("Parent process started...\n");

      // wait for the child process to terminate
      if (waitpid(pid, NULL, 0) == -1) {
         perror("waitpid");
         exit(1);
      }

      // change the contents of the shared memory segment
      s = shm;
      for (c = 'Z'; c >= 'A'; c--)
         *s++ = c;
      *s = '\0';

      printf("Parent process completed.\n");
   }

   // detach the shared memory segment from the address space of the calling process
   if (shmdt(shm) == -1) {
      perror("shmdt");
      exit(1);
   }

   // remove the shared memory segment
   if (shmctl(shmid, IPC_RMID, 0) == -1) {
      perror("shmctl");
      exit(1);
   }

   return 0;
}