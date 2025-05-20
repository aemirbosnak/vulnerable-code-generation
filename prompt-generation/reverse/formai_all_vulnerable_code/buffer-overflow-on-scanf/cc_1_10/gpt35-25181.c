//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct {
  int data;
  char message[100];
} ShmData;

int main() {
  key_t key = ftok("./", 'A');
  int shmid = shmget(key, sizeof(ShmData), IPC_CREAT | 0666);
  ShmData* sharedData = shmat(shmid, NULL, 0);
  
  if (shmid < 0) {
    printf("Error creating shared memory segment\n");
    exit(1);
  }
  
  pid_t pid = fork();
  
  if (pid < 0) {
    printf("Error forking process\n");
    exit(1);
  }
  else if (pid == 0) {
    // Child process
    printf("Greetings, I am the child process!\n");
    printf("Please enter a number: ");
    scanf("%d", &(sharedData->data));
    printf("Please enter a surreal message: ");
    scanf("%s", sharedData->message);
    printf("Thank you, I will now terminate.\n");
  }
  else {
    // Parent process
    printf("Hello, I am the parent process!\n");
    printf("Waiting for child to enter data...\n");
    sleep(5);
    printf("The child entered: %d\n", sharedData->data);
    printf("And the surreal message is: %s\n", sharedData->message);
    printf("Thank you for your participation. Goodbye!\n");
    shmdt(sharedData);
    shmctl(shmid, IPC_RMID, NULL);
  }
  
  return 0;
}