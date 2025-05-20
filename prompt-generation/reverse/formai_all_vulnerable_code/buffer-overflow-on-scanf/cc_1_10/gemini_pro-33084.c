//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE sizeof(int)

int main() {
  int shmid;  // The shared memory identifier
  int *shm;   // The shared memory pointer
  int *num;   // The number to be sent or received

  // Create the shared memory segment
  shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the current process
  shm = (int *)shmat(shmid, NULL, 0);
  if (shm == (int *)-1) {
    perror("shmat");
    exit(1);
  }

  printf("Number to be sent: ");
  scanf("%d", num);

  // The sender process
  if (fork() == 0) {
    *shm = *num;  // Place the number in shared memory
    printf("Sender: Number sent!\n");

    // Wait for the receiver to finish
    while (*shm != 0)
      ;
  } 
  // The receiver process
  else {
    // Wait for the sender to place the number in shared memory
    while (*shm == 0)
      ;

    printf("Receiver: Number received: %d\n", *shm);
    *shm = 0;  // Acknowledge receipt and release the shared memory
  }

  // Detach the shared memory segment from the current process
  shmdt(shm);

  // Remove the shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}