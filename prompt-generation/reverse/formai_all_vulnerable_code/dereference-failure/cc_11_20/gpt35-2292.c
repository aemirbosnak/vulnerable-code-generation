//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>

#define SEM_KEY 0x123456
#define SHM_KEY 0x2345678
#define SHM_SIZE 1024

typedef struct{
  char message[SHM_SIZE];
  int status;
}shared_memory;

struct sembuf semaphore;

int main(){

  int sem_id,shm_id,error_val;
  shared_memory *shmem;
  key_t semkey,shmkey;
  
  /* Get key for semaphore */
  if((semkey=ftok("semaphore.c",'l'))==-1){
      perror("ftok");
      exit(1);
  }
  
  /* Get key for shared memory */
  if((shmkey=ftok("shared_memory.c",'r'))==-1){
      perror("ftok");
      exit(1);
  }

  /* Create semaphore */
  if((sem_id=semget(SEM_KEY,1,IPC_CREAT|0666))==-1){
      perror("semget");
      exit(1);
  }

  /* Create shared memory */
  if((shm_id=shmget(SHM_KEY,SHM_SIZE,IPC_CREAT|0666))==-1){
      perror("shmget");
      exit(1);
  }

  /* Map shared memory */
  if((shmem=(shared_memory*)shmat(shm_id,(void*)0,0))==(shared_memory*)-1){
      perror("shmat");
      exit(1);
  }

  /* Set initial values */
  strcpy(shmem->message,"Hello, this is the parent process!");
  shmem->status=0;

  /* Initialize semaphore */
  semaphore.sem_num=0;
  semaphore.sem_flg=0;

  /* Parent process waits for child to signal */
  semaphore.sem_op=-1;
  error_val=semop(sem_id,&semaphore,1);
  if(error_val==-1){
      perror("semop");
      exit(1);
  }

  /* Print message from child process */
  printf("Parent received message: %s\n",shmem->message);

  /* Change message in shared memory */
  strcpy(shmem->message,"Hi child, this is the parent!");

  /* Parent process signals child */
  semaphore.sem_op=1;
  error_val=semop(sem_id,&semaphore,1);
  if(error_val==-1){
      perror("semop");
      exit(1);
  }

  /* Detach from shared memory */
  if(shmdt(shmem)==-1){
      perror("shmdt");
      exit(1);
  }

  /* Remove semaphore */
  if(semctl(sem_id,0,IPC_RMID,0)==-1){
      perror("semctl");
      exit(1);
  }

  /* Remove shared memory */
  if(shmctl(shm_id,IPC_RMID,0)==-1){
      perror("shmctl");
      exit(1);
  }
  
  return 0;
}