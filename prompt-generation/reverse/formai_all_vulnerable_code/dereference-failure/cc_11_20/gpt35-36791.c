//FormAI DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
/* This program demonstrates an interprocess communication between two processes using shared memory */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 100 // Size of shared memory segment
#define KEY 123 // Key for shared memory segment

int main() {
   int shmid;
   char *shm, *s;

   // Create shared memory segment
   if ((shmid = shmget(KEY, SHMSIZE, IPC_CREAT | 0666)) < 0) {
      perror("shmget");
      exit(1);
   }

   // Attach shared memory segment to this process
   if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
      perror("shmat");
      exit(1);
   }

   // Write data to shared memory segment
   s = shm;
   for (char c = 'a'; c <= 'z'; ++c) {
      *s++ = c;
   }
   *s = '\0';

   // Fork a child process
   pid_t pid;
   pid = fork();

   if (pid == -1) {
      perror("fork");
      exit(1);
   }
   
   if (pid == 0) { // Child process
      char *shm_child, *s_child;
      int shmid_child;
      
      // Get shared memory segment created by parent
      if ((shmid_child = shmget(KEY, SHMSIZE, 0666)) < 0) {
         perror("shmget");
         exit(1);
      }
      
      // Attach shared memory segment to the child process
      if ((shm_child = shmat(shmid_child, NULL, 0)) == (char *) -1) {
         perror("shmat");
         exit(1);
      }
      
      // Read data from shared memory segment
      s_child = shm_child;
      while (*s_child != '\0') {
         putchar(*s_child++);
      }
      putchar('\n');
      
      // Detach shared memory segment from child process
      if (shmdt(shm_child) == -1) {
         perror("shmdt");
         exit(1);
      }
      
      // Exit child process
      exit(0);
   }
   else { // Parent process
      // Wait for child process to finish
      wait(NULL);
      
      // Detach shared memory segment from parent process
      if (shmdt(shm) == -1) {
         perror("shmdt");
         exit(1);
      }
      
      // Deallocate shared memory segment
      if (shmctl(shmid, IPC_RMID, NULL) == -1) {
         perror("shmctl");
         exit(1);
      }
      
      // Exit parent process
      exit(0);
   }
}