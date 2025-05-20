//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/wait.h>
  #include <sys/ipc.h>
  #include <sys/shm.h>

  int main() {
      // Shared memory segment
      int shmid;
      key_t key = ftok(".", 'a');
      shmid = shmget(key, 1024, 0666 | IPC_CREAT);
      if (shmid < 0) {
          perror("shmget");
          exit(1);
      }

      // Shared memory
      char *shm = shmat(shmid, NULL, 0);
      if (shm == (char *)-1) {
          perror("shmat");
          exit(1);
      }

      // Child process
      pid_t pid = fork();
      if (pid == 0) {
          // Child process: write to shared memory
          char *str = "Hello, World!";
          memcpy(shm, str, strlen(str) + 1);
          printf("Child process: wrote %s to shared memory\n", str);
          exit(0);
      } else if (pid < 0) {
          perror("fork");
          exit(1);
      }

      // Parent process: wait for child to finish
      wait(NULL);

      // Parent process: read from shared memory
      printf("Parent process: read %s from shared memory\n", shm);

      // Clean up
      shmdt(shm);
      shmctl(shmid, IPC_RMID, NULL);

      return 0;
  }