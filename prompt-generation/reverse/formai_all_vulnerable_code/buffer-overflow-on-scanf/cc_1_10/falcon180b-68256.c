//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

//structure for passing data between threads
typedef struct{
    int num;
    char name[20];
}data;

//function prototypes
void *runner(void *param);
void create_threads(int num_threads);
void join_threads(int num_threads);
void init_semaphores(int num_threads);
void destroy_semaphores(int num_threads);

//global variables
int num_threads;
pthread_t thread_id[100];
sem_t mutex[100];
int thread_count;

int main(){
    printf("Enter the number of threads: ");
    scanf("%d",&num_threads);

    //initialize semaphores
    init_semaphores(num_threads);

    //create threads
    create_threads(num_threads);

    //wait for threads to finish
    join_threads(num_threads);

    printf("All threads have finished executing.\n");
    return 0;
}

//function to create threads
void create_threads(int num_threads){
    int i;
    for(i=0;i<num_threads;i++){
        pthread_create(&thread_id[i],NULL,runner,(void *)i);
    }
}

//function to join threads
void join_threads(int num_threads){
    int i;
    for(i=0;i<num_threads;i++){
        pthread_join(thread_id[i],NULL);
    }
}

//function to initialize semaphores
void init_semaphores(int num_threads){
    int i;
    for(i=0;i<num_threads;i++){
        sem_init(&mutex[i],0,1);
    }
}

//function to destroy semaphores
void destroy_semaphores(int num_threads){
    int i;
    for(i=0;i<num_threads;i++){
        sem_destroy(&mutex[i]);
    }
}

//function to execute in threads
void *runner(void *param){
    int id = (int)param;
    char name[20];
    sprintf(name,"Thread %d",id);
    printf("Thread %s is executing.\n",name);

    //acquire lock
    sem_wait(&mutex[id]);

    //critical section
    printf("Thread %s is in critical section.\n",name);
    sleep(1);

    //release lock
    sem_post(&mutex[id]);

    pthread_exit(0);
}