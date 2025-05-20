//FormAI DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>

// This program demonstrates interprocess communication in a real-life style
// Two processes communicate with shared memory to share a message
// Process A writes the message and Process B reads and displays it

#define SHM_KEY 0x12345
#define MAX_MSG_SIZE 100

int main()
{
   // Create shared memory segment
   int shm_id = shmget(SHM_KEY, MAX_MSG_SIZE, IPC_CREAT | 0666);
   if (shm_id < 0) {
      perror("shmget failed");
      exit(EXIT_FAILURE);
   }

   // Attach shared memory segment
   char* msg = (char*) shmat(shm_id, NULL, 0);
   if (msg == (void*) (-1)) {
      perror("shmat failed");
      exit(EXIT_FAILURE);
   }

   pid_t pid = fork();

   if (pid < 0) { // Error
      perror("fork failed");
      exit(EXIT_FAILURE);
   }
   else if (pid == 0) { // Child process B

      while(1) {
         if (strcmp(msg, "")) {
            printf("Received message: %s\n", msg);
            strcpy(msg, "");
         }

         sleep(1);
      }

      exit(EXIT_SUCCESS);
   }
   else { // Parent process A

      printf("Enter message: ");

      while (1) {
         fgets(msg, MAX_MSG_SIZE, stdin);
         if (strlen(msg) > 0 && msg[strlen(msg)-1] == '\n') {
            msg[strlen(msg)-1] = '\0';
         }

         if (strcmp(msg, "exit") == 0) {
            kill(pid, SIGTERM);
            exit(EXIT_SUCCESS);
         }

         sleep(1);
      }
   }

   return 0;
}