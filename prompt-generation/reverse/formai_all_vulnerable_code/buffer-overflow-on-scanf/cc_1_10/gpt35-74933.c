//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
/* 
 * Code written by [Your Name]
 * Description: This program demonstrates interprocess communication
 * using Shared Memory technique by allowing two processes to communicate
 * with each other using a shared memory buffer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>

#define SHM_SIZE 1024  /* Size of the Shared Memory Segment */

// Signal handler for interrupt signals
void signal_handler(int signum) {
  printf("Interrupt Signal Received. Cleaning up and exiting...\n");
  exit(0);
}

int main() {

  int shmid;
  char *shm; // Pointer to the shared memory buffer
  key_t key = 5678; // Unique key to identify the Shared Memory Segment
  int num1, num2;

  // Attach signal handler to interrupt signals
  signal(SIGINT, signal_handler);

  // Create a Shared Memory Segment
  if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  // Attach the Shared Memory Segment to the Process's Memory Space
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  while (1) {

    printf("Enter First Number: ");
    scanf("%d", &num1);

    printf("Enter Second Number: ");
    scanf("%d", &num2);

    // Write the input values to the Shared Memory Buffer
    sprintf(shm, "%d,%d", num1, num2);

    // Notify the other process that data has been written to the Shared Memory
    printf("Data written to the Shared Memory Segment.\n");

    // Wait for the other process to read the data
    while (*shm != '*')
      sleep(1);

    // Read the calculated result from the Shared Memory Buffer
    printf("Result: %s\n\n", shm+1);

    // Reset the memory buffer
    memset(shm, 0, SHM_SIZE);

  }

  // Detach the Shared Memory Segment from the Process's Memory Space
  shmdt(shm);

  // Remove the Shared Memory Segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;

}

/* 
 * The above code creates a Shared Memory Segment using a unique key,
 * and attaches it to the Process's Memory space. Then it prompts the user
 * to enter two integer numbers, which are written to the Shared Memory
 * buffer. The program then waits for the other process to read the data,
 * and once it is read, it reads the calculated result from the Shared Memory.
 * It then resets the memory buffer and repeats the process.
 */